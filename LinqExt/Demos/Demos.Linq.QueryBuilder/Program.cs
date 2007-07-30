using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using EeekSoft.Query;
using EeekSoft.Functional;
using EeekSoft.Expressions;
using EeekSoft.LinqDemos;
using System.Linq.Expressions;

namespace Demos.QueryBuilder
{
	// Type abbreviation representing a condition
	// (lambda expression testing if customer matches specified criteria)
	using CustomerCondition =
		System.Linq.Expressions.Expression
			<System.Func<EeekSoft.LinqDemos.Customer, bool>>;

	// Type abbreviation representing a lambda expression that
	// reads a property of a customer type
	using CustomerPropSelector =
		System.Linq.Expressions.Expression
			<System.Func<EeekSoft.LinqDemos.Customer, string>>;

	// Combinator for conditions - takes two conditions
	// and returns a new one
	using CustomerConditionCombinator =
		System.Func
			<System.Linq.Expressions.Expression<System.Func<EeekSoft.LinqDemos.Customer, bool>>,
			 System.Linq.Expressions.Expression<System.Func<EeekSoft.LinqDemos.Customer, bool>>,
			 System.Linq.Expressions.Expression<System.Func<EeekSoft.LinqDemos.Customer, bool>>>;

	class Program
	{
		static void Main(string[] args)
		{
			ParametrizedQueries();
			QueryBuilder();
		}

		#region ParametrizedQueries

		private static void ParametrizedQueries()
		{
			Console.WriteLine("=== [ Parametrized queries ] ===");
			NorthwindDataContext db = new NorthwindDataContext();

			// Build a parametrized query - this is in fact just a 
			// lamdba function (created using Linq.Func) that returns a query
			// when it gets the function ('selector') and a value ('val')
			var queryBuilder = Linq.Func(
				(string val, Expression<Func<Customer, string>> selector) =>
					from c in db.Customers.ToExpandable()
					where selector.Expand(c).IndexOf(val) != -1
					select c);

			// Dictionary that returns a lambda expression that reads
			// the property specified by a string (key)
			var dict = new Dictionary<string, Expression<Func<Customer, string>>> 
				 { { "CompanyName", c => c.CompanyName },
					 { "Country",			c => c.Country },
					 { "ContactName", c => c.ContactName } };

			// Get the input from the user
			Console.Write("Filter - field name (CompanyName, ContactName, Country):\n> ");
			string field = Console.ReadLine();
			Console.Write("Filter - value:\n> ");
			string value = Console.ReadLine();

			// Build the query using query builder
			var q = queryBuilder(value, dict[field]);

			// Execute & print the results
			foreach (var c in q)
				Console.WriteLine("{0,-30}{1,-30}{2}", c.CompanyName, c.ContactName, c.Country);
		}

		#endregion
		#region QueryBuilder

		private static void QueryBuilder()
		{
			Console.WriteLine("\n\n=== [ Query builder ] ===");
			NorthwindDataContext db = new NorthwindDataContext();

			// Dictionary that returns a lambda expression that reads
			// the property specified by a string (key)
			var dict = new Dictionary<string, CustomerPropSelector> 
				 { { "CompanyName", c => c.CompanyName },
					 { "Country",			c => c.Country },
					 { "ContactName", c => c.ContactName } };

			// Condition that always returns true
			CustomerCondition trueCond = c => true;
			// Condition that always returns false
			CustomerCondition falseCond = c => false;

			// Combine two functions using 'or' 
			CustomerConditionCombinator combineOr =
				(f, g) => (c) => f.Expand(c) || g.Expand(c);

			// Combine two functions using 'and'
			CustomerConditionCombinator combineAnd =
				(f, g) => (c) => f.Expand(c) && g.Expand(c);

			// Generate expression..
			Console.Write("Do you want to build 'or' or 'and' query (enter 'or' or 'and')?\n> ");
			bool generateOr = Console.ReadLine().ToLower() == "or";

			/* EXAMPLE			
			CustomerCondition isUk = (c) => c.Country == "UK";
			CustomerCondition isSeattle = (c) => c.City == "Seattle";
			CustomerCondition expr = combineOr(isUk, isSeattle);
			*/

			/* ALTERNATIVE #1: Using 'foreach'
			
			// Select the combinator and initial condition
			CustomerConditionCombinator combinator = 
				generateOr ? combineOr : combineAnd;
			CustomerCondition expr = 
				generateOr ? falseCond : trueCond;
			  
			// Loop over all properties in the dictionary  
			foreach (var item in dict)
			{
				// Read the value from the user
				Console.Write("Enter value for '{0}':\n> ", item.Key);
				string enteredVal = Console.ReadLine();
				CustomerPropSelector propSelector = item.Value;
			  
				// Build a condition testing whether entered value is a substring
				CustomerCondition currentCond = (c) => 
					propSelector.Expand(c).IndexOf(enteredVal) != -1;
			    
				// Finally, combine expressions using the combinator
				expr = combinator(expr, currentCond);
			}
			*/


			// ALTERNATIVE #2: Using 'Fold'
			CustomerConditionCombinator combinator =
				generateOr ? combineOr : combineAnd;

			// Build expression using the 'Fold' aggregate operator
			var expr = dict.Fold((e, item) => {
					// Read the value from the user
					Console.Write("Enter value for '{0}':\n> ", item.Key);
					string enteredVal = Console.ReadLine();
					CustomerPropSelector propSelector = item.Value;

					// Build a condition testing whether entered value is a substring
					CustomerCondition currentCond = (c) =>
						propSelector.Expand(c).IndexOf(enteredVal) != -1;

					// Finally, return the combined expression
					return combinator(e, currentCond);
				}, generateOr ? falseCond : trueCond);


			// Now, we can build a query using the generated 'expr'
			var q =
				from c in db.Customers.ToExpandable()
				where expr.Expand(c)
				select c;

			// Execute & print the results
			foreach (var c in q)
				Console.WriteLine("{0,-30}{1,-30}{2}", c.CompanyName, c.ContactName, c.Country);
		}

		#endregion
	}
}
