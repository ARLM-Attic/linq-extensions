#pragma once

using namespace System;
using namespace System::Reflection;
using namespace System::Collections::Generic;

namespace EeekSoft {
	namespace CLinq {
		/// <summary>
		/// This template class represents expression. You can use tempalte specializations
		/// to simplify working with expressions of specific type.
		/// </summary>
		template<class T> ref class Expr : ExpressionWrapper<T>
		{
		public:
			/// <summary>
			/// Returns type information about the type of this expression
			/// </summary>
			static property Type^ WrappedType { Type^ get() { return T::typeid; } }

		public:
			/// <summary>
			/// Creates expression representing literal value
			/// </summary>
      Expr<T>(T val) { _value = gcnew Literal<T>(val); }
			
			/// <summary>
			/// Conversion from generic Expression class to Expr template
			/// </summary>
      Expr<T>(Expression<T>^ value) { _value = value; }

			/// <summary>
			/// Copy constructor
			/// </summary>
			Expr<T>(Expr<T>% t)	{ _value = t._value; }

		public:
			/// <summary>
			/// Invocation of method specified by its name. Returns expression representing the call.
			/// </summary>
			template<class R> Expr<R> Invoke(String^ name, ... cli::array<GenericExpression^>^ args)
			{ return Expr<R>(ExpressionInvoke<R>(name, args)); }
			/// <summary>
			/// Invocation of static method specified by its name. Returns expression representing the call.
			/// </summary>
			template<class R> static Expr<R> InvokeStatic(String^ name, ... cli::array<GenericExpression^>^ args)
			{ return Expr<R>(ExpressionInvokeStatic<R>(name, args)); }

			/// <summary>
			/// Reading of a property specified by its name. Returns expression representing the property read.
			/// </summary>
			template<class R> Expr<R> Prop(String^ name)
			{ return Expr<R>(ExpressionProp<R>(name)); }
			/// <summary>
			/// Reading of a property specified by its name. Returns expression representing the property read.
			/// </summary>
			template<class R> static Expr<R> PropStatic(String^ name)
			{ return Expr<R>(ExpressionPropStatic<R>(name)); }
		};


		/// <summary>
		/// This template class represents variable. You can use tempalte specializations
		/// to simplify working with variables of specific type.
		/// </summary>
		template<class T> ref class Var : ExpressionWrapper<T>
		{
		public:
			Var<T>(String^ name)
			{
				_value = gcnew Variable<T>(name);
			}
			operator Expression<T>^()
			{
				return _value;
			}
		};
	}
}