// EeekSoft.CLinq.Demo.cpp : main project file.

#include "../EeekSoft.CLinq.Includes/clinq.h"
#include "northwind.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Query;
using namespace System::Globalization;

using namespace EeekSoft::CLinq;

namespace EeekSoft { namespace CLinq { namespace Demo 
{
	/*****************************************************************************/
	/** Introduction to lambda expressions                                       */
	/*****************************************************************************/
	void LambdaDemos()
	{
		// Basic operations with strings
		Expr<int> var = Var<int>("x");
		Expr<int> expr = Expr<String^>("Hello world!").Substring(6).IndexOf("!") + var;
		Console::WriteLine(expr.ToLinq());

		// Declaring lambda expressions
		Lambda<Func<int, int>^>^ lambda = clq::fun(var, expr);
		Console::WriteLine(lambda->Compile()(1));

		// Lambda expression with two parameters
		Expr<int> x = Var<int>("x");
		Expr<int> y = Var<int>("y");
		Lambda<Func<int, int, int>^>^ lambda2 = clq::fun(x, y, x + y);
		Console::WriteLine(lambda2->ToLinq());
	}

	/*****************************************************************************/
	/** Supported mathematical operations                                        */
	/*****************************************************************************/
	void MathDemos()
	{
		// Ints and some doubles
		Expr<int> i = Var<int>("i");
		Lambda<Func<int,int>^>^ foo1 = clq::fun(i, 
			21 + Expr<Math^>::Max(clq::conv<int>(Expr<Math^>::Ceiling(33.3 + Expr<Math^>::Pow(clq::conv<double>(i), 1.5))), i * 2));
		Console::WriteLine("Expression: {0}\nfoo1(42) = {1}", foo1->ToLinq()->ToString(), foo1->Compile()(42));

		// Decimal
		Expr<Decimal> dc(Decimal::Parse("0.123412341234123412341234", CultureInfo::InvariantCulture));
		Expr<Decimal> dv = Var<Decimal>("dv");
		Lambda<Func<Decimal,Decimal>^>^ foo2 = clq::fun(dv, dv + dc);
		Console::WriteLine("\nExpression: {0}\nfoo2(0.8765...) = {1}", 
			foo2->ToLinq()->ToString(), foo2->Compile()(Decimal::Parse("0.876587658765876587658765", CultureInfo::InvariantCulture)));

		// Bytes, integers, longs
		Expr<unsigned char> bv1 = Var<unsigned char>("bv1"), bv2 = Var<unsigned char>("bv2");
		Lambda<Func<unsigned char,unsigned char,long long int>^>^ foo3 = clq::fun(bv1, bv2, 
				(clq::conv<long long int>(clq::conv<int>(bv1) << Expr<int>(8))) + clq::conv<long long int>(bv2));
		Console::WriteLine("\nExpression: {0}\nfoo3(255,255) = {1}", 
			foo3->ToLinq()->ToString(), foo3->Compile()(255, 255));

		// Floats, doubles, etc..
		Expr<float> fv = Var<float>("f");
		Expr<double> fc(1.2345678);
		Lambda<Func<float, float>^>^ foo4 = clq::fun(fv, 
			clq::conv<float>(
				Expr<Math^>::Sin(clq::conv<double>(fv * clq::conv<float>(Expr<Math^>::Cos(clq::conv<double>(fc)))))
					+ Expr<Math^>::Ceiling(Expr<Math^>::Pow(clq::conv<double>(fv), 2))) );
		Console::WriteLine("\nExpression: {0}\nfoo4(4.242) = {1}", 
			foo4->ToLinq()->ToString(), foo4->Compile()(4.242f));
	}

	/*****************************************************************************/
	/** Indirect member access                                                   */
	/*****************************************************************************/
	ref class DemoClass
	{
		int _number;

	public:
		DemoClass(int n) { _number = n; }

		property int Number 
		{
			int get() { return _number;  }
		}

		int AddNumber(int n)
		{
			return _number = _number + n;
		}

		static int Square(int number)
		{
			return number * number;
		}
	};

	void IndirectAccess()
	{
		// Using Prop and Invoke for calling methods/properties by name
		Expr<DemoClass^> var = Var<DemoClass^>("var");
		Lambda<Func<DemoClass^,int>^>^ foo = clq::fun(var, 
			var.Prop<int>("Number") + 
			var.Invoke<int>("AddNumber", Expr<int>(6)) + 
			Expr<DemoClass^>::InvokeStatic<int>("Square", Expr<int>(100) ) );

		// Test it..
		DemoClass^ dcs = gcnew DemoClass(15);
		int ret = foo->Compile()(dcs);

		Console::WriteLine("foo: {0}\nfoo(dcs) = {1}", foo->ToLinq(), ret);
	}

	/*****************************************************************************/
	/** Database and DLINQ demos                                                 */
	/*****************************************************************************/
	ref class CustomerInfo
	{
		String^ _id;
		String^ _name;

	public:
		// PropMap attributes map constructor parameters to properties
		// (used by LINQ)
		CustomerInfo([PropMap("ID")] String^ id, [PropMap("Name")] String^ name) 
		{ _id=id; _name=name; }
		CustomerInfo() 
		{ }

		property String^ ID { 
			String^ get() { return _id; }
			void set(String^ value) { _id = value; }
		}

		property String^ Name {
			String^ get() { return _name; }
			void set(String^ value) { _name = value; }
		}
	};

	void DatabaseDemos()
	{
		// Create database context
		NorthwindData db("Data Source=.;Initial Catalog=northwind;Integrated Security=True");

		// Count employees
		Console::WriteLine("Number of employees: {0}",
			db.QEmployees->Count());

		// Calculate average 'UnitPrice' value
		Expr<Products^> p = Var<Products^>("p");
		Nullable<Decimal> avgPrice = 
			db.QProducts->Average( clq::fun(p, p.UnitPrice) );
		Console::WriteLine("Average unit price: {0}", avgPrice);

		// Get first employee whose 'ReportsTo' column is NULL
		Expr<Employees^> e = Var<Employees^>("e");
		Employees^ boss = db.QEmployees->
			Where( clq::fun(e, e.ReportsTo == nullptr) )->First();
		Console::WriteLine("The boss: {0} {1}",
			boss->FirstName, boss->LastName);

		// .. one more 
		Expr<Customers^> cvar = Var<Customers^>("c");
		CQuery<CustomerInfo^>^ q = db.QCustomers
			->Where(clq::fun(cvar, cvar.Country.IndexOf("U") == 0))
			->Select(clq::fun(cvar, clq::newobj<CustomerInfo^>(
					cvar.CustomerID,
					cvar.ContactName + Expr<String^>(" from ") + cvar.Country)));

		// print SQL query and results
		Console::WriteLine("\nQuery:\n{0}\n\nResults:", q->Query->ToString());
		for each(CustomerInfo^ c in q->Query)
		{
			Console::WriteLine(" * {0},  {1}", c->ID, c->Name);
		}
	}

	/*****************************************************************************/
	/** Database and DLINQ demos (Joins, etc..)                                  */
	/*****************************************************************************/

	// Shortcuts for some complex types..
	typedef IEnumerable<Orders^> OrdersCollection;
	typedef Tuple<Customers^, OrdersCollection^> CustomerOrders;

	void AdvancedDatabaseDemos()
	{
		NorthwindData db("Data Source=.;Initial Catalog=northwind;Integrated Security=True");
		
		// Declare variables
		Expr<Customers^> c = Var<Customers^>("c");
		Expr<Orders^> o = Var<Orders^>("o");
		Expr<OrdersCollection^> orders = Var<OrdersCollection^>("orders");
		Expr<CustomerOrders^> co = Var<CustomerOrders^>("co");

		// The Query
		CQuery<String^>^ q = db.QCustomers
			// Group customers and their orders and 
			// produce collection of 'CustomerOrders'
			->GroupJoin(db.QOrders,
				clq::fun(c, c.CustomerID),
				clq::fun(o, o.CustomerID),
				clq::fun<Customers^, OrdersCollection^, CustomerOrders^>
					( c, orders, clq::newobj<CustomerOrders^>(c, orders) ))
			// Filter only customers with order shipped to USA 
			// Note: 'Second' is the collection with orders
			->Where( clq::fun(co, co.Second.Where( 
					clq::fun(o, o.ShipCountry == "USA" )).Count() > 0) )
			// Projection - string concatenation
			->Select( clq::fun(co, co.First.CompanyName + Expr<String^>(", #orders = ") + 
					Expr<Convert^>::ToString(co.Second.Count()) ) );

		Console::WriteLine("Query: {0}\n\nResults:", q->Query);
		for each(String^ s in q->Query)
			Console::WriteLine(s);
	}

	/*****************************************************************************/
	/** Database and DLINQ demos (GroupBy, etc..)                                */
	/*****************************************************************************/

	// Shortcut for tuple type
	typedef Tuple<Customers^, Orders^> CustomerOrder;

	void GroupByDbDemos()
	{
		NorthwindData db("Data Source=.;Initial Catalog=northwind;Integrated Security=True");
		
		// Declare variables
		Expr<Customers^> c = Var<Customers^>("c");
		Expr<Orders^> o = Var<Orders^>("o");
		Expr<CustomerOrder^> co = Var<CustomerOrder^>("co");
		Expr<IGrouping<String^, CustomerOrder^>^> cgr = Var<IGrouping<String^, CustomerOrder^>^>("cgr");

		// Join customers and orders and than perform group by
		CQuery<String^>^ q = db.QCustomers
			->Join(db.QOrders,
					clq::fun(c, c.CustomerID),
					clq::fun(o, o.CustomerID),
					clq::fun<Customers^, Orders^, CustomerOrder^> ( c, o, clq::newobj<CustomerOrder^>(c, o) ))
			->GroupBy( clq::fun(co, co.Second.ShipCountry) )
			->Select( clq::fun(cgr, cgr.Key + Expr<String^>(", #orders = ") + 
					Expr<Convert^>::ToString(cgr.Values.Count())  ));

		Console::WriteLine("Query: {0}\n\nResults:", q->Query);
		for each(String^ s in q->Query)
			Console::WriteLine(s);
	}
}}}
/*****************************************************************************/
using namespace EeekSoft::CLinq::Demo;

int main(array<System::String ^> ^args)
{
	/*LambdaDemos();
	MathDemos();
	IndirectAccess();
	DatabaseDemos();*/
	GroupByDbDemos();
	//AdvancedDbDemos();
	return 0;
}
