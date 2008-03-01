using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Xml.Linq;
using System.Data.Linq;
using System.Linq.Expressions;
using System.Reflection;
using System.Drawing;
using System.Net;
using System.Threading;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows.Forms;

using EeekSoft.Functional;
using EeekSoft.Expressions;
using EeekSoft.Query;
using EeekSoft.LinqDemos;
using EeekSoft.Asynchronous;

namespace EeekSoft.LinqDemos
{
	#region Expressions - Usings
	
	using CustomerCondition =
		System.Linq.Expressions.Expression
			<System.Func<EeekSoft.LinqDemos.Customer, bool>>;

	using CustomerPropSelector =
		System.Linq.Expressions.Expression
			<System.Func<EeekSoft.LinqDemos.Customer, string>>;

	using CustomerConditionCombinator =
		System.Func
			<System.Linq.Expressions.Expression<System.Func<EeekSoft.LinqDemos.Customer, bool>>,
			 System.Linq.Expressions.Expression<System.Func<EeekSoft.LinqDemos.Customer, bool>>,
			 System.Linq.Expressions.Expression<System.Func<EeekSoft.LinqDemos.Customer, bool>>>;

	#endregion

	class Program
	{
		#region Statements & Monads (Just experiments, ignore this :-) )

		class Attempt<T> 
		{
			private bool hasVal;
			private T value;

			private Attempt(T v)
			{
				value = v;
				hasVal = true;
			}

			private Attempt()
			{
				hasVal = false;
			}

			public Attempt<R> Bind<R>(Func<T,Attempt<R>> func) 
			{
				Attempt<R> ret;
				if (hasVal)
					ret = func(value);
				else
					ret = new Attempt<R>();
				return ret;
			}

			public static Attempt<T> Fail
			{
				get { return new Attempt<T>(); }
			}

			public static Attempt<T> Success(T n)
			{
				return new Attempt<T>(n);
			}

			public bool HasValue
			{
				get { return hasVal; }
			}

			public T Value
			{
				get
				{
					if (!hasVal) throw new InvalidOperationException();
					return value;
				}
			}
		}

		static Attempt<int> TrySmall(int n)
		{
			if (n > 100)
				return Attempt<int>.Fail;
			else
				return Attempt<int>.Success(n);
		}

		static Attempt<int> AddSmall(int n, int m)
		{
			return TrySmall(n + m);
		}

		static void Monads()
		{
			Attempt<int> n;
			
			n = Attempt<int>.Success(42);
			n = n.Bind(m => TrySmall(m + 10));
			Console.WriteLine(n.HasValue ? n.Value.ToString() : "None");

			n = n.Bind(m => AddSmall(m, 10));
			Console.WriteLine(n.HasValue ? n.Value.ToString() : "None");

			n = n.Bind(m => AddSmall(m, 40));
			Console.WriteLine(n.HasValue ? n.Value.ToString() : "None");

			n = n.Bind(m => AddSmall(m, 40));
			Console.WriteLine(n.HasValue ? n.Value.ToString() : "None");


			n = Attempt<int>.Success(0);
			n = n.Bind(m1 => {
				int r1 = Int32.Parse(Console.ReadLine());
				return AddSmall(m1, r1).Bind(m2 =>
				{
					int r2 = Int32.Parse(Console.ReadLine());
					return AddSmall(m2, r2).Bind(m3 =>
					{
						int r3 = Int32.Parse(Console.ReadLine());
						return AddSmall(m3, r3).Bind(m4 =>
						{
							return Attempt<int>.Success(m4);
						});
					});
				});
			});
			Console.WriteLine("Finished: {0}", n.HasValue ? n.Value.ToString() : "Too much!");
		}

		/*************************************************************************/

		class Var
		{
		}

		class Var<T> : Var
		{
			internal Var(string name) { Name = name; }
			internal string Name { get; private set; }
			public T Value
			{ get { throw new NotImplementedException(); } }  
		}

		abstract class Statement
		{
			public static VarStatement<T> VarStatement<T>(Var<T> var, Expression<Func<T>> init)
			{
				return new VarStatement<T>(var, init);
			}

			public static ExpressionStatement ExpressionStatement(Expression<Action> expr)
			{
				return new ExpressionStatement(expr);
			}
		}

		class ExpressionStatement : Statement
		{
			public ExpressionStatement(Expression<Action> expr)
			{ Expression = expr; }

			public override string ToString()
			{
				return String.Format("{0};", Expression.Body.ToString());
			}

			public Expression<Action> Expression { get; private set; }
		}

		class VarStatement<T> : Statement
		{
			public VarStatement(Var<T> var, Expression<Func<T>> init) 
			{ Variable = var; Initialization = init; }

			public override string ToString()
			{
				return String.Format("var {0} = {1};", Variable.Name, Initialization.Body.ToString());
			}

			public Var<T> Variable { get; private set; }
			public Expression<Func<T>> Initialization { get; private set; }
		}

		class Function : IDisposable
		{
			int varIndex = 0;
			List<Statement> statements;
			string name;

			public Function(string name, params Var[] arguments)
			{
				this.name = name;
				this.statements = new List<Statement>();
			}

			public Var<T> Var<T>(Expression<Func<T>> f)
			{
				var v = new Var<T>("__v" + (varIndex++).ToString());
				statements.Add(Statement.VarStatement(v, f));
				return v;
			}

			public void Do(Expression<Action> f)
			{
				statements.Add(Statement.ExpressionStatement(f));
			}

			void IDisposable.Dispose()
			{
				foreach (Statement s in statements)
					Console.WriteLine(s.ToString());
			}
		}

		private static void Statements()
		{
			var arg = new Var<int>("arg");
			using (var c = new Function("Test", arg))
			{
				var n = c.Var(() => 20 + arg.Value);
				c.Do(()          => Console.WriteLine(n.Value));
			}
		}

		#endregion

		static void Main(string[] args)
		{
			//Statements();
			//Monads();

			/*SimpleExpansion();
			LinqToSqlExpandSimple();
			LinqToSqlExpandMultiple();

			OtherExtensions();
			FunctionalProgramming();*/

			//ParametrizedQueries();
			//QueryBuilder();
			DynamicQueryBuilder();

			//Asynchronous();
		}

		#region Asynchronous

		static void PrintTitleSync(string url)
		{
			WebRequest req = HttpWebRequest.Create(url);
			req.BeginGetResponse((ar) => {
				WebResponse response = req.EndGetResponse(ar);
				Stream resp = response.GetResponseStream();

				string html;
				using (var sr = new StreamReader(resp))
					html = sr.ReadToEnd();

				Regex reg = new Regex(@"&lt;title[^&gt;]*&gt;(.*)&lt;/title[^&gt;]*&gt;");
				string title = reg.Match(html).Groups[1].Value;
				Console.WriteLine("{0}: {1}", url, title);
			}, null);
		}

		static IEnumerable<IAsync> AsyncMethod(string url)
		{
			WebRequest req = HttpWebRequest.Create(url);
			Console.WriteLine("[{0}] starting", url);

			Async<WebResponse> response = req.GetResponseAsync();
			yield return response;

			Console.WriteLine("[{0}] got response", url);
			Stream resp = response.Result.GetResponseStream();

			Async<string> html = resp.ReadToEndAsync().ExecuteAsync<string>();
			yield return html;

			Regex reg = new Regex(@"<title[^>]*>(.*)</title[^>]*>");
			string title = reg.Match(html.Result).Groups[1].Value;
			title = "".PadLeft((78 - title.Length) / 2) +
				title + "".PadRight((78 - title.Length) / 2);
			Console.WriteLine("[{0}] completed\n{2}\n{1}\n{2}",
				url, title, "".PadRight(79, '*'));
		}

		static IEnumerable<IAsync> DownloadAll()
		{
			var methods = Async.Parallel(
				AsyncMethod("http://www.microsoft.com"),
				AsyncMethod("http://www.google.com"),
				AsyncMethod("http://www.apple.com"),
				AsyncMethod("http://www.novell.com") );
			yield return methods;

			Console.WriteLine("Completed all!");
		}

		static void Asynchronous()
		{
			DownloadAll().ExecuteAndWait();
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
		  Console.WriteLine("Foldl:    nums.Foldl(add, 0) = {0}", nums.Fold(add, 0));
			
		  // Using Fold to produce a string
		  var strConcat = Linq.Func((string c, int it) => c + it.ToString() + ", ");
		  Console.WriteLine("Foldl:    nums          = {0}", nums.Fold(strConcat, ""));

		  // Using Fold to reverse a list
		  var revStep = Linq.Func((Sequence<int> c, int it) => Sequence.Cons(it, c));
		  Console.WriteLine("Foldl:    reversed nums = {0}",
		    nums.Fold(revStep, Sequence.Empty<int>()).Fold(strConcat, ""));

		  // Function to recursively produce lazy sequence containing powers of two
		  Func<int, Func<LazySequence<int>>> infN = null;
		  // Build a function that when given an initial value 'n' returns a function that
		  // builds lazy sequence starting from n - it creates cell containing 'n' with
		  // recursive call to infN with an argument multiplied by two as a tail
		  infN = (n) => (() => LazySequence.Cons(n, infN(n * 2)));
		  var infList = infN(1)();
		  Console.WriteLine("\nInfinite list (take 10) = {0}", 
		    infList.Take(10).Fold(strConcat, ""));
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
		  Expression<Func<int, int>> expanded = expr.ExpandExpr();

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
		    ExpressionExtensions.ExpandExpr((Category c) => 
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
		  var dict = new Dictionary<string, CustomerPropSelector> 
		     { { "CompanyName", c => c.CompanyName },
		       { "Country",			c => c.Country },
		       { "ContactName", c => c.ContactName } };

		  // Condition that always returns true
		  CustomerCondition trueCond = (_) => true;
		  // Condition that always returns false
		  CustomerCondition falseCond = (_) => false;
			
		  // Combine two functions using 'or' 
		  CustomerConditionCombinator combineOr = 
		    (f, g) => (c) => f.Expand(c) || g.Expand(c);
			
		  // Combine two functions using 'and'
		  CustomerConditionCombinator combineAnd =
		    (f, g) => (c) => f.Expand(c) && g.Expand(c);

		  // Generate expression..
		  Console.Write("Do you want to build 'or' or 'and' query (enter 'or' or 'and')?\n> ");
		  bool generateOr = Console.ReadLine().ToLower() == "or";
		  
			/*
		  var combinator = generateOr ? combineOr : combineAnd;
		  var expr = generateOr ? falseCond : trueCond;
		  foreach (var item in dict)
		  {
		    var propSelector = item.Value;
		    Console.Write("Enter value for '{0}':\n> ", item.Key);
		    var enteredVal = Console.ReadLine();
		    var currentCond = Linq.Expr((Customer c) => propSelector.Expand(c).IndexOf(enteredVal) != -1);
		    expr = combinator(expr, currentCond);
		  }
		  */

		  var combinator = generateOr ? combineOr : combineAnd;
		  var expr = dict.Fold((e, item) => {
		      var propSelector = item.Value;
		      Console.Write("Enter value for '{0}':\n> ", item.Key);
		      var enteredVal = Console.ReadLine();
		      CustomerCondition currentCond = (c) => propSelector.Expand(c).IndexOf(enteredVal) != -1;
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

		#region QueryBuilder Generic

		// Base class that represents any selector for given table
		abstract class GenericSelector<TTable>
		{
			// Not type-safe version of the condition (because the property value is 
			// passed as an object), but it can be used if you need to store multiple
			// selectors in a collection (e.g. all properties for a specified table).
			public abstract Expression<Func<TTable, bool>> If(Expression<Func<object, bool>> cond);

			// This allows us to dynamically test what is the type of selector 
			// (e.g. when we need to ask user for a value of this type)
			public abstract Type PropertyType { get; }
		}

		// Represents a piece of code/expression that selects a property value 
		// (of type TPropType) from a database table (of type TTable)
		class GenericSelector<TTable, TPropType> : GenericSelector<TTable>
		{
			Expression<Func<TTable, TPropType>> _selector;

			public GenericSelector(Expression<Func<TTable, TPropType>> selector)
			{
				_selector = selector;
			}

			// Creates a condition that tests whether specified value selected
			// using GenericSelector matches the specified condition
			public Expression<Func<TTable,bool>> If(Expression<Func<TPropType, bool>> cond)
			{
				return (t) => cond.Expand(_selector.Expand(t));
			}

			public override Expression<Func<TTable, bool>> If(Expression<Func<object, bool>> cond)
			{
				return If((v) => cond.Expand(v));
			}

			public override Type PropertyType { get { return typeof(TPropType); } }
		}

		private static void DynamicQueryBuilder()
		{
			Console.WriteLine("\n\n=== [ Dynamic Query builder ] ===");
			NorthwindDataContext db = new NorthwindDataContext();

			// these have to be built statically at design time, however it
			// is possible to place them in collections (etc.) similarly to the
			// previous example
			var selCategory = new GenericSelector<Category, string>(c => c.CategoryName);
			var selPrice = new GenericSelector<Product, decimal?>(p => p.UnitPrice);

			
			// ----------
			// EXAMPLE #1: Combine some conditions of different types from different tables

			// build some conditions 
			var e1 = selCategory.If(s => s == "Beverages");
			var e2 = selPrice.If(p => p >= 15M);

			// combine the conditions
			var expr = Linq.Expr((Category c, Product p) => e1.Expand(c) && e2.Expand(p));
			
			// run the query
			var q =
				from c in db.Categories.ToExpandable()
				from p in c.Products
				where expr.Expand(c, p)
				select p;

			// Execute & print the results
			foreach (var p in q)
				Console.WriteLine("{0,-30}{1,-30}", p.ProductName, p.UnitPrice);

			// ----------
			// EXAMPLE #2: Using GenericSelector<TTable> base class...
			Console.WriteLine("\nExample #2 (various conditions combined using OR):");

			var conds = new Dictionary<string, GenericSelector<Product>> { 
				{ "Product name", new GenericSelector<Product, string>(p => p.ProductName) },
				{ "Unit price", new GenericSelector<Product, decimal?>(p => p.UnitPrice) } };
			
			var trueCond = Linq.Expr((Product _) => false);
			var expr2 = conds.Aggregate(trueCond, (e, item) =>
			{
				Console.Write("Enter value for '{0}': ", item.Key);
				string val = Console.ReadLine();

				// This needs to be replaced with some more complex method for parsing user input
				// - it needs to support various types that user may input when building the condition
				Expression<Func<Product, bool>> newExpr;
				if (item.Value.PropertyType == typeof(string)) 
					newExpr = item.Value.If(o => (string)o == val);
				else if (item.Value.PropertyType == typeof(decimal?)) 
					newExpr = item.Value.If(o => (decimal?)o >= Decimal.Parse(val));
				else throw new NotSupportedException();

				return Linq.Expr((Product p) => e.Expand(p) || newExpr.Expand(p));
			});

			// run the query
			var q2 =
				from p in db.Products.ToExpandable()
				where expr2.Expand(p)
				select p;

			// Execute & print the results
			foreach (var p in q2)
				Console.WriteLine("{0,-30}{1,-30}", p.ProductName, p.UnitPrice);

		}

		#endregion
	}
}
