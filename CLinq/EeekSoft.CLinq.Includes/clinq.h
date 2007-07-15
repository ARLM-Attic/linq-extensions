#pragma once
#include "clinqcore.h"
#include "clinqtyped.h"
#include "clinqseq.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Collections::Generic;

namespace EeekSoft
{
	namespace CLinq
	{
		namespace clq
		{
			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 1 argument
			/// and body and returns lambda expression. 
			/// When using Expr as parameters, the type inferrence infers generic arguments.
			/// </summary>
			template<class A0, class T> 
			Lambda<System::Query::Func<A0, T>^>^ fun(Expr<A0> v, Expr<T> body)
			{
				return gcnew Lambda<System::Query::Func<A0, T>^>(gcnew array<GenericExpression^>{ v }, body);
			}

			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 2 arguments 
			/// and body and returns lambda expression.
			/// When using Expr as parameters, the type inferrence infers generic arguments.
			/// </summary>
			template<class A0, class A1, class T>
			Lambda<System::Query::Func<A0, A1, T>^>^ fun(Expr<A0> v0, Expr<A1> v1, Expr<T> body)
			{
				return gcnew Lambda<System::Query::Func<A0, A1, T>^>(gcnew array<GenericExpression^>{ v0, v1 }, body);
			}

			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 3 arguments 
			/// and body and returns lambda expression.
			/// When using Expr as parameters, the type inferrence infers generic arguments.
			/// </summary>
			template<class A0, class A1, class A2, class T>
			Lambda<System::Query::Func<A0, A1, A2, T>^>^ fun(Expr<A0> v0, Expr<A1> v1, Expr<A2> v2, Expr<T> body)
			{
				return gcnew Lambda<System::Query::Func<A0, A1, A2, T>^>(gcnew array<GenericExpression^>{ v0, v1, v2 }, body);
			}

			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 4 arguments 
			/// and body and returns lambda expression.
			/// When using Expr as parameters, the type inferrence infers generic arguments.
			/// </summary>
			template<class A0, class A1, class A2, class A3, class T>
			Lambda<System::Query::Func<A0, A1, A2, A3, T>^>^ fun(Expr<A0> v0, Expr<A1> v1, Expr<A2> v2, Expr<A3> v3, Expr<T> body)
			{
				return gcnew Lambda<System::Query::Func<A0, A1, A2, A3, T>^>(gcnew array<GenericExpression^>{ v0, v1, v2, v3 }, body);
			}

			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 1 argument
			/// and body and returns lambda expression.
			/// </summary>
			template<class A0, class T> 
			Lambda<System::Query::Func<A0, T>^>^ fun(Expression<A0>^ v, Expression<T>^ body)
			{
				return gcnew Lambda<System::Query::Func<A0, T>^>(gcnew array<GenericExpression^>{ v }, body);
			}

			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 2 arguments 
			/// and body and returns lambda expression.
			/// </summary>
			template<class A0, class A1, class T>
			Lambda<System::Query::Func<A0, A1, T>^>^ fun(Expression<A0>^ v0, Expression<A1>^ v1, Expression<T>^ body)
			{
				return gcnew Lambda<System::Query::Func<A0, A1, T>^>(gcnew array<GenericExpression^>{ v0, v1 }, body);
			}

			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 3 arguments 
			/// and body and returns lambda expression.
			/// </summary>
			template<class A0, class A1, class A2, class T>
			Lambda<System::Query::Func<A0, A1, A2, T>^>^ fun(Expression<A0>^ v0, Expression<A1>^ v1, Expression<A2>^ v2, Expression<T>^ body)
			{
				return gcnew Lambda<System::Query::Func<A0, A1, A2, T>^>(gcnew array<GenericExpression^>{ v0, v1, v2 }, body);
			}

			/// <summary>
			/// Function for declaring lambda expressions. Takes expressions representing 4 arguments 
			/// and body and returns lambda expression.
			/// </summary>
			template<class A0, class A1, class A2, class A3, class T>
			Lambda<System::Query::Func<A0, A1, A2, A3, T>^>^ fun(Expression<A0>^ v0, Expression<A1>^ v1, Expression<A2>^ v2, Expression<A3>^ v3, Expression<T>^ body)
			{
				return gcnew Lambda<System::Query::Func<A0, A1, A2, A3, T>^>(gcnew array<GenericExpression^>{ v0, v1, v2, v3 }, body);
			}

			/// <summary>
			/// Represents creation of an object instance. Type parameter specifies class to be created and parameters will be
			/// passed as an arguments to constructor. Constructor with the same number of parameters will be selected.
			/// </summary>
			/// <remarks>
			/// Throws CLinqException if the constructor with specified number of arguments doesn't exist or is ambigous.
			/// </remarks>
			template<class T>
			Expr<T> newobj(... array<GenericExpression^>^ args)
			{
				Type^ t = T::typeid;

				ConstructorInfo^ selected = nullptr;
				for each(ConstructorInfo^ c in t->GetConstructors())
				{
					if (c->GetParameters()->Length == args->Length) 
					{
						if (selected == nullptr)
							selected = c;
						else 
							throw gcnew Exception("Ambigous constructor found!");
					}
				}
				if (selected == nullptr)
					throw gcnew Exception("No constructor with specified number of parameters found!");
				return Expr<T>(gcnew ConstructorInvokeExpression<T>(selected, args));
			}

			/// <summary>
			/// Represents conversion between expressions of two different types.
			/// </summary>
			template<class T>
			Expr<T> conv(GenericExpression^ expr)
			{
				return Expr<T>::Convert(expr);
			}

			/// <summary>
			/// Returns same expression that is passed as a parameter, but with type information.
			/// Use this method if you have untyped expression and you want to convert it to typed expression.
			/// </summary>
			template<class T>
			Expr<T> typed(GenericExpression^ expr)
			{
				return Expr<T>::Typed(expr);
			}
		}
	}
}