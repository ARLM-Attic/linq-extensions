using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Xml.Linq;
using System.Data.Linq;
using System.Linq.Expressions;
using System.Reflection;

using EeekSoft.Functional;
using EeekSoft.Expressions;
using EeekSoft.Query;

using EeekSoft.LinqDemos;
using System.Drawing;
using System.Net;
using System.Threading;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace EeekSoft.LinqDemos
{
	delegate void Action();

	public class Unit
	{
		private Unit() {}
		static Unit()
		{
			Value = new Unit();
		}
		public static Unit Value { get; private set; }
	}

	static class AsyncExtensions
	{
		public static Async<WebResponse> GetResponseAsync(this WebRequest req)
		{
			return new Async<WebResponse>(req.BeginGetResponse, req.EndGetResponse);
		}

		public static Async<int> BeginReadAsync(this Stream stream, byte[] buffer, int offset, int count)
		{
			return new Async<int>(
				(callback, st) => stream.BeginRead(buffer, offset, count, callback, st), 
				stream.EndRead);
		}

		public static void Execute(this IEnumerable<IAsync> async)
		{
			AsyncExtensions.Run(async.GetEnumerator());
		}

		private static void Run(IEnumerator<IAsync> en)
		{
			if (!en.MoveNext()) return;
			en.Current.ExecuteStep
				(() => AsyncExtensions.Run(en));
		}
	}

	static class Async
	{
		public static Async<Unit> Parallel(IEnumerable<IAsync>[] operations)
		{
			return new Async<Unit>((cont) =>
				{
					bool[] completed = new bool[operations.Length];
					for (int i = 0; i < operations.Length; i++)
						ExecuteAndSet(operations[i], completed, i, cont).Execute();
				});
		}

		private static IEnumerable<IAsync> ExecuteAndSet(IEnumerable<IAsync> op, bool[] flags, int index, Action<Unit> cont)
		{
			foreach (IAsync async in op) yield return async;
			bool allSet = true;
			lock (flags)
			{
				flags[index] = true;
				foreach (bool b in flags) if (!b) { allSet = false; break; }
			}
			if (allSet) cont(Unit.Value);
		}
	}

	interface IAsync
	{
		void ExecuteStep(Action cont);
	}

	class Async<T> : IAsync
	{
		Action<Action<T>> func;
		T result;
		bool completed = false;

		public Async(Action<Action<T>> function)
		{
			this.func = function;
		}

		public Async(Func<AsyncCallback, object, IAsyncResult> begin, Func<IAsyncResult, T> end)
		{
			this.func = (cont) => begin(delegate(IAsyncResult res) { cont(end(res)); }, null);
		}

		public T Result
		{
			get
			{
				if (!completed) throw new Exception("Operation not completed, did you forgot 'yield return'?");
				return result;
			}
		}

		public void ExecuteStep(Action cont)
		{
			func((res) =>
				{
					result = res;
					completed = true;
					cont();
				});
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			/*SimpleExpansion();
			LinqToSqlExpandSimple();
			LinqToSqlExpandMultiple();

			OtherExtensions();
			FunctionalProgramming();

			ParametrizedQueries();
			QueryBuilder();*/

			LazyValues();
			//Asynchronous();
		}

		static Random rnd = new Random();

		static void LazyValues()
		{
			Application.Run(new FontForm());

			var calc1 = Lazy.New(() => {
					Console.WriteLine("Calculating #1");
					return 42;
				});

			var calc2 = Lazy.New(() => {
					Console.WriteLine("Calculating #2");
					return 43;
				});


			int res;
			res = ReturnRandomValue(calc1, calc2);
			Console.WriteLine("Result = {0}", res);
			res = ReturnRandomValue(calc1, calc2);
			Console.WriteLine("Result = {0}", res);
		}

		static int ReturnRandomValue(Lazy<int> a0, Lazy<int> a1)
		{
			if (rnd.Next(2) == 0)
				return a0.Value;
			else
				return a1.Value;
		}

		#region Asynchronous

		static bool running = true;

		static IEnumerable<IAsync> AsyncMethod(string url)
		{
			WebRequest req = HttpWebRequest.Create(url);
			Console.WriteLine("[{0}] starting", url);
			
			Async<WebResponse> response = req.GetResponseAsync();
			yield return response;

			Console.WriteLine("[{0}] got response", url);
			Stream resp = response.Result.GetResponseStream();

			MemoryStream ms = new MemoryStream();
			int read = -1;
			while (read != 0)
			{
				byte[] buffer = new byte[1024];
				Async<int> count = resp.BeginReadAsync(buffer, 0, 1024);
				yield return count;

				Console.WriteLine("[{0}] got data: {1}", url, count.Result);
				ms.Write(buffer, 0, count.Result);
				read = count.Result;
			}

			Regex reg = new Regex(@"<title[^>]*>(.*)</title[^>]*>");
			ms.Seek(0, SeekOrigin.Begin);
			string s = new StreamReader(ms).ReadToEnd();
			string title = reg.Match(s).Groups[1].Value;
			title = "".PadLeft((78 - title.Length) / 2) + 
				title + "".PadRight((78 - title.Length) / 2);
			Console.WriteLine("[{0}] completed\n{2}\n{1}\n{2}", 
				url, title, "".PadRight(79,'*'));
		}

		static IEnumerable<IAsync> DownloadAll()
		{
			var methods = Async.Parallel(new IEnumerable<IAsync>[] {
				AsyncMethod("http://www.microsoft.com"),
				AsyncMethod("http://www.google.com"),
				AsyncMethod("http://www.apple.com"),
				AsyncMethod("http://www.novell.com") });
			yield return methods;

			running = false;
			Console.WriteLine("Completed all!");
		}

		static void Asynchronous()
		{
			DownloadAll().Execute();

			int i = 0;
			while (running)
			{
				Console.WriteLine(i++);
				Thread.Sleep(500);
			}
			Console.ReadLine();
		}

		#endregion

		#region FunctionalProgramming

		private static void FunctionalProgramming()
		{
			Console.WriteLine("\n\n=== [ Functional programming ] ===");

			// Create a function that builds a range from 'min' to 'max'
			Func<int, int, Sequence<int>> range = null;
			range = (min, max) => {
				// if min == max then return an empty sequence
				if (max == min)
					return Sequence.Empty<int>();
			  // Otherwise create cell with value min and 
				// a tail built recursively from 'min + 1' to 'max'
				else
					return Sequence.Cons(min, range(min + 1, max)); };
			
			// Build a range from 0 to 10
			var nums = range(0, 10);

			// Create a function to add two numbers
			var add = Linq.Func((int a, int b) => a + b);
			// ..and fix first argument to create a function that adds 10 to a number
			var add10 = add.Curry(10);
			
			Console.WriteLine("Currying: add10(5) = {0}, add10(32) = {1}", add10(5), add10(32));

			// Using Fold to add all numbers in a sequence 
			Console.WriteLine("Foldl:    nums.Foldl(add, 0) = {0}", nums.FoldLeft(add, 0));
			
			// Using Fold to produce a string
			var strConcat = Linq.Func((string c, int it) => c + it.ToString() + ", ");
			Console.WriteLine("Foldl:    nums          = {0}", nums.FoldLeft(strConcat, ""));

			// Using Fold to reverse a list
			var revStep = Linq.Func((Sequence<int> c, int it) => Sequence.Cons(it, c));
			Console.WriteLine("Foldl:    reversed nums = {0}",
				nums.FoldLeft(revStep, Sequence.Empty<int>()).FoldLeft(strConcat, ""));

			// Function to recursively produce lazy sequence containing powers of two
			Func<int, Func<LazySequence<int>>> infN = null;
			// Build a function that when given an initial value 'n' returns a function that
			// builds lazy sequence starting from n - it creates cell containing 'n' with
			// recursive call to infN with an argument multiplied by two as a tail
			infN = (n) => (() => LazySequence.Cons(n, infN(n * 2)));
			var infList = infN(1)();
			Console.WriteLine("\nInfinite list (take 10) = {0}", 
				infList.Take(10).FoldLeft(strConcat, ""));
		}

		#endregion

		#region SimpleExpansion

		/// <summary>
		/// Simple demonstration of ExpandableExpression
		/// </summary>
		private static void SimpleExpansion()
		{
			Console.WriteLine("=== [ SimpleExpansion ] ===");

			// Declare expression 'calc' that will be used by other lambda expressions
			Expression<Func<int, int>> calc = i => i * 10;

			// Expression and Func that uses 'calc' expression
			// Invoke() is extension method from ExpressionExtensions class
			Expression<Func<int, int>> expr =
				i => calc.Expand(i) + 2;
			Func<int, int> func =
				i => calc.Expand(i) + 2;

			// Execute Func (calc is compiled at runtime)
			// Prints: 
			//   42
			Console.WriteLine("Call func: {0}", func(4));

			// Now expand the expression
			// Expand() is extension method from ExpressionExtensions class
			Expression<Func<int, int>> expanded = expr.Expand();

			// Print original and expand expression 
			// Prints:
			//	 Original: i => Add(i => Multiply(i, 10).Invoke(i), 2)
			//	 Expanded: i => Add(Multiply(i, 10), 2)
			// (as you can see invocation of lambda expression is replaced by its body)
			Console.WriteLine("Original: {0}", expr.ToString());
			Console.WriteLine("Expanded: {0}", expanded.ToString());

			// Compile and execute expanded expression
			// Prints:
			//   42
			Console.WriteLine("Compiled: {0}", expanded.Compile().Invoke(4));
		}

		#endregion
		#region LinqToSqlExpandSimple

		/// <summary>
		/// Advanced example that uses DLINQ for data access
		/// </summary>
		private static void LinqToSqlExpandSimple()
		{
			Console.WriteLine("\n\n=== [ LinqToSqlExpandSimple ] ===");
			NorthwindDataContext db = new NorthwindDataContext();
			
			// ORIGINAL VERSION
			// we want to extract the code that produces 'info' from the query so 
			// it can be reused by other queries (you may want to expose it as a 
			// property in some global class for example)
			var q_1 = 
				from c in db.Categories 
					let info = 
						new { 
							AveragePrice = 
								(from p in db.Products 
								 where p.CategoryID == c.CategoryID
								 select p).Average(p => p.UnitPrice),
							ExpensiveProduct = 
								(from p in db.Products 
								 where p.UnitPrice == (db.Products.Where
									(r => r.CategoryID == c.CategoryID).Max(r => r.UnitPrice))
								 select p.ProductName).First() }
					where info.AveragePrice > 20.0M
					select new { c.CategoryName, info.AveragePrice, info.ExpensiveProduct };

			// SOLUTION
			// Expression that will be used in multiple database queries takes 
			// Category from dabase and returns an anonymous type (if you want to 
			// expose it as property, you have to use named type)
			// (we're using Linq.Expr to build an expression tree, so we can
			// use 'var' to declare the expression tree variable)
			var selectInfo = Linq.Expr((Category c) =>
						new
						{
							AveragePrice =
								(from p in db.Products
								 where p.CategoryID == c.CategoryID
								 select p).Average(p => p.UnitPrice),
							ExpensiveProduct =
								(from p in db.Products
								 where p.UnitPrice == (db.Products.Where
									 (r => r.CategoryID == c.CategoryID).Max(r => r.UnitPrice))
								 select p.ProductName).First()
						});
			
			// To use expression in Query call it using Invoke method
			// and call extension method ToExpandable() on table
			var q = 
				from c in db.Categories.ToExpandable()
					let info = selectInfo.Expand(c)
					where info.AveragePrice > 20.0M
					select new { c.CategoryName, info.AveragePrice, info.ExpensiveProduct };

			// Print the results...
			foreach (var row in q)
				Console.WriteLine("* {0}\n  avg price: {1}, product: {2}",
					row.CategoryName, row.AveragePrice, row.ExpensiveProduct);

			// HOW DOES IT WORK?
			// If we write just 'where' with 'selectInfo' it will fail, because the
			// LINQ to SQL translator doesn't understand the 'Expand' method
			var q_2 = db.Categories.Where(c => selectInfo.Expand(c).AveragePrice > 20.0M);

			// To make it work we have to add 'ExpressionExtensions.Expand' explicitly
			// This is correct because expression is expanded before sending to LINQ to SQL
			// The wrapper created using 'ToExpandable' performs exactly this - it 
			// adds 'ExpressionExtension.Expand' to all clauses automatically.
			var q_3 = db.Categories.Where(
				ExpressionExtensions.Expand((Category c) => 
					selectInfo.Expand(c).AveragePrice > 20.0M));
		}

		#endregion
		#region LinqToSqlExpandMultiple

		private static void LinqToSqlExpandMultiple()
		{
			Console.WriteLine("\n\n=== [ LinqToSqlExpandMultiple ] ===");

			// Initialize DB connection (connection string is in the config file)
			NorthwindDataContext db = new NorthwindDataContext();

			// We will rise price of product when we have ten or less items in stock 
			Expression<Func<Product, bool>> risePrice =
				(r) => r.UnitsInStock < 10;

			// Defines lambda expression that calculates prcie (uses 'risePrice')
			// (value of vat variable is captured when expression is created)
			decimal vat = 1.19m;
			Expression<Func<Product, decimal?>> calcPrice =
				(p) => (risePrice.Expand(p) ? 3 : 1) * p.UnitPrice * vat;

			// Query..
			// Select products with higher price than 30 
			// (and of course return price of product)
			var q =
				from p in db.Products.ToExpandable()
				where calcPrice.Expand(p) > 30.0m
				select new
					{
						p.ProductName,
						p.UnitsInStock,
						p.UnitPrice,
						ShopPrice = calcPrice.Expand(p),
						ExtraPrice = risePrice.Expand(p)
					};

			// Print the results
			foreach (var row in q)
				Console.WriteLine("{0,-35} {2,-7:00.00}  {3,-7:00.00}  {1,-3} {4}",
					row.ProductName, row.UnitsInStock, row.UnitPrice, row.ShopPrice, row.ExtraPrice ? "!!!" : "");
		}

		#endregion

		#region Other extensions

		/// <summary>
		/// Demo of some other extensions to things that are (currently) missing in LINQ
		/// </summary>
		private static void OtherExtensions()
		{
			Console.WriteLine("\n\n=== [ Other Extensions ] ===");

			NorthwindDataContext db = new NorthwindDataContext();

			// Select products, that conain one of values from array in their name
			var q = from p in db.Products.ToExpandable()
							where p.ProductName.ContainsAny("Sir", "Chef")
							select new { p.ProductName };

			Console.WriteLine("ContainsAny [Sir,Chef]:");
			foreach (var row in q)
				Console.WriteLine("{0}", row.ProductName);

			// Select products, that conain all of values from array in their name
			var q2 = from p in db.Products.ToExpandable()
							 where p.ProductName.ContainsAll("Gu", "Ca")
							 select new { p.ProductName };

			Console.WriteLine("\nContainsAll [Gu,Ca]:");
			foreach (var row in q2)
				Console.WriteLine("{0}", row.ProductName);
		}

		#endregion
		#region ParametrizedQueries

		private static void ParametrizedQueries()
		{
			Console.WriteLine("\n\n=== [ Parametrized queries ] ===");
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
			var dict = new Dictionary<string, Expression<Func<Customer, string>>> 
				 { { "CompanyName", c => c.CompanyName },
					 { "Country",			c => c.Country },
					 { "ContactName", c => c.ContactName } };

			// Condition that always returns true
			var trueExpr = Linq.Expr((Customer c) => true);
			// Condition that always returns false
			var falseExpr = Linq.Expr((Customer c) => false);
			// Combine two functions using 'or' 
			var combineOr = Linq.Func
				((Expression<Func<Customer, bool>> f, Expression<Func<Customer, bool>> g) =>
					 Linq.Expr((Customer c) => f.Expand(c) || g.Expand(c)));
			// Combine two functions using 'and'
			var combineAnd = Linq.Func
				((Expression<Func<Customer, bool>> f, Expression<Func<Customer, bool>> g) =>
					Linq.Expr((Customer c) => f.Expand(c) && g.Expand(c)));

			// Generate expression..
			Console.Write("Do you want to build 'or' or 'and' query (enter 'or' or 'and')?\n> ");
			bool generateOr = Console.ReadLine().ToLower() == "or";
			var combinator = generateOr ? combineOr : combineAnd;
			var expr = generateOr ? falseExpr : trueExpr;
			foreach (var item in dict)
			{
				var propSelector = item.Value;
				Console.Write("Enter value for '{0}':\n> ", item.Key);
				var enteredVal = Console.ReadLine();
				var currentExpr = Linq.Expr((Customer c) => propSelector.Expand(c).IndexOf(enteredVal) != -1);
				expr = combinator(expr, currentExpr);
			}

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
