#define DEC_PROPERTY_CACHE(otype, name, sname) \
	static System::Reflection::PropertyInfo^ _ ## name; \
	static property System::Reflection::PropertyInfo^ Property_ ## name { System::Reflection::PropertyInfo^ get() { if (_ ## name == nullptr) _ ## name = (otype::typeid)->GetProperty(sname); return _ ## name; } }

using namespace EeekSoft::CLinq;
namespace EeekSoft { namespace CLinq { namespace Demo { 
    ref class Orders;
    ref class Products;
    ref class Order_Details;
    ref class CustomerCustomerDemo;
    ref class CustomerDemographics;
    ref class Region;
    ref class Territories;
    ref class EmployeeTerritories;
    ref class Employees;
    ref class Categories;
    ref class Customers;
    ref class Shippers;
    ref class Suppliers;
    
    ref class NorthwindData : System::Data::DLinq::DataContext
    {
    public:
      System::Data::DLinq::Table<Orders^>^ Orders;
      System::Data::DLinq::Table<Products^>^ Products;
      System::Data::DLinq::Table<Order_Details^>^ Order_Details;
      System::Data::DLinq::Table<CustomerCustomerDemo^>^ CustomerCustomerDemo;
      System::Data::DLinq::Table<CustomerDemographics^>^ CustomerDemographics;
      System::Data::DLinq::Table<Region^>^ Region;
      System::Data::DLinq::Table<Territories^>^ Territories;
      System::Data::DLinq::Table<EmployeeTerritories^>^ EmployeeTerritories;
      System::Data::DLinq::Table<Employees^>^ Employees;
      System::Data::DLinq::Table<Categories^>^ Categories;
      System::Data::DLinq::Table<Customers^>^ Customers;
      System::Data::DLinq::Table<Shippers^>^ Shippers;
      System::Data::DLinq::Table<Suppliers^>^ Suppliers;
      
      property CQuery<EeekSoft::CLinq::Demo::Orders^>^ QOrders
      {
        CQuery<EeekSoft::CLinq::Demo::Orders^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Orders^>(Orders);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Products^>^ QProducts
      {
        CQuery<EeekSoft::CLinq::Demo::Products^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Products^>(Products);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Order_Details^>^ QOrder_Details
      {
        CQuery<EeekSoft::CLinq::Demo::Order_Details^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Order_Details^>(Order_Details);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::CustomerCustomerDemo^>^ QCustomerCustomerDemo
      {
        CQuery<EeekSoft::CLinq::Demo::CustomerCustomerDemo^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::CustomerCustomerDemo^>(CustomerCustomerDemo);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::CustomerDemographics^>^ QCustomerDemographics
      {
        CQuery<EeekSoft::CLinq::Demo::CustomerDemographics^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::CustomerDemographics^>(CustomerDemographics);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Region^>^ QRegion
      {
        CQuery<EeekSoft::CLinq::Demo::Region^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Region^>(Region);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Territories^>^ QTerritories
      {
        CQuery<EeekSoft::CLinq::Demo::Territories^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Territories^>(Territories);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::EmployeeTerritories^>^ QEmployeeTerritories
      {
        CQuery<EeekSoft::CLinq::Demo::EmployeeTerritories^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::EmployeeTerritories^>(EmployeeTerritories);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Employees^>^ QEmployees
      {
        CQuery<EeekSoft::CLinq::Demo::Employees^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Employees^>(Employees);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Categories^>^ QCategories
      {
        CQuery<EeekSoft::CLinq::Demo::Categories^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Categories^>(Categories);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Customers^>^ QCustomers
      {
        CQuery<EeekSoft::CLinq::Demo::Customers^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Customers^>(Customers);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Shippers^>^ QShippers
      {
        CQuery<EeekSoft::CLinq::Demo::Shippers^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Shippers^>(Shippers);
        }
      };
    
      property CQuery<EeekSoft::CLinq::Demo::Suppliers^>^ QSuppliers
      {
        CQuery<EeekSoft::CLinq::Demo::Suppliers^>^ get() 
        { 
          return gcnew CQuery<EeekSoft::CLinq::Demo::Suppliers^>(Suppliers);
        }
      };
    
    
    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
    NorthwindData(System::String^ connection) 
      : System::Data::DLinq::DataContext(connection)
    {
    }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
    NorthwindData(System::Data::IDbConnection^ connection) 
      : System::Data::DLinq::DataContext(connection)
    {
    }
  };
} } } 

using namespace EeekSoft::CLinq::Demo;

namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Orders")]
  ref class Orders
  {
  private:

    int _OrderID;
    System::String^ _CustomerID;
    System::Nullable<int> _EmployeeID;
    System::Nullable<System::DateTime> _OrderDate;
    System::Nullable<System::DateTime> _RequiredDate;
    System::Nullable<System::DateTime> _ShippedDate;
    System::Nullable<int> _ShipVia;
    System::Nullable<System::Decimal> _Freight;
    System::String^ _ShipName;
    System::String^ _ShipAddress;
    System::String^ _ShipCity;
    System::String^ _ShipRegion;
    System::String^ _ShipPostalCode;
    System::String^ _ShipCountry;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "OrderID", Storage = "_OrderID", DBType = "Int NOT NULL IDENTITY", Id = true, AutoGen = true)]
	  virtual property int OrderID
	  {
		  int get() { return this->_OrderID; }
		  void set(int value) 
      {
        if ((this->_OrderID != value))
        {
				  this->OnPropertyChanging("OrderID");
				  this->_OrderID = value;
				  this->OnPropertyChanged("OrderID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CustomerID", Storage = "_CustomerID", DBType = "NChar(5)")]
	  virtual property System::String^ CustomerID
	  {
		  System::String^ get() { return this->_CustomerID; }
		  void set(System::String^ value) 
      {
        if ((this->_CustomerID != value))
        {
				  this->OnPropertyChanging("CustomerID");
				  this->_CustomerID = value;
				  this->OnPropertyChanged("CustomerID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "EmployeeID", Storage = "_EmployeeID", DBType = "Int")]
	  virtual property System::Nullable<int> EmployeeID
	  {
		  System::Nullable<int> get() { return this->_EmployeeID; }
		  void set(System::Nullable<int> value) 
      {
        if ((this->_EmployeeID.HasValue != value.HasValue) || (this->_EmployeeID.HasValue && (this->_EmployeeID.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("EmployeeID");
				  this->_EmployeeID = value;
				  this->OnPropertyChanged("EmployeeID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "OrderDate", Storage = "_OrderDate", DBType = "DateTime")]
	  virtual property System::Nullable<System::DateTime> OrderDate
	  {
		  System::Nullable<System::DateTime> get() { return this->_OrderDate; }
		  void set(System::Nullable<System::DateTime> value) 
      {
        if ((this->_OrderDate.HasValue != value.HasValue) || (this->_OrderDate.HasValue && (this->_OrderDate.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("OrderDate");
				  this->_OrderDate = value;
				  this->OnPropertyChanged("OrderDate");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "RequiredDate", Storage = "_RequiredDate", DBType = "DateTime")]
	  virtual property System::Nullable<System::DateTime> RequiredDate
	  {
		  System::Nullable<System::DateTime> get() { return this->_RequiredDate; }
		  void set(System::Nullable<System::DateTime> value) 
      {
        if ((this->_RequiredDate.HasValue != value.HasValue) || (this->_RequiredDate.HasValue && (this->_RequiredDate.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("RequiredDate");
				  this->_RequiredDate = value;
				  this->OnPropertyChanged("RequiredDate");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShippedDate", Storage = "_ShippedDate", DBType = "DateTime")]
	  virtual property System::Nullable<System::DateTime> ShippedDate
	  {
		  System::Nullable<System::DateTime> get() { return this->_ShippedDate; }
		  void set(System::Nullable<System::DateTime> value) 
      {
        if ((this->_ShippedDate.HasValue != value.HasValue) || (this->_ShippedDate.HasValue && (this->_ShippedDate.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("ShippedDate");
				  this->_ShippedDate = value;
				  this->OnPropertyChanged("ShippedDate");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipVia", Storage = "_ShipVia", DBType = "Int")]
	  virtual property System::Nullable<int> ShipVia
	  {
		  System::Nullable<int> get() { return this->_ShipVia; }
		  void set(System::Nullable<int> value) 
      {
        if ((this->_ShipVia.HasValue != value.HasValue) || (this->_ShipVia.HasValue && (this->_ShipVia.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("ShipVia");
				  this->_ShipVia = value;
				  this->OnPropertyChanged("ShipVia");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Freight", Storage = "_Freight", DBType = "Money")]
	  virtual property System::Nullable<System::Decimal> Freight
	  {
		  System::Nullable<System::Decimal> get() { return this->_Freight; }
		  void set(System::Nullable<System::Decimal> value) 
      {
        if ((this->_Freight.HasValue != value.HasValue) || (this->_Freight.HasValue && (this->_Freight.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("Freight");
				  this->_Freight = value;
				  this->OnPropertyChanged("Freight");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipName", Storage = "_ShipName", DBType = "NVarChar(40)")]
	  virtual property System::String^ ShipName
	  {
		  System::String^ get() { return this->_ShipName; }
		  void set(System::String^ value) 
      {
        if ((this->_ShipName != value))
        {
				  this->OnPropertyChanging("ShipName");
				  this->_ShipName = value;
				  this->OnPropertyChanged("ShipName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipAddress", Storage = "_ShipAddress", DBType = "NVarChar(60)")]
	  virtual property System::String^ ShipAddress
	  {
		  System::String^ get() { return this->_ShipAddress; }
		  void set(System::String^ value) 
      {
        if ((this->_ShipAddress != value))
        {
				  this->OnPropertyChanging("ShipAddress");
				  this->_ShipAddress = value;
				  this->OnPropertyChanged("ShipAddress");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipCity", Storage = "_ShipCity", DBType = "NVarChar(15)")]
	  virtual property System::String^ ShipCity
	  {
		  System::String^ get() { return this->_ShipCity; }
		  void set(System::String^ value) 
      {
        if ((this->_ShipCity != value))
        {
				  this->OnPropertyChanging("ShipCity");
				  this->_ShipCity = value;
				  this->OnPropertyChanged("ShipCity");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipRegion", Storage = "_ShipRegion", DBType = "NVarChar(15)")]
	  virtual property System::String^ ShipRegion
	  {
		  System::String^ get() { return this->_ShipRegion; }
		  void set(System::String^ value) 
      {
        if ((this->_ShipRegion != value))
        {
				  this->OnPropertyChanging("ShipRegion");
				  this->_ShipRegion = value;
				  this->OnPropertyChanged("ShipRegion");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipPostalCode", Storage = "_ShipPostalCode", DBType = "NVarChar(10)")]
	  virtual property System::String^ ShipPostalCode
	  {
		  System::String^ get() { return this->_ShipPostalCode; }
		  void set(System::String^ value) 
      {
        if ((this->_ShipPostalCode != value))
        {
				  this->OnPropertyChanging("ShipPostalCode");
				  this->_ShipPostalCode = value;
				  this->OnPropertyChanged("ShipPostalCode");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipCountry", Storage = "_ShipCountry", DBType = "NVarChar(15)")]
	  virtual property System::String^ ShipCountry
	  {
		  System::String^ get() { return this->_ShipCountry; }
		  void set(System::String^ value) 
      {
        if ((this->_ShipCountry != value))
        {
				  this->OnPropertyChanging("ShipCountry");
				  this->_ShipCountry = value;
				  this->OnPropertyChanged("ShipCountry");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Orders()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Orders^> : ExpressionWrapper<Orders^>
  {
  private:

    DEC_PROPERTY_CACHE(Orders, OrderID, "OrderID")
    DEC_PROPERTY_CACHE(Orders, CustomerID, "CustomerID")
    DEC_PROPERTY_CACHE(Orders, EmployeeID, "EmployeeID")
    DEC_PROPERTY_CACHE(Orders, OrderDate, "OrderDate")
    DEC_PROPERTY_CACHE(Orders, RequiredDate, "RequiredDate")
    DEC_PROPERTY_CACHE(Orders, ShippedDate, "ShippedDate")
    DEC_PROPERTY_CACHE(Orders, ShipVia, "ShipVia")
    DEC_PROPERTY_CACHE(Orders, Freight, "Freight")
    DEC_PROPERTY_CACHE(Orders, ShipName, "ShipName")
    DEC_PROPERTY_CACHE(Orders, ShipAddress, "ShipAddress")
    DEC_PROPERTY_CACHE(Orders, ShipCity, "ShipCity")
    DEC_PROPERTY_CACHE(Orders, ShipRegion, "ShipRegion")
    DEC_PROPERTY_CACHE(Orders, ShipPostalCode, "ShipPostalCode")
    DEC_PROPERTY_CACHE(Orders, ShipCountry, "ShipCountry")    
  
  public:
    Expr<Orders^>() { }
    Expr<Orders^>(Expression<Orders^>^ value)
		{
			_value = value;
		}
		operator Expression<Orders^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> OrderID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_OrderID, this)); }
	  }

    property Expr<System::String^> CustomerID
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CustomerID, this)); }
	  }

    property Expr<System::Nullable<int>> EmployeeID
	  {
		  Expr<System::Nullable<int>> get() 
      {  return Expr<System::Nullable<int>>(gcnew PropertyExpression<System::Nullable<int>>(Property_EmployeeID, this)); }
	  }

    property Expr<System::Nullable<System::DateTime>> OrderDate
	  {
		  Expr<System::Nullable<System::DateTime>> get() 
      {  return Expr<System::Nullable<System::DateTime>>(gcnew PropertyExpression<System::Nullable<System::DateTime>>(Property_OrderDate, this)); }
	  }

    property Expr<System::Nullable<System::DateTime>> RequiredDate
	  {
		  Expr<System::Nullable<System::DateTime>> get() 
      {  return Expr<System::Nullable<System::DateTime>>(gcnew PropertyExpression<System::Nullable<System::DateTime>>(Property_RequiredDate, this)); }
	  }

    property Expr<System::Nullable<System::DateTime>> ShippedDate
	  {
		  Expr<System::Nullable<System::DateTime>> get() 
      {  return Expr<System::Nullable<System::DateTime>>(gcnew PropertyExpression<System::Nullable<System::DateTime>>(Property_ShippedDate, this)); }
	  }

    property Expr<System::Nullable<int>> ShipVia
	  {
		  Expr<System::Nullable<int>> get() 
      {  return Expr<System::Nullable<int>>(gcnew PropertyExpression<System::Nullable<int>>(Property_ShipVia, this)); }
	  }

    property Expr<System::Nullable<System::Decimal>> Freight
	  {
		  Expr<System::Nullable<System::Decimal>> get() 
      {  return Expr<System::Nullable<System::Decimal>>(gcnew PropertyExpression<System::Nullable<System::Decimal>>(Property_Freight, this)); }
	  }

    property Expr<System::String^> ShipName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ShipName, this)); }
	  }

    property Expr<System::String^> ShipAddress
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ShipAddress, this)); }
	  }

    property Expr<System::String^> ShipCity
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ShipCity, this)); }
	  }

    property Expr<System::String^> ShipRegion
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ShipRegion, this)); }
	  }

    property Expr<System::String^> ShipPostalCode
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ShipPostalCode, this)); }
	  }

    property Expr<System::String^> ShipCountry
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ShipCountry, this)); }
	  }
  };

  template<> ref class Var<Orders^> : ExpressionWrapper<Orders^>
	{
	public:
		Var<Orders^>(System::String^ name)
		{
			_value = gcnew Variable<Orders^>(name);
		}
		operator Expression<Orders^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Products")]
  ref class Products
  {
  private:

    int _ProductID;
    System::String^ _ProductName;
    System::Nullable<int> _SupplierID;
    System::Nullable<int> _CategoryID;
    System::String^ _QuantityPerUnit;
    System::Nullable<System::Decimal> _UnitPrice;
    System::Nullable<short> _UnitsInStock;
    System::Nullable<short> _UnitsOnOrder;
    System::Nullable<short> _ReorderLevel;
    bool _Discontinued;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ProductID", Storage = "_ProductID", DBType = "Int NOT NULL IDENTITY", Id = true, AutoGen = true)]
	  virtual property int ProductID
	  {
		  int get() { return this->_ProductID; }
		  void set(int value) 
      {
        if ((this->_ProductID != value))
        {
				  this->OnPropertyChanging("ProductID");
				  this->_ProductID = value;
				  this->OnPropertyChanged("ProductID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ProductName", Storage = "_ProductName", DBType = "NVarChar(40) NOT NULL")]
	  virtual property System::String^ ProductName
	  {
		  System::String^ get() { return this->_ProductName; }
		  void set(System::String^ value) 
      {
        if ((this->_ProductName != value))
        {
				  this->OnPropertyChanging("ProductName");
				  this->_ProductName = value;
				  this->OnPropertyChanged("ProductName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "SupplierID", Storage = "_SupplierID", DBType = "Int")]
	  virtual property System::Nullable<int> SupplierID
	  {
		  System::Nullable<int> get() { return this->_SupplierID; }
		  void set(System::Nullable<int> value) 
      {
        if ((this->_SupplierID.HasValue != value.HasValue) || (this->_SupplierID.HasValue && (this->_SupplierID.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("SupplierID");
				  this->_SupplierID = value;
				  this->OnPropertyChanged("SupplierID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CategoryID", Storage = "_CategoryID", DBType = "Int")]
	  virtual property System::Nullable<int> CategoryID
	  {
		  System::Nullable<int> get() { return this->_CategoryID; }
		  void set(System::Nullable<int> value) 
      {
        if ((this->_CategoryID.HasValue != value.HasValue) || (this->_CategoryID.HasValue && (this->_CategoryID.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("CategoryID");
				  this->_CategoryID = value;
				  this->OnPropertyChanged("CategoryID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "QuantityPerUnit", Storage = "_QuantityPerUnit", DBType = "NVarChar(20)")]
	  virtual property System::String^ QuantityPerUnit
	  {
		  System::String^ get() { return this->_QuantityPerUnit; }
		  void set(System::String^ value) 
      {
        if ((this->_QuantityPerUnit != value))
        {
				  this->OnPropertyChanging("QuantityPerUnit");
				  this->_QuantityPerUnit = value;
				  this->OnPropertyChanged("QuantityPerUnit");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "UnitPrice", Storage = "_UnitPrice", DBType = "Money")]
	  virtual property System::Nullable<System::Decimal> UnitPrice
	  {
		  System::Nullable<System::Decimal> get() { return this->_UnitPrice; }
		  void set(System::Nullable<System::Decimal> value) 
      {
        if ((this->_UnitPrice.HasValue != value.HasValue) || (this->_UnitPrice.HasValue && (this->_UnitPrice.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("UnitPrice");
				  this->_UnitPrice = value;
				  this->OnPropertyChanged("UnitPrice");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "UnitsInStock", Storage = "_UnitsInStock", DBType = "SmallInt")]
	  virtual property System::Nullable<short> UnitsInStock
	  {
		  System::Nullable<short> get() { return this->_UnitsInStock; }
		  void set(System::Nullable<short> value) 
      {
        if ((this->_UnitsInStock.HasValue != value.HasValue) || (this->_UnitsInStock.HasValue && (this->_UnitsInStock.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("UnitsInStock");
				  this->_UnitsInStock = value;
				  this->OnPropertyChanged("UnitsInStock");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "UnitsOnOrder", Storage = "_UnitsOnOrder", DBType = "SmallInt")]
	  virtual property System::Nullable<short> UnitsOnOrder
	  {
		  System::Nullable<short> get() { return this->_UnitsOnOrder; }
		  void set(System::Nullable<short> value) 
      {
        if ((this->_UnitsOnOrder.HasValue != value.HasValue) || (this->_UnitsOnOrder.HasValue && (this->_UnitsOnOrder.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("UnitsOnOrder");
				  this->_UnitsOnOrder = value;
				  this->OnPropertyChanged("UnitsOnOrder");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ReorderLevel", Storage = "_ReorderLevel", DBType = "SmallInt")]
	  virtual property System::Nullable<short> ReorderLevel
	  {
		  System::Nullable<short> get() { return this->_ReorderLevel; }
		  void set(System::Nullable<short> value) 
      {
        if ((this->_ReorderLevel.HasValue != value.HasValue) || (this->_ReorderLevel.HasValue && (this->_ReorderLevel.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("ReorderLevel");
				  this->_ReorderLevel = value;
				  this->OnPropertyChanged("ReorderLevel");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Discontinued", Storage = "_Discontinued", DBType = "Bit NOT NULL")]
	  virtual property bool Discontinued
	  {
		  bool get() { return this->_Discontinued; }
		  void set(bool value) 
      {
        if ((this->_Discontinued != value))
        {
				  this->OnPropertyChanging("Discontinued");
				  this->_Discontinued = value;
				  this->OnPropertyChanged("Discontinued");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Products()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Products^> : ExpressionWrapper<Products^>
  {
  private:

    DEC_PROPERTY_CACHE(Products, ProductID, "ProductID")
    DEC_PROPERTY_CACHE(Products, ProductName, "ProductName")
    DEC_PROPERTY_CACHE(Products, SupplierID, "SupplierID")
    DEC_PROPERTY_CACHE(Products, CategoryID, "CategoryID")
    DEC_PROPERTY_CACHE(Products, QuantityPerUnit, "QuantityPerUnit")
    DEC_PROPERTY_CACHE(Products, UnitPrice, "UnitPrice")
    DEC_PROPERTY_CACHE(Products, UnitsInStock, "UnitsInStock")
    DEC_PROPERTY_CACHE(Products, UnitsOnOrder, "UnitsOnOrder")
    DEC_PROPERTY_CACHE(Products, ReorderLevel, "ReorderLevel")
    DEC_PROPERTY_CACHE(Products, Discontinued, "Discontinued")    
  
  public:
    Expr<Products^>() { }
    Expr<Products^>(Expression<Products^>^ value)
		{
			_value = value;
		}
		operator Expression<Products^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> ProductID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_ProductID, this)); }
	  }

    property Expr<System::String^> ProductName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ProductName, this)); }
	  }

    property Expr<System::Nullable<int>> SupplierID
	  {
		  Expr<System::Nullable<int>> get() 
      {  return Expr<System::Nullable<int>>(gcnew PropertyExpression<System::Nullable<int>>(Property_SupplierID, this)); }
	  }

    property Expr<System::Nullable<int>> CategoryID
	  {
		  Expr<System::Nullable<int>> get() 
      {  return Expr<System::Nullable<int>>(gcnew PropertyExpression<System::Nullable<int>>(Property_CategoryID, this)); }
	  }

    property Expr<System::String^> QuantityPerUnit
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_QuantityPerUnit, this)); }
	  }

    property Expr<System::Nullable<System::Decimal>> UnitPrice
	  {
		  Expr<System::Nullable<System::Decimal>> get() 
      {  return Expr<System::Nullable<System::Decimal>>(gcnew PropertyExpression<System::Nullable<System::Decimal>>(Property_UnitPrice, this)); }
	  }

    property Expr<System::Nullable<short>> UnitsInStock
	  {
		  Expr<System::Nullable<short>> get() 
      {  return Expr<System::Nullable<short>>(gcnew PropertyExpression<System::Nullable<short>>(Property_UnitsInStock, this)); }
	  }

    property Expr<System::Nullable<short>> UnitsOnOrder
	  {
		  Expr<System::Nullable<short>> get() 
      {  return Expr<System::Nullable<short>>(gcnew PropertyExpression<System::Nullable<short>>(Property_UnitsOnOrder, this)); }
	  }

    property Expr<System::Nullable<short>> ReorderLevel
	  {
		  Expr<System::Nullable<short>> get() 
      {  return Expr<System::Nullable<short>>(gcnew PropertyExpression<System::Nullable<short>>(Property_ReorderLevel, this)); }
	  }

    property Expr<bool> Discontinued
	  {
		  Expr<bool> get() 
      {  return Expr<bool>(gcnew PropertyExpression<bool>(Property_Discontinued, this)); }
	  }
  };

  template<> ref class Var<Products^> : ExpressionWrapper<Products^>
	{
	public:
		Var<Products^>(System::String^ name)
		{
			_value = gcnew Variable<Products^>(name);
		}
		operator Expression<Products^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Order Details")]
  ref class Order_Details
  {
  private:

    int _OrderID;
    int _ProductID;
    System::Decimal _UnitPrice;
    short _Quantity;
    float _Discount;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "OrderID", Storage = "_OrderID", DBType = "Int NOT NULL", Id = true)]
	  virtual property int OrderID
	  {
		  int get() { return this->_OrderID; }
		  void set(int value) 
      {
        if ((this->_OrderID != value))
        {
				  this->OnPropertyChanging("OrderID");
				  this->_OrderID = value;
				  this->OnPropertyChanged("OrderID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ProductID", Storage = "_ProductID", DBType = "Int NOT NULL", Id = true)]
	  virtual property int ProductID
	  {
		  int get() { return this->_ProductID; }
		  void set(int value) 
      {
        if ((this->_ProductID != value))
        {
				  this->OnPropertyChanging("ProductID");
				  this->_ProductID = value;
				  this->OnPropertyChanged("ProductID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "UnitPrice", Storage = "_UnitPrice", DBType = "Money NOT NULL")]
	  virtual property System::Decimal UnitPrice
	  {
		  System::Decimal get() { return this->_UnitPrice; }
		  void set(System::Decimal value) 
      {
        if ((this->_UnitPrice != value))
        {
				  this->OnPropertyChanging("UnitPrice");
				  this->_UnitPrice = value;
				  this->OnPropertyChanged("UnitPrice");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Quantity", Storage = "_Quantity", DBType = "SmallInt NOT NULL")]
	  virtual property short Quantity
	  {
		  short get() { return this->_Quantity; }
		  void set(short value) 
      {
        if ((this->_Quantity != value))
        {
				  this->OnPropertyChanging("Quantity");
				  this->_Quantity = value;
				  this->OnPropertyChanged("Quantity");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Discount", Storage = "_Discount", DBType = "Real NOT NULL")]
	  virtual property float Discount
	  {
		  float get() { return this->_Discount; }
		  void set(float value) 
      {
        if ((this->_Discount != value))
        {
				  this->OnPropertyChanging("Discount");
				  this->_Discount = value;
				  this->OnPropertyChanged("Discount");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Order_Details()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Order_Details^> : ExpressionWrapper<Order_Details^>
  {
  private:

    DEC_PROPERTY_CACHE(Order_Details, OrderID, "OrderID")
    DEC_PROPERTY_CACHE(Order_Details, ProductID, "ProductID")
    DEC_PROPERTY_CACHE(Order_Details, UnitPrice, "UnitPrice")
    DEC_PROPERTY_CACHE(Order_Details, Quantity, "Quantity")
    DEC_PROPERTY_CACHE(Order_Details, Discount, "Discount")    
  
  public:
    Expr<Order_Details^>() { }
    Expr<Order_Details^>(Expression<Order_Details^>^ value)
		{
			_value = value;
		}
		operator Expression<Order_Details^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> OrderID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_OrderID, this)); }
	  }

    property Expr<int> ProductID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_ProductID, this)); }
	  }

    property Expr<System::Decimal> UnitPrice
	  {
		  Expr<System::Decimal> get() 
      {  return Expr<System::Decimal>(gcnew PropertyExpression<System::Decimal>(Property_UnitPrice, this)); }
	  }

    property Expr<short> Quantity
	  {
		  Expr<short> get() 
      {  return Expr<short>(gcnew PropertyExpression<short>(Property_Quantity, this)); }
	  }

    property Expr<float> Discount
	  {
		  Expr<float> get() 
      {  return Expr<float>(gcnew PropertyExpression<float>(Property_Discount, this)); }
	  }
  };

  template<> ref class Var<Order_Details^> : ExpressionWrapper<Order_Details^>
	{
	public:
		Var<Order_Details^>(System::String^ name)
		{
			_value = gcnew Variable<Order_Details^>(name);
		}
		operator Expression<Order_Details^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "CustomerCustomerDemo")]
  ref class CustomerCustomerDemo
  {
  private:

    System::String^ _CustomerID;
    System::String^ _CustomerTypeID;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CustomerID", Storage = "_CustomerID", DBType = "NChar(5) NOT NULL", Id = true)]
	  virtual property System::String^ CustomerID
	  {
		  System::String^ get() { return this->_CustomerID; }
		  void set(System::String^ value) 
      {
        if ((this->_CustomerID != value))
        {
				  this->OnPropertyChanging("CustomerID");
				  this->_CustomerID = value;
				  this->OnPropertyChanged("CustomerID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CustomerTypeID", Storage = "_CustomerTypeID", DBType = "NChar(10) NOT NULL", Id = true)]
	  virtual property System::String^ CustomerTypeID
	  {
		  System::String^ get() { return this->_CustomerTypeID; }
		  void set(System::String^ value) 
      {
        if ((this->_CustomerTypeID != value))
        {
				  this->OnPropertyChanging("CustomerTypeID");
				  this->_CustomerTypeID = value;
				  this->OnPropertyChanged("CustomerTypeID");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		CustomerCustomerDemo()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<CustomerCustomerDemo^> : ExpressionWrapper<CustomerCustomerDemo^>
  {
  private:

    DEC_PROPERTY_CACHE(CustomerCustomerDemo, CustomerID, "CustomerID")
    DEC_PROPERTY_CACHE(CustomerCustomerDemo, CustomerTypeID, "CustomerTypeID")    
  
  public:
    Expr<CustomerCustomerDemo^>() { }
    Expr<CustomerCustomerDemo^>(Expression<CustomerCustomerDemo^>^ value)
		{
			_value = value;
		}
		operator Expression<CustomerCustomerDemo^>^()
		{
			return _value;
		}
    
  public:

    property Expr<System::String^> CustomerID
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CustomerID, this)); }
	  }

    property Expr<System::String^> CustomerTypeID
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CustomerTypeID, this)); }
	  }
  };

  template<> ref class Var<CustomerCustomerDemo^> : ExpressionWrapper<CustomerCustomerDemo^>
	{
	public:
		Var<CustomerCustomerDemo^>(System::String^ name)
		{
			_value = gcnew Variable<CustomerCustomerDemo^>(name);
		}
		operator Expression<CustomerCustomerDemo^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "CustomerDemographics")]
  ref class CustomerDemographics
  {
  private:

    System::String^ _CustomerTypeID;
    System::String^ _CustomerDesc;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CustomerTypeID", Storage = "_CustomerTypeID", DBType = "NChar(10) NOT NULL", Id = true)]
	  virtual property System::String^ CustomerTypeID
	  {
		  System::String^ get() { return this->_CustomerTypeID; }
		  void set(System::String^ value) 
      {
        if ((this->_CustomerTypeID != value))
        {
				  this->OnPropertyChanging("CustomerTypeID");
				  this->_CustomerTypeID = value;
				  this->OnPropertyChanged("CustomerTypeID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CustomerDesc", Storage = "_CustomerDesc", DBType = "NText")]
	  virtual property System::String^ CustomerDesc
	  {
		  System::String^ get() { return this->_CustomerDesc; }
		  void set(System::String^ value) 
      {
        if ((this->_CustomerDesc != value))
        {
				  this->OnPropertyChanging("CustomerDesc");
				  this->_CustomerDesc = value;
				  this->OnPropertyChanged("CustomerDesc");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		CustomerDemographics()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<CustomerDemographics^> : ExpressionWrapper<CustomerDemographics^>
  {
  private:

    DEC_PROPERTY_CACHE(CustomerDemographics, CustomerTypeID, "CustomerTypeID")
    DEC_PROPERTY_CACHE(CustomerDemographics, CustomerDesc, "CustomerDesc")    
  
  public:
    Expr<CustomerDemographics^>() { }
    Expr<CustomerDemographics^>(Expression<CustomerDemographics^>^ value)
		{
			_value = value;
		}
		operator Expression<CustomerDemographics^>^()
		{
			return _value;
		}
    
  public:

    property Expr<System::String^> CustomerTypeID
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CustomerTypeID, this)); }
	  }

    property Expr<System::String^> CustomerDesc
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CustomerDesc, this)); }
	  }
  };

  template<> ref class Var<CustomerDemographics^> : ExpressionWrapper<CustomerDemographics^>
	{
	public:
		Var<CustomerDemographics^>(System::String^ name)
		{
			_value = gcnew Variable<CustomerDemographics^>(name);
		}
		operator Expression<CustomerDemographics^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Region")]
  ref class Region
  {
  private:

    int _RegionID;
    System::String^ _RegionDescription;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "RegionID", Storage = "_RegionID", DBType = "Int NOT NULL", Id = true)]
	  virtual property int RegionID
	  {
		  int get() { return this->_RegionID; }
		  void set(int value) 
      {
        if ((this->_RegionID != value))
        {
				  this->OnPropertyChanging("RegionID");
				  this->_RegionID = value;
				  this->OnPropertyChanged("RegionID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "RegionDescription", Storage = "_RegionDescription", DBType = "NChar(50) NOT NULL")]
	  virtual property System::String^ RegionDescription
	  {
		  System::String^ get() { return this->_RegionDescription; }
		  void set(System::String^ value) 
      {
        if ((this->_RegionDescription != value))
        {
				  this->OnPropertyChanging("RegionDescription");
				  this->_RegionDescription = value;
				  this->OnPropertyChanged("RegionDescription");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Region()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Region^> : ExpressionWrapper<Region^>
  {
  private:

    DEC_PROPERTY_CACHE(Region, RegionID, "RegionID")
    DEC_PROPERTY_CACHE(Region, RegionDescription, "RegionDescription")    
  
  public:
    Expr<Region^>() { }
    Expr<Region^>(Expression<Region^>^ value)
		{
			_value = value;
		}
		operator Expression<Region^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> RegionID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_RegionID, this)); }
	  }

    property Expr<System::String^> RegionDescription
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_RegionDescription, this)); }
	  }
  };

  template<> ref class Var<Region^> : ExpressionWrapper<Region^>
	{
	public:
		Var<Region^>(System::String^ name)
		{
			_value = gcnew Variable<Region^>(name);
		}
		operator Expression<Region^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Territories")]
  ref class Territories
  {
  private:

    System::String^ _TerritoryID;
    System::String^ _TerritoryDescription;
    int _RegionID;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "TerritoryID", Storage = "_TerritoryID", DBType = "NVarChar(20) NOT NULL", Id = true)]
	  virtual property System::String^ TerritoryID
	  {
		  System::String^ get() { return this->_TerritoryID; }
		  void set(System::String^ value) 
      {
        if ((this->_TerritoryID != value))
        {
				  this->OnPropertyChanging("TerritoryID");
				  this->_TerritoryID = value;
				  this->OnPropertyChanged("TerritoryID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "TerritoryDescription", Storage = "_TerritoryDescription", DBType = "NChar(50) NOT NULL")]
	  virtual property System::String^ TerritoryDescription
	  {
		  System::String^ get() { return this->_TerritoryDescription; }
		  void set(System::String^ value) 
      {
        if ((this->_TerritoryDescription != value))
        {
				  this->OnPropertyChanging("TerritoryDescription");
				  this->_TerritoryDescription = value;
				  this->OnPropertyChanged("TerritoryDescription");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "RegionID", Storage = "_RegionID", DBType = "Int NOT NULL")]
	  virtual property int RegionID
	  {
		  int get() { return this->_RegionID; }
		  void set(int value) 
      {
        if ((this->_RegionID != value))
        {
				  this->OnPropertyChanging("RegionID");
				  this->_RegionID = value;
				  this->OnPropertyChanged("RegionID");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Territories()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Territories^> : ExpressionWrapper<Territories^>
  {
  private:

    DEC_PROPERTY_CACHE(Territories, TerritoryID, "TerritoryID")
    DEC_PROPERTY_CACHE(Territories, TerritoryDescription, "TerritoryDescription")
    DEC_PROPERTY_CACHE(Territories, RegionID, "RegionID")    
  
  public:
    Expr<Territories^>() { }
    Expr<Territories^>(Expression<Territories^>^ value)
		{
			_value = value;
		}
		operator Expression<Territories^>^()
		{
			return _value;
		}
    
  public:

    property Expr<System::String^> TerritoryID
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_TerritoryID, this)); }
	  }

    property Expr<System::String^> TerritoryDescription
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_TerritoryDescription, this)); }
	  }

    property Expr<int> RegionID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_RegionID, this)); }
	  }
  };

  template<> ref class Var<Territories^> : ExpressionWrapper<Territories^>
	{
	public:
		Var<Territories^>(System::String^ name)
		{
			_value = gcnew Variable<Territories^>(name);
		}
		operator Expression<Territories^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "EmployeeTerritories")]
  ref class EmployeeTerritories
  {
  private:

    int _EmployeeID;
    System::String^ _TerritoryID;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "EmployeeID", Storage = "_EmployeeID", DBType = "Int NOT NULL", Id = true)]
	  virtual property int EmployeeID
	  {
		  int get() { return this->_EmployeeID; }
		  void set(int value) 
      {
        if ((this->_EmployeeID != value))
        {
				  this->OnPropertyChanging("EmployeeID");
				  this->_EmployeeID = value;
				  this->OnPropertyChanged("EmployeeID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "TerritoryID", Storage = "_TerritoryID", DBType = "NVarChar(20) NOT NULL", Id = true)]
	  virtual property System::String^ TerritoryID
	  {
		  System::String^ get() { return this->_TerritoryID; }
		  void set(System::String^ value) 
      {
        if ((this->_TerritoryID != value))
        {
				  this->OnPropertyChanging("TerritoryID");
				  this->_TerritoryID = value;
				  this->OnPropertyChanged("TerritoryID");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		EmployeeTerritories()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<EmployeeTerritories^> : ExpressionWrapper<EmployeeTerritories^>
  {
  private:

    DEC_PROPERTY_CACHE(EmployeeTerritories, EmployeeID, "EmployeeID")
    DEC_PROPERTY_CACHE(EmployeeTerritories, TerritoryID, "TerritoryID")    
  
  public:
    Expr<EmployeeTerritories^>() { }
    Expr<EmployeeTerritories^>(Expression<EmployeeTerritories^>^ value)
		{
			_value = value;
		}
		operator Expression<EmployeeTerritories^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> EmployeeID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_EmployeeID, this)); }
	  }

    property Expr<System::String^> TerritoryID
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_TerritoryID, this)); }
	  }
  };

  template<> ref class Var<EmployeeTerritories^> : ExpressionWrapper<EmployeeTerritories^>
	{
	public:
		Var<EmployeeTerritories^>(System::String^ name)
		{
			_value = gcnew Variable<EmployeeTerritories^>(name);
		}
		operator Expression<EmployeeTerritories^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Employees")]
  ref class Employees
  {
  private:

    int _EmployeeID;
    System::String^ _LastName;
    System::String^ _FirstName;
    System::String^ _Title;
    System::String^ _TitleOfCourtesy;
    System::Nullable<System::DateTime> _BirthDate;
    System::Nullable<System::DateTime> _HireDate;
    System::String^ _Address;
    System::String^ _City;
    System::String^ _Region;
    System::String^ _PostalCode;
    System::String^ _Country;
    System::String^ _HomePhone;
    System::String^ _Extension;
    array<unsigned char>^ _Photo;
    System::String^ _Notes;
    System::Nullable<int> _ReportsTo;
    System::String^ _PhotoPath;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "EmployeeID", Storage = "_EmployeeID", DBType = "Int NOT NULL IDENTITY", Id = true, AutoGen = true)]
	  virtual property int EmployeeID
	  {
		  int get() { return this->_EmployeeID; }
		  void set(int value) 
      {
        if ((this->_EmployeeID != value))
        {
				  this->OnPropertyChanging("EmployeeID");
				  this->_EmployeeID = value;
				  this->OnPropertyChanged("EmployeeID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "LastName", Storage = "_LastName", DBType = "NVarChar(20) NOT NULL")]
	  virtual property System::String^ LastName
	  {
		  System::String^ get() { return this->_LastName; }
		  void set(System::String^ value) 
      {
        if ((this->_LastName != value))
        {
				  this->OnPropertyChanging("LastName");
				  this->_LastName = value;
				  this->OnPropertyChanged("LastName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "FirstName", Storage = "_FirstName", DBType = "NVarChar(10) NOT NULL")]
	  virtual property System::String^ FirstName
	  {
		  System::String^ get() { return this->_FirstName; }
		  void set(System::String^ value) 
      {
        if ((this->_FirstName != value))
        {
				  this->OnPropertyChanging("FirstName");
				  this->_FirstName = value;
				  this->OnPropertyChanged("FirstName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Title", Storage = "_Title", DBType = "NVarChar(30)")]
	  virtual property System::String^ Title
	  {
		  System::String^ get() { return this->_Title; }
		  void set(System::String^ value) 
      {
        if ((this->_Title != value))
        {
				  this->OnPropertyChanging("Title");
				  this->_Title = value;
				  this->OnPropertyChanged("Title");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "TitleOfCourtesy", Storage = "_TitleOfCourtesy", DBType = "NVarChar(25)")]
	  virtual property System::String^ TitleOfCourtesy
	  {
		  System::String^ get() { return this->_TitleOfCourtesy; }
		  void set(System::String^ value) 
      {
        if ((this->_TitleOfCourtesy != value))
        {
				  this->OnPropertyChanging("TitleOfCourtesy");
				  this->_TitleOfCourtesy = value;
				  this->OnPropertyChanged("TitleOfCourtesy");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "BirthDate", Storage = "_BirthDate", DBType = "DateTime")]
	  virtual property System::Nullable<System::DateTime> BirthDate
	  {
		  System::Nullable<System::DateTime> get() { return this->_BirthDate; }
		  void set(System::Nullable<System::DateTime> value) 
      {
        if ((this->_BirthDate.HasValue != value.HasValue) || (this->_BirthDate.HasValue && (this->_BirthDate.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("BirthDate");
				  this->_BirthDate = value;
				  this->OnPropertyChanged("BirthDate");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "HireDate", Storage = "_HireDate", DBType = "DateTime")]
	  virtual property System::Nullable<System::DateTime> HireDate
	  {
		  System::Nullable<System::DateTime> get() { return this->_HireDate; }
		  void set(System::Nullable<System::DateTime> value) 
      {
        if ((this->_HireDate.HasValue != value.HasValue) || (this->_HireDate.HasValue && (this->_HireDate.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("HireDate");
				  this->_HireDate = value;
				  this->OnPropertyChanged("HireDate");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Address", Storage = "_Address", DBType = "NVarChar(60)")]
	  virtual property System::String^ Address
	  {
		  System::String^ get() { return this->_Address; }
		  void set(System::String^ value) 
      {
        if ((this->_Address != value))
        {
				  this->OnPropertyChanging("Address");
				  this->_Address = value;
				  this->OnPropertyChanged("Address");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "City", Storage = "_City", DBType = "NVarChar(15)")]
	  virtual property System::String^ City
	  {
		  System::String^ get() { return this->_City; }
		  void set(System::String^ value) 
      {
        if ((this->_City != value))
        {
				  this->OnPropertyChanging("City");
				  this->_City = value;
				  this->OnPropertyChanged("City");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Region", Storage = "_Region", DBType = "NVarChar(15)")]
	  virtual property System::String^ Region
	  {
		  System::String^ get() { return this->_Region; }
		  void set(System::String^ value) 
      {
        if ((this->_Region != value))
        {
				  this->OnPropertyChanging("Region");
				  this->_Region = value;
				  this->OnPropertyChanged("Region");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "PostalCode", Storage = "_PostalCode", DBType = "NVarChar(10)")]
	  virtual property System::String^ PostalCode
	  {
		  System::String^ get() { return this->_PostalCode; }
		  void set(System::String^ value) 
      {
        if ((this->_PostalCode != value))
        {
				  this->OnPropertyChanging("PostalCode");
				  this->_PostalCode = value;
				  this->OnPropertyChanged("PostalCode");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Country", Storage = "_Country", DBType = "NVarChar(15)")]
	  virtual property System::String^ Country
	  {
		  System::String^ get() { return this->_Country; }
		  void set(System::String^ value) 
      {
        if ((this->_Country != value))
        {
				  this->OnPropertyChanging("Country");
				  this->_Country = value;
				  this->OnPropertyChanged("Country");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "HomePhone", Storage = "_HomePhone", DBType = "NVarChar(24)")]
	  virtual property System::String^ HomePhone
	  {
		  System::String^ get() { return this->_HomePhone; }
		  void set(System::String^ value) 
      {
        if ((this->_HomePhone != value))
        {
				  this->OnPropertyChanging("HomePhone");
				  this->_HomePhone = value;
				  this->OnPropertyChanged("HomePhone");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Extension", Storage = "_Extension", DBType = "NVarChar(4)")]
	  virtual property System::String^ Extension
	  {
		  System::String^ get() { return this->_Extension; }
		  void set(System::String^ value) 
      {
        if ((this->_Extension != value))
        {
				  this->OnPropertyChanging("Extension");
				  this->_Extension = value;
				  this->OnPropertyChanged("Extension");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Photo", Storage = "_Photo", DBType = "Image")]
	  virtual property array<unsigned char>^ Photo
	  {
		  array<unsigned char>^ get() { return this->_Photo; }
		  void set(array<unsigned char>^ value) 
      {
        if ((this->_Photo != value))
        {
				  this->OnPropertyChanging("Photo");
				  this->_Photo = value;
				  this->OnPropertyChanged("Photo");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Notes", Storage = "_Notes", DBType = "NText")]
	  virtual property System::String^ Notes
	  {
		  System::String^ get() { return this->_Notes; }
		  void set(System::String^ value) 
      {
        if ((this->_Notes != value))
        {
				  this->OnPropertyChanging("Notes");
				  this->_Notes = value;
				  this->OnPropertyChanged("Notes");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ReportsTo", Storage = "_ReportsTo", DBType = "Int")]
	  virtual property System::Nullable<int> ReportsTo
	  {
		  System::Nullable<int> get() { return this->_ReportsTo; }
		  void set(System::Nullable<int> value) 
      {
        if ((this->_ReportsTo.HasValue != value.HasValue) || (this->_ReportsTo.HasValue && (this->_ReportsTo.GetValueOrDefault() != value.GetValueOrDefault())))
        {
				  this->OnPropertyChanging("ReportsTo");
				  this->_ReportsTo = value;
				  this->OnPropertyChanged("ReportsTo");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "PhotoPath", Storage = "_PhotoPath", DBType = "NVarChar(255)")]
	  virtual property System::String^ PhotoPath
	  {
		  System::String^ get() { return this->_PhotoPath; }
		  void set(System::String^ value) 
      {
        if ((this->_PhotoPath != value))
        {
				  this->OnPropertyChanging("PhotoPath");
				  this->_PhotoPath = value;
				  this->OnPropertyChanged("PhotoPath");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Employees()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Employees^> : ExpressionWrapper<Employees^>
  {
  private:

    DEC_PROPERTY_CACHE(Employees, EmployeeID, "EmployeeID")
    DEC_PROPERTY_CACHE(Employees, LastName, "LastName")
    DEC_PROPERTY_CACHE(Employees, FirstName, "FirstName")
    DEC_PROPERTY_CACHE(Employees, Title, "Title")
    DEC_PROPERTY_CACHE(Employees, TitleOfCourtesy, "TitleOfCourtesy")
    DEC_PROPERTY_CACHE(Employees, BirthDate, "BirthDate")
    DEC_PROPERTY_CACHE(Employees, HireDate, "HireDate")
    DEC_PROPERTY_CACHE(Employees, Address, "Address")
    DEC_PROPERTY_CACHE(Employees, City, "City")
    DEC_PROPERTY_CACHE(Employees, Region, "Region")
    DEC_PROPERTY_CACHE(Employees, PostalCode, "PostalCode")
    DEC_PROPERTY_CACHE(Employees, Country, "Country")
    DEC_PROPERTY_CACHE(Employees, HomePhone, "HomePhone")
    DEC_PROPERTY_CACHE(Employees, Extension, "Extension")
    DEC_PROPERTY_CACHE(Employees, Photo, "Photo")
    DEC_PROPERTY_CACHE(Employees, Notes, "Notes")
    DEC_PROPERTY_CACHE(Employees, ReportsTo, "ReportsTo")
    DEC_PROPERTY_CACHE(Employees, PhotoPath, "PhotoPath")    
  
  public:
    Expr<Employees^>() { }
    Expr<Employees^>(Expression<Employees^>^ value)
		{
			_value = value;
		}
		operator Expression<Employees^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> EmployeeID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_EmployeeID, this)); }
	  }

    property Expr<System::String^> LastName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_LastName, this)); }
	  }

    property Expr<System::String^> FirstName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_FirstName, this)); }
	  }

    property Expr<System::String^> Title
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Title, this)); }
	  }

    property Expr<System::String^> TitleOfCourtesy
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_TitleOfCourtesy, this)); }
	  }

    property Expr<System::Nullable<System::DateTime>> BirthDate
	  {
		  Expr<System::Nullable<System::DateTime>> get() 
      {  return Expr<System::Nullable<System::DateTime>>(gcnew PropertyExpression<System::Nullable<System::DateTime>>(Property_BirthDate, this)); }
	  }

    property Expr<System::Nullable<System::DateTime>> HireDate
	  {
		  Expr<System::Nullable<System::DateTime>> get() 
      {  return Expr<System::Nullable<System::DateTime>>(gcnew PropertyExpression<System::Nullable<System::DateTime>>(Property_HireDate, this)); }
	  }

    property Expr<System::String^> Address
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Address, this)); }
	  }

    property Expr<System::String^> City
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_City, this)); }
	  }

    property Expr<System::String^> Region
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Region, this)); }
	  }

    property Expr<System::String^> PostalCode
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_PostalCode, this)); }
	  }

    property Expr<System::String^> Country
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Country, this)); }
	  }

    property Expr<System::String^> HomePhone
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_HomePhone, this)); }
	  }

    property Expr<System::String^> Extension
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Extension, this)); }
	  }

    property Expression<array<unsigned char>^>^ Photo
	  {
		  Expression<array<unsigned char>^>^ get() 
      {  return (gcnew PropertyExpression<array<unsigned char>^>(Property_Photo, this)); }
	  }

    property Expr<System::String^> Notes
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Notes, this)); }
	  }

    property Expr<System::Nullable<int>> ReportsTo
	  {
		  Expr<System::Nullable<int>> get() 
      {  return Expr<System::Nullable<int>>(gcnew PropertyExpression<System::Nullable<int>>(Property_ReportsTo, this)); }
	  }

    property Expr<System::String^> PhotoPath
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_PhotoPath, this)); }
	  }
  };

  template<> ref class Var<Employees^> : ExpressionWrapper<Employees^>
	{
	public:
		Var<Employees^>(System::String^ name)
		{
			_value = gcnew Variable<Employees^>(name);
		}
		operator Expression<Employees^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Categories")]
  ref class Categories
  {
  private:

    int _CategoryID;
    System::String^ _CategoryName;
    System::String^ _Description;
    array<unsigned char>^ _Picture;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CategoryID", Storage = "_CategoryID", DBType = "Int NOT NULL IDENTITY", Id = true, AutoGen = true)]
	  virtual property int CategoryID
	  {
		  int get() { return this->_CategoryID; }
		  void set(int value) 
      {
        if ((this->_CategoryID != value))
        {
				  this->OnPropertyChanging("CategoryID");
				  this->_CategoryID = value;
				  this->OnPropertyChanged("CategoryID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CategoryName", Storage = "_CategoryName", DBType = "NVarChar(15) NOT NULL")]
	  virtual property System::String^ CategoryName
	  {
		  System::String^ get() { return this->_CategoryName; }
		  void set(System::String^ value) 
      {
        if ((this->_CategoryName != value))
        {
				  this->OnPropertyChanging("CategoryName");
				  this->_CategoryName = value;
				  this->OnPropertyChanged("CategoryName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Description", Storage = "_Description", DBType = "NText")]
	  virtual property System::String^ Description
	  {
		  System::String^ get() { return this->_Description; }
		  void set(System::String^ value) 
      {
        if ((this->_Description != value))
        {
				  this->OnPropertyChanging("Description");
				  this->_Description = value;
				  this->OnPropertyChanged("Description");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Picture", Storage = "_Picture", DBType = "Image")]
	  virtual property array<unsigned char>^ Picture
	  {
		  array<unsigned char>^ get() { return this->_Picture; }
		  void set(array<unsigned char>^ value) 
      {
        if ((this->_Picture != value))
        {
				  this->OnPropertyChanging("Picture");
				  this->_Picture = value;
				  this->OnPropertyChanged("Picture");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Categories()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Categories^> : ExpressionWrapper<Categories^>
  {
  private:

    DEC_PROPERTY_CACHE(Categories, CategoryID, "CategoryID")
    DEC_PROPERTY_CACHE(Categories, CategoryName, "CategoryName")
    DEC_PROPERTY_CACHE(Categories, Description, "Description")
    DEC_PROPERTY_CACHE(Categories, Picture, "Picture")    
  
  public:
    Expr<Categories^>() { }
    Expr<Categories^>(Expression<Categories^>^ value)
		{
			_value = value;
		}
		operator Expression<Categories^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> CategoryID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_CategoryID, this)); }
	  }

    property Expr<System::String^> CategoryName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CategoryName, this)); }
	  }

    property Expr<System::String^> Description
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Description, this)); }
	  }

    property Expression<array<unsigned char>^>^ Picture
	  {
		  Expression<array<unsigned char>^>^ get() 
      {  return (gcnew PropertyExpression<array<unsigned char>^>(Property_Picture, this)); }
	  }
  };

  template<> ref class Var<Categories^> : ExpressionWrapper<Categories^>
	{
	public:
		Var<Categories^>(System::String^ name)
		{
			_value = gcnew Variable<Categories^>(name);
		}
		operator Expression<Categories^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Customers")]
  ref class Customers
  {
  private:

    System::String^ _CustomerID;
    System::String^ _CompanyName;
    System::String^ _ContactName;
    System::String^ _ContactTitle;
    System::String^ _Address;
    System::String^ _City;
    System::String^ _Region;
    System::String^ _PostalCode;
    System::String^ _Country;
    System::String^ _Phone;
    System::String^ _Fax;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CustomerID", Storage = "_CustomerID", DBType = "NChar(5) NOT NULL", Id = true)]
	  virtual property System::String^ CustomerID
	  {
		  System::String^ get() { return this->_CustomerID; }
		  void set(System::String^ value) 
      {
        if ((this->_CustomerID != value))
        {
				  this->OnPropertyChanging("CustomerID");
				  this->_CustomerID = value;
				  this->OnPropertyChanged("CustomerID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CompanyName", Storage = "_CompanyName", DBType = "NVarChar(40) NOT NULL")]
	  virtual property System::String^ CompanyName
	  {
		  System::String^ get() { return this->_CompanyName; }
		  void set(System::String^ value) 
      {
        if ((this->_CompanyName != value))
        {
				  this->OnPropertyChanging("CompanyName");
				  this->_CompanyName = value;
				  this->OnPropertyChanged("CompanyName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ContactName", Storage = "_ContactName", DBType = "NVarChar(30)")]
	  virtual property System::String^ ContactName
	  {
		  System::String^ get() { return this->_ContactName; }
		  void set(System::String^ value) 
      {
        if ((this->_ContactName != value))
        {
				  this->OnPropertyChanging("ContactName");
				  this->_ContactName = value;
				  this->OnPropertyChanged("ContactName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ContactTitle", Storage = "_ContactTitle", DBType = "NVarChar(30)")]
	  virtual property System::String^ ContactTitle
	  {
		  System::String^ get() { return this->_ContactTitle; }
		  void set(System::String^ value) 
      {
        if ((this->_ContactTitle != value))
        {
				  this->OnPropertyChanging("ContactTitle");
				  this->_ContactTitle = value;
				  this->OnPropertyChanged("ContactTitle");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Address", Storage = "_Address", DBType = "NVarChar(60)")]
	  virtual property System::String^ Address
	  {
		  System::String^ get() { return this->_Address; }
		  void set(System::String^ value) 
      {
        if ((this->_Address != value))
        {
				  this->OnPropertyChanging("Address");
				  this->_Address = value;
				  this->OnPropertyChanged("Address");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "City", Storage = "_City", DBType = "NVarChar(15)")]
	  virtual property System::String^ City
	  {
		  System::String^ get() { return this->_City; }
		  void set(System::String^ value) 
      {
        if ((this->_City != value))
        {
				  this->OnPropertyChanging("City");
				  this->_City = value;
				  this->OnPropertyChanged("City");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Region", Storage = "_Region", DBType = "NVarChar(15)")]
	  virtual property System::String^ Region
	  {
		  System::String^ get() { return this->_Region; }
		  void set(System::String^ value) 
      {
        if ((this->_Region != value))
        {
				  this->OnPropertyChanging("Region");
				  this->_Region = value;
				  this->OnPropertyChanged("Region");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "PostalCode", Storage = "_PostalCode", DBType = "NVarChar(10)")]
	  virtual property System::String^ PostalCode
	  {
		  System::String^ get() { return this->_PostalCode; }
		  void set(System::String^ value) 
      {
        if ((this->_PostalCode != value))
        {
				  this->OnPropertyChanging("PostalCode");
				  this->_PostalCode = value;
				  this->OnPropertyChanged("PostalCode");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Country", Storage = "_Country", DBType = "NVarChar(15)")]
	  virtual property System::String^ Country
	  {
		  System::String^ get() { return this->_Country; }
		  void set(System::String^ value) 
      {
        if ((this->_Country != value))
        {
				  this->OnPropertyChanging("Country");
				  this->_Country = value;
				  this->OnPropertyChanged("Country");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Phone", Storage = "_Phone", DBType = "NVarChar(24)")]
	  virtual property System::String^ Phone
	  {
		  System::String^ get() { return this->_Phone; }
		  void set(System::String^ value) 
      {
        if ((this->_Phone != value))
        {
				  this->OnPropertyChanging("Phone");
				  this->_Phone = value;
				  this->OnPropertyChanged("Phone");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Fax", Storage = "_Fax", DBType = "NVarChar(24)")]
	  virtual property System::String^ Fax
	  {
		  System::String^ get() { return this->_Fax; }
		  void set(System::String^ value) 
      {
        if ((this->_Fax != value))
        {
				  this->OnPropertyChanging("Fax");
				  this->_Fax = value;
				  this->OnPropertyChanged("Fax");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Customers()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Customers^> : ExpressionWrapper<Customers^>
  {
  private:

    DEC_PROPERTY_CACHE(Customers, CustomerID, "CustomerID")
    DEC_PROPERTY_CACHE(Customers, CompanyName, "CompanyName")
    DEC_PROPERTY_CACHE(Customers, ContactName, "ContactName")
    DEC_PROPERTY_CACHE(Customers, ContactTitle, "ContactTitle")
    DEC_PROPERTY_CACHE(Customers, Address, "Address")
    DEC_PROPERTY_CACHE(Customers, City, "City")
    DEC_PROPERTY_CACHE(Customers, Region, "Region")
    DEC_PROPERTY_CACHE(Customers, PostalCode, "PostalCode")
    DEC_PROPERTY_CACHE(Customers, Country, "Country")
    DEC_PROPERTY_CACHE(Customers, Phone, "Phone")
    DEC_PROPERTY_CACHE(Customers, Fax, "Fax")    
  
  public:
    Expr<Customers^>() { }
    Expr<Customers^>(Expression<Customers^>^ value)
		{
			_value = value;
		}
		operator Expression<Customers^>^()
		{
			return _value;
		}
    
  public:

    property Expr<System::String^> CustomerID
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CustomerID, this)); }
	  }

    property Expr<System::String^> CompanyName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CompanyName, this)); }
	  }

    property Expr<System::String^> ContactName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ContactName, this)); }
	  }

    property Expr<System::String^> ContactTitle
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ContactTitle, this)); }
	  }

    property Expr<System::String^> Address
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Address, this)); }
	  }

    property Expr<System::String^> City
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_City, this)); }
	  }

    property Expr<System::String^> Region
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Region, this)); }
	  }

    property Expr<System::String^> PostalCode
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_PostalCode, this)); }
	  }

    property Expr<System::String^> Country
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Country, this)); }
	  }

    property Expr<System::String^> Phone
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Phone, this)); }
	  }

    property Expr<System::String^> Fax
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Fax, this)); }
	  }
  };

  template<> ref class Var<Customers^> : ExpressionWrapper<Customers^>
	{
	public:
		Var<Customers^>(System::String^ name)
		{
			_value = gcnew Variable<Customers^>(name);
		}
		operator Expression<Customers^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Shippers")]
  ref class Shippers
  {
  private:

    int _ShipperID;
    System::String^ _CompanyName;
    System::String^ _Phone;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ShipperID", Storage = "_ShipperID", DBType = "Int NOT NULL IDENTITY", Id = true, AutoGen = true)]
	  virtual property int ShipperID
	  {
		  int get() { return this->_ShipperID; }
		  void set(int value) 
      {
        if ((this->_ShipperID != value))
        {
				  this->OnPropertyChanging("ShipperID");
				  this->_ShipperID = value;
				  this->OnPropertyChanged("ShipperID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CompanyName", Storage = "_CompanyName", DBType = "NVarChar(40) NOT NULL")]
	  virtual property System::String^ CompanyName
	  {
		  System::String^ get() { return this->_CompanyName; }
		  void set(System::String^ value) 
      {
        if ((this->_CompanyName != value))
        {
				  this->OnPropertyChanging("CompanyName");
				  this->_CompanyName = value;
				  this->OnPropertyChanged("CompanyName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Phone", Storage = "_Phone", DBType = "NVarChar(24)")]
	  virtual property System::String^ Phone
	  {
		  System::String^ get() { return this->_Phone; }
		  void set(System::String^ value) 
      {
        if ((this->_Phone != value))
        {
				  this->OnPropertyChanging("Phone");
				  this->_Phone = value;
				  this->OnPropertyChanged("Phone");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Shippers()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Shippers^> : ExpressionWrapper<Shippers^>
  {
  private:

    DEC_PROPERTY_CACHE(Shippers, ShipperID, "ShipperID")
    DEC_PROPERTY_CACHE(Shippers, CompanyName, "CompanyName")
    DEC_PROPERTY_CACHE(Shippers, Phone, "Phone")    
  
  public:
    Expr<Shippers^>() { }
    Expr<Shippers^>(Expression<Shippers^>^ value)
		{
			_value = value;
		}
		operator Expression<Shippers^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> ShipperID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_ShipperID, this)); }
	  }

    property Expr<System::String^> CompanyName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CompanyName, this)); }
	  }

    property Expr<System::String^> Phone
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Phone, this)); }
	  }
  };

  template<> ref class Var<Shippers^> : ExpressionWrapper<Shippers^>
	{
	public:
		Var<Shippers^>(System::String^ name)
		{
			_value = gcnew Variable<Shippers^>(name);
		}
		operator Expression<Shippers^>^()
		{
			return _value;
		}
	};  
} }


namespace EeekSoft { namespace CLinq { namespace Demo { 
  
  [System::Data::DLinq::TableAttribute(Name = "Suppliers")]
  ref class Suppliers
  {
  private:

    int _SupplierID;
    System::String^ _CompanyName;
    System::String^ _ContactName;
    System::String^ _ContactTitle;
    System::String^ _Address;
    System::String^ _City;
    System::String^ _Region;
    System::String^ _PostalCode;
    System::String^ _Country;
    System::String^ _Phone;
    System::String^ _Fax;
    System::String^ _HomePage;
  public:

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "SupplierID", Storage = "_SupplierID", DBType = "Int NOT NULL IDENTITY", Id = true, AutoGen = true)]
	  virtual property int SupplierID
	  {
		  int get() { return this->_SupplierID; }
		  void set(int value) 
      {
        if ((this->_SupplierID != value))
        {
				  this->OnPropertyChanging("SupplierID");
				  this->_SupplierID = value;
				  this->OnPropertyChanged("SupplierID");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "CompanyName", Storage = "_CompanyName", DBType = "NVarChar(40) NOT NULL")]
	  virtual property System::String^ CompanyName
	  {
		  System::String^ get() { return this->_CompanyName; }
		  void set(System::String^ value) 
      {
        if ((this->_CompanyName != value))
        {
				  this->OnPropertyChanging("CompanyName");
				  this->_CompanyName = value;
				  this->OnPropertyChanged("CompanyName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ContactName", Storage = "_ContactName", DBType = "NVarChar(30)")]
	  virtual property System::String^ ContactName
	  {
		  System::String^ get() { return this->_ContactName; }
		  void set(System::String^ value) 
      {
        if ((this->_ContactName != value))
        {
				  this->OnPropertyChanging("ContactName");
				  this->_ContactName = value;
				  this->OnPropertyChanged("ContactName");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "ContactTitle", Storage = "_ContactTitle", DBType = "NVarChar(30)")]
	  virtual property System::String^ ContactTitle
	  {
		  System::String^ get() { return this->_ContactTitle; }
		  void set(System::String^ value) 
      {
        if ((this->_ContactTitle != value))
        {
				  this->OnPropertyChanging("ContactTitle");
				  this->_ContactTitle = value;
				  this->OnPropertyChanged("ContactTitle");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Address", Storage = "_Address", DBType = "NVarChar(60)")]
	  virtual property System::String^ Address
	  {
		  System::String^ get() { return this->_Address; }
		  void set(System::String^ value) 
      {
        if ((this->_Address != value))
        {
				  this->OnPropertyChanging("Address");
				  this->_Address = value;
				  this->OnPropertyChanged("Address");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "City", Storage = "_City", DBType = "NVarChar(15)")]
	  virtual property System::String^ City
	  {
		  System::String^ get() { return this->_City; }
		  void set(System::String^ value) 
      {
        if ((this->_City != value))
        {
				  this->OnPropertyChanging("City");
				  this->_City = value;
				  this->OnPropertyChanged("City");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Region", Storage = "_Region", DBType = "NVarChar(15)")]
	  virtual property System::String^ Region
	  {
		  System::String^ get() { return this->_Region; }
		  void set(System::String^ value) 
      {
        if ((this->_Region != value))
        {
				  this->OnPropertyChanging("Region");
				  this->_Region = value;
				  this->OnPropertyChanged("Region");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "PostalCode", Storage = "_PostalCode", DBType = "NVarChar(10)")]
	  virtual property System::String^ PostalCode
	  {
		  System::String^ get() { return this->_PostalCode; }
		  void set(System::String^ value) 
      {
        if ((this->_PostalCode != value))
        {
				  this->OnPropertyChanging("PostalCode");
				  this->_PostalCode = value;
				  this->OnPropertyChanged("PostalCode");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Country", Storage = "_Country", DBType = "NVarChar(15)")]
	  virtual property System::String^ Country
	  {
		  System::String^ get() { return this->_Country; }
		  void set(System::String^ value) 
      {
        if ((this->_Country != value))
        {
				  this->OnPropertyChanging("Country");
				  this->_Country = value;
				  this->OnPropertyChanged("Country");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Phone", Storage = "_Phone", DBType = "NVarChar(24)")]
	  virtual property System::String^ Phone
	  {
		  System::String^ get() { return this->_Phone; }
		  void set(System::String^ value) 
      {
        if ((this->_Phone != value))
        {
				  this->OnPropertyChanging("Phone");
				  this->_Phone = value;
				  this->OnPropertyChanged("Phone");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "Fax", Storage = "_Fax", DBType = "NVarChar(24)")]
	  virtual property System::String^ Fax
	  {
		  System::String^ get() { return this->_Fax; }
		  void set(System::String^ value) 
      {
        if ((this->_Fax != value))
        {
				  this->OnPropertyChanging("Fax");
				  this->_Fax = value;
				  this->OnPropertyChanged("Fax");
			  }
		  }
	  }

    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "HomePage", Storage = "_HomePage", DBType = "NText")]
	  virtual property System::String^ HomePage
	  {
		  System::String^ get() { return this->_HomePage; }
		  void set(System::String^ value) 
      {
        if ((this->_HomePage != value))
        {
				  this->OnPropertyChanging("HomePage");
				  this->_HomePage = value;
				  this->OnPropertyChanged("HomePage");
			  }
		  }
	  }

  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		Suppliers()
		{
		}
    
    
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this->PropertyChanging != nullptr))
			{
				this->PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this->PropertyChanged != nullptr))
			{
				this->PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    
  };
} } } 

namespace EeekSoft { namespace CLinq {

  template<> ref class Expr<Suppliers^> : ExpressionWrapper<Suppliers^>
  {
  private:

    DEC_PROPERTY_CACHE(Suppliers, SupplierID, "SupplierID")
    DEC_PROPERTY_CACHE(Suppliers, CompanyName, "CompanyName")
    DEC_PROPERTY_CACHE(Suppliers, ContactName, "ContactName")
    DEC_PROPERTY_CACHE(Suppliers, ContactTitle, "ContactTitle")
    DEC_PROPERTY_CACHE(Suppliers, Address, "Address")
    DEC_PROPERTY_CACHE(Suppliers, City, "City")
    DEC_PROPERTY_CACHE(Suppliers, Region, "Region")
    DEC_PROPERTY_CACHE(Suppliers, PostalCode, "PostalCode")
    DEC_PROPERTY_CACHE(Suppliers, Country, "Country")
    DEC_PROPERTY_CACHE(Suppliers, Phone, "Phone")
    DEC_PROPERTY_CACHE(Suppliers, Fax, "Fax")
    DEC_PROPERTY_CACHE(Suppliers, HomePage, "HomePage")    
  
  public:
    Expr<Suppliers^>() { }
    Expr<Suppliers^>(Expression<Suppliers^>^ value)
		{
			_value = value;
		}
		operator Expression<Suppliers^>^()
		{
			return _value;
		}
    
  public:

    property Expr<int> SupplierID
	  {
		  Expr<int> get() 
      {  return Expr<int>(gcnew PropertyExpression<int>(Property_SupplierID, this)); }
	  }

    property Expr<System::String^> CompanyName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_CompanyName, this)); }
	  }

    property Expr<System::String^> ContactName
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ContactName, this)); }
	  }

    property Expr<System::String^> ContactTitle
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_ContactTitle, this)); }
	  }

    property Expr<System::String^> Address
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Address, this)); }
	  }

    property Expr<System::String^> City
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_City, this)); }
	  }

    property Expr<System::String^> Region
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Region, this)); }
	  }

    property Expr<System::String^> PostalCode
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_PostalCode, this)); }
	  }

    property Expr<System::String^> Country
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Country, this)); }
	  }

    property Expr<System::String^> Phone
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Phone, this)); }
	  }

    property Expr<System::String^> Fax
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_Fax, this)); }
	  }

    property Expr<System::String^> HomePage
	  {
		  Expr<System::String^> get() 
      {  return Expr<System::String^>(gcnew PropertyExpression<System::String^>(Property_HomePage, this)); }
	  }
  };

  template<> ref class Var<Suppliers^> : ExpressionWrapper<Suppliers^>
	{
	public:
		Var<Suppliers^>(System::String^ name)
		{
			_value = gcnew Variable<Suppliers^>(name);
		}
		operator Expression<Suppliers^>^()
		{
			return _value;
		}
	};  
} }

