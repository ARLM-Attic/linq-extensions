// EeekSoft.CLinq.h

#pragma once

#include "EeekSoft.CLinq.Utils.h"

using namespace System;
using namespace System::Expressions;
using namespace System::Reflection;
using namespace System::Collections::Generic;

namespace EeekSoft {
	namespace CLinq {
		/// <summary>
		/// Abstract untyped expression
		/// </summary>
		public ref class GenericExpression abstract
		{
		public:
			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() abstract;
		};

		/// <summary>
		/// Abstract typed expression
		/// </summary>
		generic<typename T> public ref class Expression abstract : GenericExpression 
		{
		protected:
			/// <summary> Invoke method by name. Returns expression representing method call. </summary>
			generic<typename R> Expression<R>^ ExpressionInvoke(String^ name, ... cli::array<GenericExpression^>^ args);
			/// <summary> Invoke static method by name. Returns expression representing method call. </summary>
			generic<typename R> static Expression<R>^ ExpressionInvokeStatic(String^ name, ... cli::array<GenericExpression^>^ args);
			/// <summary> Read property by name. Returns expression representing property reading. </summary>
			generic<typename R> Expression<R>^ ExpressionProp(String^ name);
			/// <summary> Read property by name. Returns expression representing property reading. </summary>
			generic<typename R> static Expression<R>^ ExpressionPropStatic(String^ name);

		public:
			operator Expression<T>^() { return this; }
		};

		/// <summary>
		/// Represents conversion from untyped to typed expression
		/// </summary>
		generic<typename T> public ref class TypedExpression : Expression<T>
		{
		protected:
			GenericExpression^ _inner;
		public:
			TypedExpression() { }

			/// <summary>
			/// Wraps specified generic expression. 
			/// </summary>
			TypedExpression(GenericExpression^ expr)
			{
				_inner = expr;
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				return _inner->ToLinq();
			}
		};

		/// <summary>
		/// Represents conversion from expression of another type to specified type
		/// </summary>
		generic<typename T> public ref class ConvertExpression : Expression<T>
		{
			GenericExpression^ _expr;
		public:
			ConvertExpression(GenericExpression^ expr)
			{
				_expr = expr;
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				return System::Expressions::Expression::Convert(_expr->ToLinq(), T::typeid);
			}
		};

		/// <summary>
		/// Represents creating of array that will be passed as an params parameter
		/// </summary>
		generic<typename T> public ref class ParamsExpression : GenericExpression
		{
		private:
			System::Expressions::Expression^ _value;

		public:
			ParamsExpression(... cli::array<Expression<T>^>^ arr)
			{
				List<System::Expressions::Expression^>^ ret = gcnew List<System::Expressions::Expression^>();
				for(int i=0; i<arr->Length; i++) ret->Add(arr[i]->ToLinq());
				_value = System::Expressions::Expression::NewArrayInit(T::typeid, ret);
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				return _value;
			}
		};


		/// <summary>
		/// Represent reading of a property with unknown return type
		/// </summary>
		public ref class PropertyExpressionUntyped : GenericExpression
		{
		private:
			PropertyInfo^ _prop;
			GenericExpression^ _instance;
			
		public:
			PropertyExpressionUntyped(PropertyInfo^ prop, GenericExpression^ instance)
			{
				_prop = prop;
				_instance = instance;
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				System::Expressions::Expression^ self = nullptr;
				if (_instance) self = _instance->ToLinq();
				return System::Expressions::Expression::Property(self, _prop);
			}
		};

		/// <summary>
		/// Represent reading of a property with known return type
		/// </summary>
		generic<typename T> public ref class PropertyExpression : TypedExpression<T>
		{
		public:
			PropertyExpression(PropertyInfo^ prop, GenericExpression^ instance)
			{
				_inner = gcnew PropertyExpressionUntyped(prop, instance);
			}
		};


		/// <summary>
		/// Represents call to a method or constructor with unknown return type
		/// </summary>
		public ref class MethodBaseInvokeExpressionUntyped : GenericExpression
		{
		protected:
			MethodBase^ _method;
			GenericExpression^ _instance;
			array<GenericExpression^>^ _parameters;

		public:
			MethodBaseInvokeExpressionUntyped(MethodBase^ method, GenericExpression^ instance, ... array<GenericExpression^>^ parameters)
			{
				_method = method;
				_instance = instance;
				_parameters = parameters;
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				List<System::Expressions::Expression^>^ args = gcnew List<System::Expressions::Expression^>();
				if (_parameters != nullptr)
				{
					for each(GenericExpression^ e in _parameters) args->Add(e->ToLinq());
				}
				
				System::Expressions::Expression^ self = nullptr;
				if (_instance) self = _instance->ToLinq();

				if (_method->IsConstructor)
				{
					// Handle bindings (PropMap attribute)
					ConstructorInfo^ ctor = dynamic_cast<ConstructorInfo^>(_method);
					cli::array<ParameterInfo^>^ params = ctor->GetParameters();
					List<System::Expressions::Binding^>^ bindings = gcnew List<System::Expressions::Binding^>(params->Length);
					bool hasBindings = true;

					for(int i=0; i<params->Length; i++)
					{
						cli::array<Object^>^ attrs = params[i]->GetCustomAttributes(PropMapAttribute::typeid, false);
						if (attrs->Length == 0) { hasBindings = false; break; }

						PropMapAttribute^ pm = dynamic_cast<PropMapAttribute^>(attrs[0]);
						MemberInfo^ member = ctor->DeclaringType->GetProperty(pm->Property);
						bindings->Add(System::Expressions::Expression::Bind(member, args[i]));
					}

					if (hasBindings)
					{
						// TODO: May CTP bug workaround (can't use MemberInit and call Ctor in one expression)
						ConstructorInfo^ emptyCtor = ctor->DeclaringType->GetConstructor(Type::EmptyTypes);

						return System::Expressions::Expression::MemberInit
							(System::Expressions::Expression::New(emptyCtor), bindings);
					}
					else
						return System::Expressions::Expression::New(ctor, args);
				}
				else if (_method->IsVirtual)
					return System::Expressions::Expression::CallVirtual(dynamic_cast<MethodInfo^>(_method), self, args);
				else
					return System::Expressions::Expression::Call(dynamic_cast<MethodInfo^>(_method), self, args);
			}
		};

		/// <summary>
		/// Represents call to a method or constructor with known return type
		/// </summary>
		generic<typename T> public ref class MethodBaseInvokeExpression : TypedExpression<T>
		{
		public:
			MethodBaseInvokeExpression(MethodBase^ method, GenericExpression^ instance, ... array<GenericExpression^>^ parameters)
			{
				_inner = gcnew MethodBaseInvokeExpressionUntyped(method, instance, parameters);
			}
		};


		/// <summary>
		/// Represents call to a method with unknown return type
		/// </summary>
		public ref class MethodInvokeExpressionUntyped : MethodBaseInvokeExpressionUntyped
		{
		public:
			MethodInvokeExpressionUntyped(MethodInfo^ method, GenericExpression^ instance, array<GenericExpression^>^ parameters) 
				: MethodBaseInvokeExpressionUntyped(method, instance, parameters) { }
			MethodInvokeExpressionUntyped(MethodInfo^ method, GenericExpression^ instance, GenericExpression^ param) 
				: MethodBaseInvokeExpressionUntyped(method, instance, nullptr ) 
				{ _parameters = gcnew cli::array<GenericExpression^>{ param }; }
		};


		/// <summary>
		/// Represents call to a method with known return type
		/// </summary>
		generic<typename T> public ref class MethodInvokeExpression : MethodBaseInvokeExpression<T>
		{
		public:
			MethodInvokeExpression(MethodInfo^ method, GenericExpression^ instance, ... array<GenericExpression^>^ parameters) 
				: MethodBaseInvokeExpression(method, instance, parameters) { }
			MethodInvokeExpression(MethodInfo^ method, GenericExpression^ instance, GenericExpression^ param) 
				: MethodBaseInvokeExpression(method, instance, param ) 
				{ }
		};

		/// <summary>
		/// Represents call to a constructor with unknown return type
		/// </summary>
		public ref class ConstructorInvokeExpressionUntyped : MethodBaseInvokeExpressionUntyped
		{
		public:
			ConstructorInvokeExpressionUntyped(ConstructorInfo^ ctor, ... array<GenericExpression^>^ parameters) 
				: MethodBaseInvokeExpressionUntyped(ctor, nullptr, parameters) { }
		};

		/// <summary>
		/// Represents call to a constructor with known return type
		/// </summary>
		generic<typename T> public ref class ConstructorInvokeExpression : MethodBaseInvokeExpression<T>
		{
		public:
			ConstructorInvokeExpression(ConstructorInfo^ ctor, ... array<GenericExpression^>^ parameters) 
				: MethodBaseInvokeExpression(ctor, nullptr, parameters) { }
		};

		/// <summary>
		/// Represents binary operation (for example +, -, * and many other)
		/// </summary>
		generic<typename T, typename TL, typename TR> public ref class BinaryExpression : Expression<T>
		{
		private:
			Expression<TL>^ _left;
			Expression<TR>^ _right;
			ExpressionType _type;

		public:
			BinaryExpression(Expression<TL>^ left, Expression<TR>^ right, ExpressionType type)
			{
				_left = left;
				_right = right;
				_type = type;
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				if (TR::typeid == TL::typeid && TL::typeid == String::typeid && _type == ExpressionType::Add) 
				{
					// String concatenation
					MethodInfo^ meth = (String::typeid)->GetMethod("Concat", gcnew array<Type^>{ cli::array<String^>::typeid });
					return (MethodInvokeExpression<T>(meth, nullptr, gcnew ParamsExpression<String^>
						(dynamic_cast<Expression<String^>^>(_left), dynamic_cast<Expression<String^>^>(_right)))).ToLinq();
				}
				else
				{
					System::Expressions::Expression^ leftVal = _left?(_left->ToLinq()):(System::Expressions::Expression::Constant(nullptr));
					System::Expressions::Expression^ rightVal = _right?(_right->ToLinq()):(System::Expressions::Expression::Constant(nullptr));

					if (_type == ExpressionType::Add) return System::Expressions::Expression::Add(leftVal, rightVal);
					if (_type == ExpressionType::Subtract) return System::Expressions::Expression::Subtract(leftVal, rightVal);
					if (_type == ExpressionType::Multiply) return System::Expressions::Expression::Multiply(leftVal, rightVal);
					if (_type == ExpressionType::Divide) return System::Expressions::Expression::Divide(leftVal, rightVal);
					if (_type == ExpressionType::RShift) return System::Expressions::Expression::RShift(leftVal, rightVal);
					if (_type == ExpressionType::LShift) return System::Expressions::Expression::LShift(leftVal, rightVal);
					if (_type == ExpressionType::LT) return System::Expressions::Expression::LT(leftVal, rightVal);
					if (_type == ExpressionType::GT) return System::Expressions::Expression::GT(leftVal, rightVal);
					if (_type == ExpressionType::GE) return System::Expressions::Expression::GE(leftVal, rightVal);
					if (_type == ExpressionType::LE) return System::Expressions::Expression::LE(leftVal, rightVal);
					if (_type == ExpressionType::EQ) return System::Expressions::Expression::EQ(leftVal, rightVal);
					if (_type == ExpressionType::NE) return System::Expressions::Expression::NE(leftVal, rightVal);
					if (_type == ExpressionType::Or) return System::Expressions::Expression::Or(leftVal, rightVal);
					if (_type == ExpressionType::And) return System::Expressions::Expression::And(leftVal, rightVal);
				}
				throw gcnew NotImplementedException("This binary operation is not supported!");
			}
		};


		/// <summary>
		/// Represents unary operations (like boolean negation)
		/// </summary>
		generic<typename T, typename PT> public ref class UnaryExpression : Expression<T>
		{
		private:
			Expression<PT>^ _value;
			ExpressionType _type;

		public:
			UnaryExpression(Expression<PT>^ value, ExpressionType type)
			{
				_value = value;
				_type = type;
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				if (_type == ExpressionType::Not) return System::Expressions::Expression::Not(_value->ToLinq());
				throw gcnew NotImplementedException("This unary operation is not supported!");
			}
		};


		/// <summary>
		/// Base class for the Expr template. Wraps another type of expression.
		/// </summary>
		generic<typename T> public ref class ExpressionWrapper abstract : Expression<T>
		{
		protected:
			Expression<T>^ _value;

		public:
			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				return _value->ToLinq();
			}
		};


		/// <summary>
		/// Represents variable of type T
		/// </summary>
		generic<typename T> public ref class Variable : Expression<T>
		{
		private:
			String^ _name;
			System::Expressions::Expression^ _var;

		public:
			Variable(String^ name)
			{
				_name = name;
				_var = System::Expressions::Expression::Parameter(T::typeid, _name);
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				return _var;
			}
		};


		/// <summary>
		/// Represents literal of type T
		/// </summary>
		generic<typename T> public ref class Literal : Expression<T>
		{
		private:
			T _value;

		public:
			Literal(T value)
			{
				_value = value;
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				return System::Expressions::Expression::Constant(_value);
			}
		};


		/// <summary>
		/// Represents lambda expression. F type parameter should be one of the System::Query::Func types.
		/// </summary>
		generic<typename F> public ref class Lambda : Expression<F>
		{
		private:
			GenericExpression^ _body;
			List<System::Expressions::ParameterExpression^>^ _params;

		public:
			Lambda(array<GenericExpression^>^ params, GenericExpression^ body)
			{
				_body = body;
				_params = gcnew List<System::Expressions::ParameterExpression^>();
				for each(GenericExpression^ ge in params) 
					_params->Add((System::Expressions::ParameterExpression^)ge->ToLinq());
			}

			/// <summary> 
			/// Returns LINQ representation of the expression. 
			/// </summary>
			virtual System::Expressions::Expression^ ToLinq() override 
			{
				return System::Expressions::Expression::Lambda(F::typeid, _body->ToLinq(), _params);
			}

			/// <summary> 
			/// Returns typed LINQ representation of the expression. 
			/// </summary>
			System::Expressions::Expression<F>^ ToTypedLinq()
			{
				return System::Expressions::Expression::Lambda<F>(_body->ToLinq(), _params);
			}

			/// <summary> 
			/// Compiles the lambda expression
			/// </summary>
			F Compile()
			{
				System::Expressions::Expression<F>^ lambda = 
					System::Expressions::Expression::Lambda<F>(_body->ToLinq(), _params);
				return lambda->Compile();
			}
		};
	}
}

// Expression::Prop & Expression::Invoke implementations
generic<typename T> generic<typename R> EeekSoft::CLinq::Expression<R>^ EeekSoft::CLinq::Expression<T>::ExpressionInvoke(String^ name, ... cli::array<GenericExpression^>^ args)
{
	Type^ t = T::typeid;
	return gcnew MethodInvokeExpression<R>(t->GetMethod(name), this, args);
}

generic<typename T> generic<typename R> EeekSoft::CLinq::Expression<R>^ EeekSoft::CLinq::Expression<T>::ExpressionProp(String^ name)
{
	Type^ t = T::typeid;
	return gcnew PropertyExpression<R>(t->GetProperty(name), this);
}

generic<typename T> generic<typename R> EeekSoft::CLinq::Expression<R>^ EeekSoft::CLinq::Expression<T>::ExpressionInvokeStatic(String^ name, ... cli::array<GenericExpression^>^ args)
{
	Type^ t = T::typeid;
	return gcnew MethodInvokeExpression<R>(t->GetMethod(name), nullptr, args);
}

generic<typename T> generic<typename R> EeekSoft::CLinq::Expression<R>^ EeekSoft::CLinq::Expression<T>::ExpressionPropStatic(String^ name)
{
	Type^ t = T::typeid;
	return gcnew PropertyExpression<R>(t->GetProperty(name), nullptr);
}

