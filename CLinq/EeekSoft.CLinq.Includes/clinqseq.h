#pragma once

// Ugly macros that make it a bit simpler to write Expr<IEnumerable<T>> (see below)
#define DEC_METHOD_CACHE1(name, sname, a0) \
	static MethodInfo^ _ ## name; static MethodInfo^ Method_ ## name (... cli::array<Type^>^ gt) { \
		if (_ ## name == nullptr) _ ## name = GetGenericMethod(Seq, sname, gcnew array<Type^>{ a0 })->MakeGenericMethod(gt); return _ ## name; }
#define DEC_METHOD_CACHE2(name, sname, a0, a1) \
	static MethodInfo^ _ ## name; static MethodInfo^ Method_ ## name (... cli::array<Type^>^ gt) { \
		if (_ ## name == nullptr) _ ## name = GetGenericMethod(Seq, sname, gcnew array<Type^>{ a0, a1 })->MakeGenericMethod(gt); return _ ## name; }
#define DEC_METHOD_CACHE3(name, sname, a0, a1, a2) \
	static MethodInfo^ _ ## name; static MethodInfo^ Method_ ## name (... cli::array<Type^>^ gt) { \
		if (_ ## name == nullptr) _ ## name = GetGenericMethod(Seq, sname, gcnew array<Type^>{ a0, a1, a2 })->MakeGenericMethod(gt); return _ ## name; }
#define DEC_METHOD_CACHE5(name, sname, a0, a1, a2, a3, a4) \
	static MethodInfo^ _ ## name; static MethodInfo^ Method_ ## name (... cli::array<Type^>^ gt) { \
		if (_ ## name == nullptr) _ ## name = GetGenericMethod(Seq, sname, gcnew array<Type^>{ a0, a1, a2, a3, a4 })->MakeGenericMethod(gt); return _ ## name; }

#include "clinqcore.h"
#include "clinqtyped.h"

using namespace System;
using namespace System::Query;
using namespace System::Reflection;
using namespace System::Collections::Generic;

namespace EeekSoft {
	namespace CLinq {

		/// <summary>
		/// Searches for method by it's name and types. Finds generic methods as well.
		/// (Expects that parameters will be types without generic parameters)
		/// </summary>
		MethodInfo^ GetGenericMethod(Type^ type, String^ name, ... cli::array<Type^>^ args)
		{
			for each(MethodInfo^ mi in type->GetMethods())
			{
				if (mi->Name != name) continue;
				cli::array<ParameterInfo^>^ pi = mi->GetParameters();
				if (pi->Length != args->Length) continue;

				for(int i=0; i<args->Length; i++)
					if (pi[i]->ParameterType->GetGenericTypeDefinition() != args[i]) goto failed;
				return mi;
			failed:;
			}
			return nullptr;
		}


		/// <summary>
		/// This generic class represents pair of values.
		/// </summary>
		generic<typename A, typename B> ref class Tuple
		{
		private:
			A _a;
			B _b;

		public:
			/// <summary>
			/// Initializes the values stored in the class.
			/// </summary>
			Tuple([PropMap("First")] A first, [PropMap("Second")] B second) 
			{
				_a = first; _b = second;
			}

			/// <summary>
			/// TODO: May CTP bug workaround (can't use MemberInit and call Ctor in one expression)
			/// </summary>
			Tuple() { }

			/// <summary>
			/// Gets or sets the first value stored in the tuple.
			/// </summary>
			property A First { 
				A get() { return _a; } 
				void set(A value) { _a = value; }
			}

			/// <summary>
			/// Gets or sets the second value stored in the tuple.
			/// </summary>
			property B Second { 
				B get() { return _b; } 
				void set(B value) { _b = value; }
			}
		};


		/// <summary>
		/// Expr template specialization for working with the Tuple type
		/// </summary>
		template<class A, class B> ref class Expr<Tuple<A, B>^> : ExpressionWrapper<Tuple<A, B>^>
		{
		public:
			static property Type^ WrappedType { Type^ get() { return Tuple<A, B>::typeid; } }
    
		public:
			Expr<Tuple<A, B>^>() { }
			Expr<Tuple<A, B>^>(Tuple<A, B>^ val) { _value = gcnew Literal<Tuple<A, B>^>(val); }
			Expr<Tuple<A, B>^>(Expression<Tuple<A, B>^>^ value) { _value = value; }
			Expr<Tuple<A, B>^>(Expr<Tuple<A, B>^>% b)	{ _value = b._value; }
			operator Expression<Tuple<A, B>^>^() { return _value; }
			operator GenericExpression^() { return _value; }
			static operator Expr<Tuple<A, B>^>(Expression<Tuple<A, B>^>^ value)  { return Expr<Tuple<A, B>^>(value); }
			static operator Expr<Tuple<A, B>^>(Tuple<A, B>^ b) { return Expr<Tuple<A, B>^>(b); }

		public:
			static Expr<Tuple<A, B>^> Typed(GenericExpression^ value) 
			{ 
				return Expr<Tuple<A, B>^>(gcnew TypedExpression<Tuple<A, B>^>(value));
			}

			static Expr<Tuple<A, B>^> Convert(GenericExpression^ value) 
			{ 
				return Expr<Tuple<A, B>^>(gcnew ConvertExpression<Tuple<A, B>^>(value));
			}

		private:
			static property Type^ Tup 
			{
				Type^ get() { return Tuple<A, B>::typeid; }
			}

		public:
			/// <summary>
			/// Represents getting the first value stored in tuple
			/// </summary>
			property Expr<A> First
			{
				Expr<A> get()
				{
					return Expr<A>(gcnew PropertyExpression<A>(Tup->GetProperty("First"), this));
				}
			}

			/// <summary>
			/// Represents getting the second value stored in tuple
			/// </summary>
			property Expr<B> Second
			{
				Expr<B> get()
				{
					return Expr<B>(gcnew PropertyExpression<B>(Tup->GetProperty("Second"), this)); 
				}
			}
		};


		/// <summary>
		/// Expr template specialization for working with the IEnumerable type
		/// </summary>
		template<class T> ref class Expr<IEnumerable<T>^> : ExpressionWrapper<IEnumerable<T>^>
		{
		public:
			static property Type^ WrappedType { Type^ get() { return IEnumerable<T>::typeid; } }
    
		public:
			Expr<IEnumerable<T>^>() { }
			Expr<IEnumerable<T>^>(IEnumerable<T>^ val) { _value = gcnew Literal<IEnumerable<T>^>(val); }
			Expr<IEnumerable<T>^>(Expression<IEnumerable<T>^>^ value) { _value = value; }
			Expr<IEnumerable<T>^>(Expr<IEnumerable<T>^>% b)	{ _value = b._value; }
			operator Expression<IEnumerable<T>^>^() { return _value; }
			operator GenericExpression^() { return _value; }
			static operator Expr<IEnumerable<T>^>(Expression<IEnumerable<T>^>^ value)  { return Expr<IEnumerable<T>^>(value); }
			static operator Expr<IEnumerable<T>^>(IEnumerable<T>^ b) { return Expr<IEnumerable<T>^>(b); }

		public:
			static Expr<IEnumerable<T>^> Typed(GenericExpression^ value) 
			{ 
				return Expr<IEnumerable<T>^>(gcnew TypedExpression<IEnumerable<T>^>(value));
			}

			static Expr<IEnumerable<T>^> Convert(GenericExpression^ value) 
			{ 
				return Expr<IEnumerable<T>^>(gcnew ConvertExpression<IEnumerable<T>^>(value));
			}

		private:
			static cli::array<Type^>^ _funcTypes;

			static property Type^ Seq 
			{
				Type^ get() { return System::Query::Sequence::typeid; }
			}

			static property cli::array<Type^>^ FuncTypes
			{
				cli::array<Type^>^ get() 
				{
					if (_funcTypes == nullptr)
						_funcTypes = gcnew cli::array<Type^> 
						{
							nullptr,
							System::Query::Func::typeid,
							(System::Query::Func<int,int>::typeid)->GetGenericTypeDefinition(),
							(System::Query::Func<int,int,int>::typeid)->GetGenericTypeDefinition(),
							(System::Query::Func<int,int,int,int>::typeid)->GetGenericTypeDefinition(),
						};
					return _funcTypes;
				}
			}

		private:
			// Ugly macros that declare reflection cache...
			DEC_METHOD_CACHE1(Count, "Count", IEnumerable::typeid);
			DEC_METHOD_CACHE2(Count2, "Count", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(Select, "Select", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(Where, "Where", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(SelectMany, "SelectMany", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE5(Join, "Join", IEnumerable::typeid, IQueryable::typeid, FuncTypes[2], FuncTypes[2], FuncTypes[2] );
			DEC_METHOD_CACHE5(GroupJoin, "GroupJoin", IEnumerable::typeid, IQueryable::typeid, FuncTypes[2], FuncTypes[2], FuncTypes[2] );
			DEC_METHOD_CACHE2(OrderBy, "OrderBy", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(OrderByDescending, "OrderByDescending", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE1(First, "First", IEnumerable::typeid );
			DEC_METHOD_CACHE1(FirstOrDefault, "FirstOrDefault", IEnumerable::typeid );
			DEC_METHOD_CACHE1(Last, "Last", IEnumerable::typeid );
			DEC_METHOD_CACHE1(LastOrDefault, "LastOrDefault", IEnumerable::typeid );
			DEC_METHOD_CACHE1(Single, "Single", IEnumerable::typeid );
			DEC_METHOD_CACHE1(SingleOrDefault, "SingleOrDefault", IEnumerable::typeid );
			DEC_METHOD_CACHE1(Any, "Any", IEnumerable::typeid );
			DEC_METHOD_CACHE1(Min, "Min", IEnumerable::typeid );
			DEC_METHOD_CACHE1(Max, "Max", IEnumerable::typeid );
			DEC_METHOD_CACHE1(LongCount, "LongCount", IEnumerable::typeid );
			DEC_METHOD_CACHE2(LongCount2, "LongCount", IEnumerable::typeid, FuncTypes[2] );			
			DEC_METHOD_CACHE2(Sum, "Sum", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(Average, "Average", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(GroupBy, "GroupBy", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE3(GroupBy2, "GroupBy2", IEnumerable::typeid, FuncTypes[2], FuncTypes[2] );
			DEC_METHOD_CACHE2(Concat, "Concat", IEnumerable::typeid, IQueryable::typeid );
			DEC_METHOD_CACHE2(Union, "Union", IEnumerable::typeid, IQueryable::typeid );
			DEC_METHOD_CACHE2(Intersect, "Intersect", IEnumerable::typeid, IQueryable::typeid );
			DEC_METHOD_CACHE2(Except, "Except", IEnumerable::typeid, IQueryable::typeid );
			DEC_METHOD_CACHE2(All, "All", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(Any2, "Any2", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(Last2, "Last2", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(Single2, "Single2", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(First2, "First2", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(LastOrDefault2, "LastOrDefault2", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(SingleOrDefault2, "SingleOrDefault2", IEnumerable::typeid, FuncTypes[2] );
			DEC_METHOD_CACHE2(FirstOrDefault2, "FirstOrDefault2", IEnumerable::typeid, FuncTypes[2] );

		public:

			/// <summary>
			/// The Select operator performs a projection over a sequence
			/// </summary>
			template<class R> Expr<IEnumerable<R>^> Select(Lambda<System::Query::Func<T, R>^>^ selector)
			{
				return Expr<IEnumerable<R>^>(gcnew MethodInvokeExpression<IEnumerable<R>^>
					(Method_Select(T::typeid, R::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Where operator filters a sequence based on a predicate
			/// </summary>
			Expr<IEnumerable<T>^> Where(Lambda<System::Query::Func<T, bool>^>^ filter)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Where(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The SelectMany operator performs a one to many element projection over a sequence.
			/// </summary>
			template<class S> Expr<IEnumerable<S>^> SelectMany(Lambda<Func<T, IEnumerable<S>^>^>^ selector)
			{
				return Expr<IEnumerable<S>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_SelectMany(T::typeid, S::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Join operator performs an inner join of two sequences based on matching keys extracted from the elements.
			/// </summary>
			template<class U, class K, class V> Expr<IEnumerable<V>^> Join(Expr<IQueryable<U>^> inner, Lambda<Func<T,K>^>^ outerKeySelector, 
				Lambda<Func<U,K>^>^ innerKeySelector, Lambda<Func<T,U,V>^>^ resultSelector)
			{
				return Expr<IEnumerable<S>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Join(T::typeid, K::typeid, V::typeid), this, gcnew array<GenericExpression^>{ this, inner, outerKeySelector, innerKeySelector, resultSelector } ));
			}

			/// <summary>
			/// The GroupJoin operator performs a grouped join of two sequences based on matching keys extracted from the elements.
			/// </summary>
			template<class U, class K, class V> Expr<IEnumerable<V>^> GroupJoin(Expr<IQueryable<U>^> inner, Lambda<Func<T,K>^>^ outerKeySelector, 
				Lambda<Func<U,K>^>^ innerKeySelector, Lambda<Func<T,IEnumerable<U>^,V>^>^ resultSelector)
			{
				return Expr<IEnumerable<V>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_GroupJoin(T::typeid, U::typeid, K::typeid, V::typeid), this, gcnew array<GenericExpression^>{ this, inner, outerKeySelector, innerKeySelector, resultSelector } ));
			}

			/// <summary>
			/// The OrderBy operator orders a sequence according to one or more keys in ascending order.
			/// </summary>
			template<class K> Expr<IEnumerable<T>^> OrderBy(Lambda<Func<T,K>^>^ keySelector)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_OrderBy(T::typeid, K::typeid), this, gcnew array<GenericExpression^>{ this, keySelector } ));
			}

			/// <summary>
			/// he OrderBy operator orders a sequence according to one or more keys in descending order.
			/// </summary>
			template<class K> Expr<IEnumerable<T>^> OrderByDescending(Lambda<Func<T, K>^>^ keySelector)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_OrderByDescending(T::typeid, K::typeid), this, gcnew array<GenericExpression^>{ this, keySelector } ));
			}

			/// <summary>
			/// The First operator returns the first element of a sequence.
			/// </summary>
			Expr<T> First()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_First(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The FirstOrDefault operator returns the first element of a sequence, or a default value if no element is found.
			/// </summary>
			Expr<T> FirstOrDefault()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_FirstOrDefault(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Last operator returns the last element of a sequence.
			/// </summary>
			Expr<T> Last()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_Last(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The LastOrDefault operator returns the last element of a sequence, or a default value if no element is found.
			/// </summary>
			Expr<T> LastOrDefault()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_LastOrDefault(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Single operator returns the single element of a sequence.
			/// </summary>
			Expr<T> Single()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_Single(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The SingleOrDefault operator returns the single element of a sequence, or a default value if no element is found.
			/// </summary>
			Expr<T> SingleOrDefault()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_SingleOrDefault(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Any operator checks whether any element of a sequence satisfies a condition.
			/// </summary>
			Expr<bool> Any()
			{
				return Expr<bool>(gcnew MethodInvokeExpression<bool>
					(Method_Any(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Min operator finds the minimum of a sequence of numeric values.
			/// </summary>
			Expr<T> Min()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_Min(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Max operator finds the maximum of a sequence of numeric values.
			/// </summary>
			Expr<T> Max()
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_Max(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The LongCount operator counts the number of elements in a sequence with a return type of Long.
			/// </summary>
			Expr<long long int> LongCount()
			{
				return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
					(Method_LongCount(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Count operator counts the number of elements in a sequence with a return type of int.
			/// </summary>
			Expr<int> Count()
			{
				return Expr<int>(gcnew MethodInvokeExpression<int>
					(Method_Count(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Count operator counts the number of elements in a sequence with a return type of int.
			/// </summary>
			Expr<int> Count(Lambda<System::Query::Func<T, bool>^>^ filter)
			{
				return Expr<int>(gcnew MethodInvokeExpression<int>
					(Method_Count2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The GroupBy operator groups the elements of a sequence.
			/// </summary>
			template<class K> Expr<IEnumerable<IGrouping<K, T>^>^> GroupBy(Lambda<Func<T, K>^>^ keySelector)
			{
				return Expr<IEnumerable<IGrouping<K, T>^>^>(gcnew MethodInvokeExpression<IEnumerable<IGrouping<K, T>^>^>
					(Method_GroupBy(T::typeid, K::typeid), this, gcnew array<GenericExpression^>{ this, keySelector } ));
			}

			/// <summary>
			/// The GroupBy operator groups the elements of a sequence.
			/// </summary>
			template<class K, class E> Expr<IEnumerable<IGrouping<K, E>^>^> GroupBy(Lambda<Func<T, K>^>^ keySelector, Lambda<Func<T, E>^>^ elementSelector)
			{
				return Expr<IEnumerable<IGrouping<K, E>^>^>(gcnew MethodInvokeExpression<IEnumerable<IGrouping<K, E>^>^>
					(Method_GroupBy2(T::typeid, K::typeid, E::typeid), this, gcnew array<GenericExpression^>{ this, keySelector, elementSelector } ));
			}
			
			/// <summary>
			/// The Min operator finds the minimum of a sequence of numeric values.
			/// </summary>
			template<class V> Expr<V> Min(Lambda<Func<T, V>^>^ selector)
			{
				return Expr<V>(gcnew MethodInvokeExpression<V>
					(Method_Min(T::typeid, V::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Max operator finds the maximum of a sequence of numeric values. 
			/// </summary>
			template<class V> Expr<V> Max(Lambda<Func<T, V>^>^ selector)
			{
				return Expr<V>(gcnew MethodInvokeExpression<V>
					(Method_Max(T::typeid, V::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Take operator yields a given number of elements from a sequence and then skips the remainder of the sequence.
			/// </summary>
			Expr<IEnumerable<T>^> Take(Expr<int> count)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Take(T::typeid), this, gcnew array<GenericExpression^>{ this, count } ));
			}

			/// <summary>
			/// The Skip operator skips a given number of elements from a sequence and then yields the remainder of the sequence.
			/// </summary>
			Expr<IEnumerable<T>^> Skip(Expr<int> count)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Skip(T::typeid), this, gcnew array<GenericExpression^>{ this, count } ));
			}

			/// <summary>
			/// The Distinct operator eliminates duplicate elements from a sequence.
			/// </summary>
			Expr<IEnumerable<T>^> Distinct()
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Distinct(T::typeid), this, gcnew array<GenericExpression^>{ this } ));
			}

			/// <summary>
			/// The Concat operator concatenates two sequences.
			/// </summary>
			Expr<IEnumerable<T>^> Concat(Expr<IQueryable<T>^> source)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Concat(T::typeid), this, gcnew array<GenericExpression^>{ this, source } ));
			}

			/// <summary>
			/// The Union operator produces the set union of two sequences.
			/// </summary>
			Expr<IEnumerable<T>^> Union(Expr<IQueryable<T>^> source)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Union(T::typeid), this, gcnew array<GenericExpression^>{ this, source } ));
			}

			/// <summary>
			/// The Intersect operator produces the set intersection of two sequences.
			/// </summary>
			Expr<IEnumerable<T>^> Intersect(Expr<IQueryable<T>^> source)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Intersect(T::typeid), this, gcnew array<GenericExpression^>{ this, source } ));
			}

			/// <summary>
			/// The Except operator produces the set difference between two sequences.
			/// </summary>
			Expr<IEnumerable<T>^> Except(Expr<IQueryable<T>^> source)
			{
				return Expr<IEnumerable<T>^>(gcnew MethodInvokeExpression<IEnumerable<T>^>
					(Method_Except(T::typeid), this, gcnew array<GenericExpression^>{ this, source } ));
			}

			/// <summary>
			/// The First operator returns the first element of a sequence.
			/// </summary>
			Expr<T> First(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_First2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The FirstOrDefault operator returns the first element of a sequence, or a default value if no element is found.
			/// </summary>
			Expr<T> FirstOrDefault(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_FirstOrDefault2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The Last operator returns the last element of a sequence.
			/// </summary>
			Expr<T> Last(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_Last2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The LastOrDefault operator returns the last element of a sequence, or a default value if no element is found.
			/// </summary>
			Expr<T> LastOrDefault(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_LastOrDefault2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The Single operator returns the single element of a sequence.
			/// </summary>
			Expr<T> Single(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_Single2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The SingleOrDefault operator returns the single element of a sequence, or a default value if no element is found.
			/// </summary>
			Expr<T> SingleOrDefault(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<T>(gcnew MethodInvokeExpression<T>
					(Method_SingleOrDefault2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The Any operator checks whether any element of a sequence satisfies a condition.
			/// </summary>
			Expr<bool> Any(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<bool>(gcnew MethodInvokeExpression<bool>
					(Method_Any2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The All operator checks whether all elements of a sequence satisfy a condition.
			/// </summary>
			Expr<bool> All(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<bool>(gcnew MethodInvokeExpression<bool>
					(Method_All2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The LongCount operator counts the number of elements in a sequence with a return type of Long.
			/// </summary>
			Expr<long long int> LongCount(Lambda<Func<T, bool>^>^ filter)
			{
				return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
					(Method_LongCount2(T::typeid), this, gcnew array<GenericExpression^>{ this, filter } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<int> Sum(Lambda<System::Query::Func<T, int>^>^ selector)
			{
				return Expr<int>(gcnew MethodInvokeExpression<int>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<double> Average(Lambda<System::Query::Func<T, int>^>^ selector)
			{
				return Expr<double>(gcnew MethodInvokeExpression<double>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<long long int> Sum(Lambda<System::Query::Func<T, long long int>^>^ selector)
			{
				return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<double> Average(Lambda<System::Query::Func<T, long long int>^>^ selector)
			{
				return Expr<double>(gcnew MethodInvokeExpression<double>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<double> Sum(Lambda<System::Query::Func<T, double>^>^ selector)
			{
				return Expr<double>(gcnew MethodInvokeExpression<double>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<double> Average(Lambda<System::Query::Func<T, double>^>^ selector)
			{
				return Expr<double>(gcnew MethodInvokeExpression<double>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<Decimal> Sum(Lambda<System::Query::Func<T, Decimal>^>^ selector)
			{
				return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<Decimal> Average(Lambda<System::Query::Func<T, Decimal>^>^ selector)
			{
				return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<int>> Sum(Lambda<System::Query::Func<T, Nullable<int>>^>^ selector)
			{
				return Expr<Nullable<int>>(gcnew MethodInvokeExpression<Nullable<int>>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<double>> Average(Lambda<System::Query::Func<T, Nullable<int>>^>^ selector)
			{
				return Expr<Nullable<double>>(gcnew MethodInvokeExpression<Nullable<double>>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<long long int>> Sum(Lambda<System::Query::Func<T, Nullable<long long int>>^>^ selector)
			{
				return Expr<Nullable<long long int>>(gcnew MethodInvokeExpression<Nullable<long long int>>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<double>> Average(Lambda<System::Query::Func<T, Nullable<long long int>>^>^ selector)
			{
				return Expr<Nullable<double>>(gcnew MethodInvokeExpression<Nullable<double>>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<double>> Sum(Lambda<System::Query::Func<T, Nullable<double>>^>^ selector)
			{
				return Expr<Nullable<double>>(gcnew MethodInvokeExpression<Nullable<double>>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<double>> Average(Lambda<System::Query::Func<T, Nullable<double>>^>^ selector)
			{
				return Expr<Nullable<double>>(gcnew MethodInvokeExpression<Nullable<double>>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Sum operator computes the sum of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<Decimal>> Sum(Lambda<System::Query::Func<T, Nullable<Decimal>>^>^ selector)
			{
				return Expr<Nullable<Decimal>>(gcnew MethodInvokeExpression<Nullable<Decimal>>
					(Method_Sum(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}

			/// <summary>
			/// The Average operator computes the average of a sequence of numeric values.
			/// </summary>
			Expr<Nullable<Decimal>> Average(Lambda<System::Query::Func<T, Nullable<Decimal>>^>^ selector)
			{
				return Expr<Nullable<Decimal>>(gcnew MethodInvokeExpression<Nullable<Decimal>>
					(Method_Average(T::typeid), this, gcnew array<GenericExpression^>{ this, selector } ));
			}
		};


		/// <summary>
		/// Expr template specialization for working with the IGrouping type
		/// </summary>
		template<class T, class K> ref class Expr<IGrouping<K, T>^> : ExpressionWrapper<IGrouping<K, T>^>
		{
		public:
			static property Type^ WrappedType { Type^ get() { return IGrouping<K, T>::typeid; } }
    
		public:
			Expr<IGrouping<K, T>^>() { }
			Expr<IGrouping<K, T>^>(IGrouping<K, T>^ val) { _value = gcnew Literal<IGrouping<K, T>^>(val); }
			Expr<IGrouping<K, T>^>(Expression<IGrouping<K, T>^>^ value) { _value = value; }
			Expr<IGrouping<K, T>^>(Expr<IGrouping<K, T>^>% b)	{ _value = b._value; }
			operator Expression<IGrouping<K, T>^>^() { return _value; }
			operator GenericExpression^() { return _value; }
			static operator Expr<IGrouping<K, T>^>(Expression<IGrouping<K, T>^>^ value)  { return Expr<IGrouping<K, T>^>(value); }
			static operator Expr<IGrouping<K, T>^>(IGrouping<K, T>^ b) { return Expr<IGrouping<K, T>^>(b); }

		public:
			static Expr<IGrouping<K, T>^> Typed(GenericExpression^ value) 
			{ 
				return Expr<IGrouping<K, T>^>(gcnew TypedExpression<IGrouping<K, T>^>(value));
			}

			static Expr<IGrouping<K, T>^> Convert(GenericExpression^ value) 
			{ 
				return Expr<IGrouping<K, T>^>(gcnew ConvertExpression<IGrouping<K, T>^>(value));
			}

		private:
			static property Type^ Grouping
			{
				Type^ get() { return IGrouping<K, T>::typeid; }
			}

		public:
			/// <summary>
			/// Returns expression representing the Key of the grouping
			/// </summary>
			property Expr<K> Key
			{
				Expr<K> get()
				{
					return Expr<K>(gcnew PropertyExpression<K>(Grouping->GetProperty("Key"), this));
				}
			}

			/// <summary>
			/// Returns expression representing the values of the grouping
			/// </summary>
			property Expr<IEnumerable<T>^> Values
			{
				Expr<IEnumerable<T>^> get()
				{
					return Expr<IEnumerable<T>^>::Typed(this);
				}
			}
		};
} }