#pragma once

#include "EeekSoft.CLinq.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Expressions;
using namespace System::Query;

namespace EeekSoft {
	namespace CLinq {

		/// <summary> 
		/// Returns CLinq query. Contains several methods for constructing queries. 
		/// These methods are called query operators in LINQ terminology.
		/// </summary>
		generic<typename T> public ref class CQuery
		{
		private:
			IQueryable<T>^ _q;

		public:
			/// <summary> 
			/// Underlying LINQ query
			/// </summary>
			property IQueryable<T>^ Query
			{
				IQueryable<T>^ get() { return _q; }
			}

		public:
			CQuery(IQueryable<T>^ q)
			{
				_q = q;
			}

			generic<typename R> CQuery<R>^ Select(Lambda<Func<T, R>^>^ selector)
			{
				return gcnew CQuery<R>(Queryable::Select<T,R>(_q, selector->ToTypedLinq()));
			}

			CQuery<T>^ Where(Lambda<Func<T, bool>^>^ filter)
			{
				return gcnew CQuery<T>(Queryable::Where<T>(_q, filter->ToTypedLinq()));
			}

			generic<typename S> CQuery<S>^ SelectMany(Lambda<Func<T, IEnumerable<S>^>^>^ selector)
			{
				return gcnew CQuery<S>(Queryable::SelectMany<T,S>(_q, selector->ToTypedLinq()));
			}

			generic<typename U, typename K, typename V> CQuery<V>^ Join(CQuery<U>^ inner, Lambda<Func<T,K>^>^ outerKeySelector, 
				Lambda<Func<U,K>^>^ innerKeySelector, Lambda<Func<T,U,V>^>^ resultSelector)
			{
				return gcnew CQuery<V>(Queryable::Join<T,U,K,V>(_q, inner->Query, outerKeySelector->ToTypedLinq(), 
					innerKeySelector->ToTypedLinq(), resultSelector->ToTypedLinq()));
			}

			generic<typename U, typename K, typename V> CQuery<V>^ GroupJoin(CQuery<U>^ inner, Lambda<Func<T,K>^>^ outerKeySelector, 
				Lambda<Func<U,K>^>^ innerKeySelector, Lambda<Func<T,IEnumerable<U>^,V>^>^ resultSelector)
			{
				return gcnew CQuery<V>(Queryable::GroupJoin<T,U,K,V>(_q, inner->Query, outerKeySelector->ToTypedLinq(), 
					innerKeySelector->ToTypedLinq(), resultSelector->ToTypedLinq()));
			}

			generic<typename K> CQuery<T>^ OrderBy(Lambda<Func<T,K>^>^ keySelector)
			{
				return gcnew CQuery<T>(Queryable::OrderBy<T, K>(_q, keySelector->ToTypedLinq()));
			}

			generic<typename K> CQuery<T>^ OrderByDescending(Lambda<Func<T, K>^>^ keySelector)
			{
				return gcnew CQuery<T>(Queryable::OrderByDescending<T, K>(_q, keySelector->ToTypedLinq()));
			}

			CQuery<T>^ Take(int count)
			{
				return gcnew CQuery<T>(Queryable::Take<T>(_q, count));
			}

			CQuery<T>^ Skip(int count)
			{
				return gcnew CQuery<T>(Queryable::Skip<T>(_q, count));
			}

			// watch out - VS sometimes hangs when editing following two methods :-)

			generic<typename K> CQuery<IGrouping<K, T>^>^ GroupBy(Lambda<Func<T, K>^>^ keySelector)
			{
				return gcnew CQuery<IGrouping<K, T>^>(Queryable::GroupBy<T, K>(_q, keySelector->ToTypedLinq()));
			}

			generic<typename K, typename E> CQuery<IGrouping<K, E>^>^ GroupBy(Lambda<Func<T, K>^>^ keySelector, Lambda<Func<T, E>^>^ elementSelector)
			{
				return gcnew CQuery<IGrouping<K, E>^>(Queryable::GroupBy<T, K, E>(_q, keySelector->ToTypedLinq(), elementSelector->ToTypedLinq()));
			}
			
			CQuery<T>^ Distinct()
			{
				return gcnew CQuery<T>(Queryable::Distinct<T>(_q));
			}

			CQuery<T>^ Concat(IQueryable<T>^ source)
			{
				return gcnew CQuery<T>(Queryable::Concat<T>(_q, source));
			}

			CQuery<T>^ Union(IQueryable<T>^ source)
			{
				return gcnew CQuery<T>(Queryable::Union<T>(_q, source));
			}

			CQuery<T>^ Intersect(IQueryable<T>^ source)
			{
				return gcnew CQuery<T>(Queryable::Union<T>(_q, source));
			}

			CQuery<T>^ Except(IQueryable<T>^ source)
			{
				return gcnew CQuery<T>(Queryable::Union<T>(_q, source));
			}

			T First(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::First<T>(_q, filter->ToTypedLinq());
			}

			T FirstOrDefault(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::FirstOrDefault<T>(_q, filter->ToTypedLinq());
			}

			T Last(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::Last<T>(_q, filter->ToTypedLinq());
			}

			T LastOrDefault(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::LastOrDefault<T>(_q, filter->ToTypedLinq());
			}

			T Single(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::Single<T>(_q, filter->ToTypedLinq());
			}

			T SingleOrDefault(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::SingleOrDefault<T>(_q, filter->ToTypedLinq());
			}

			T First()
			{
				return Queryable::First<T>(_q);
			}

			T FirstOrDefault()
			{
				return Queryable::FirstOrDefault<T>(_q);
			}

			T Last()
			{
				return Queryable::Last<T>(_q);
			}

			T LastOrDefault()
			{
				return Queryable::LastOrDefault<T>(_q);
			}

			T Single()
			{
				return Queryable::Last<T>(_q);
			}

			T SingleOrDefault()
			{
				return Queryable::SingleOrDefault<T>(_q);
			}

			bool Any(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::Any<T>(_q, filter->ToTypedLinq());
			}

			bool Any()
			{
				return Queryable::Any<T>(_q);
			}

			bool All(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::All<T>(_q, filter->ToTypedLinq());
			}

			int Count()
			{
				return Queryable::Count<T>(_q);
			}

			int Count(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::Count<T>(_q, filter->ToTypedLinq());
			}

			long long int LongCount()
			{
				return Queryable::LongCount<T>(_q);
			}

			long long int LongCount(Lambda<Func<T, bool>^>^ filter)
			{
				return Queryable::LongCount<T>(_q, filter->ToTypedLinq());
			}

			T Min()
			{
				return Queryable::Min<T>(_q);
			}

			T Max()
			{
				return Queryable::Max<T>(_q);
			}

			generic<typename V> V Min(Lambda<Func<T, V>^>^ selector)
			{
				return Queryable::Min<T, V>(_q, selector->ToTypedLinq());
			}

			generic<typename V> V Max(Lambda<Func<T, V>^>^ selector)
			{
				return Queryable::Max<T, V>(_q, selector->ToTypedLinq());
			}

			int Sum(Lambda<System::Query::Func<T, int>^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			double Average(Lambda<System::Query::Func<T, int>^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}

			double Sum(Lambda<System::Query::Func<T, double>^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			double Average(Lambda<System::Query::Func<T, double>^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}

			Decimal Sum(Lambda<System::Query::Func<T, Decimal >^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			Decimal Average(Lambda<System::Query::Func<T, Decimal >^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}

			long long int Sum(Lambda<System::Query::Func<T, long long int>^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			double Average(Lambda<System::Query::Func<T, long long int>^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}

			Nullable<int> Sum(Lambda<System::Query::Func<T, Nullable<int>>^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			Nullable<double> Average(Lambda<System::Query::Func<T, Nullable<int>>^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}

			Nullable<double> Sum(Lambda<System::Query::Func<T, Nullable<double>>^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			Nullable<double> Average(Lambda<System::Query::Func<T, Nullable<double>>^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}

			Nullable<Decimal> Sum(Lambda<System::Query::Func<T, Nullable<Decimal> >^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			Nullable<Decimal> Average(Lambda<System::Query::Func<T, Nullable<Decimal> >^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}

			Nullable<long long int> Sum(Lambda<System::Query::Func<T, Nullable<long long int>>^>^ selector)
			{
				return System::Query::Queryable::Sum<T>(_q, selector->ToTypedLinq());
			}

			Nullable<double> Average(Lambda<System::Query::Func<T, Nullable<long long int>>^>^ selector)
			{
				return System::Query::Queryable::Average<T>(_q, selector->ToTypedLinq());
			}
		};
	}
}