<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
  xmlns:msxsl="urn:schemas-microsoft-com:xslt"
  xmlns:user="urn:my-scripts">
  <msxsl:script language="C#" implements-prefix="user">
  <![CDATA[
  public string getidentifier(string id) {
    return id.Replace(' ', '_');
  }
  
  private string makenullable(string name, bool nullable)
  {
    if (nullable) return "System::Nullable<"+name+">"; else return name;
  }
  
  private string typename(string name, bool nullable, out bool gennullable) 
  {
    gennullable = nullable;
    switch(name)
    {
      case "System.Boolean": return makenullable("bool", nullable);
      case "System.Char": return makenullable("wchar_t", nullable);
      case "System.SByte": return makenullable("signed char", nullable);
      case "System.Byte": return makenullable("unsigned char", nullable);
      case "System.Int16": return makenullable("short", nullable);
      case "System.UInt16": return makenullable("unsigned short", nullable);
      case "System.Int32": return makenullable("int", nullable);
      case "System.UInt32": return makenullable("unsigned int", nullable);
      case "System.Int64": return makenullable("long long int", nullable);
      case "System.UInt64": return makenullable("unsigned long long int", nullable);
      case "System.Single": return makenullable("float", nullable);
      case "System.Double": return makenullable("double", nullable);
      case "System.DateTime": return makenullable("System::DateTime", nullable);
      case "System.Decimal": return makenullable("System::Decimal", nullable);
      case "System.String": gennullable=false; return "System::String^";
      default:
        if (name.IndexOf("[]")>0)
        {
          return makenullable("array<"+typename(name.Replace("[]",""), nullable)+">^", nullable);
        }
        else
          return makenullable(name.Replace(".", "::")+"^", nullable);
    }
  }
  
  public string typename(string name, bool nullable) 
  {
    bool tmp;
    return typename(name, nullable, out tmp);
  }
  
  public bool isnullable(string name, bool nullable) 
  {
    bool tmp;
    typename(name, nullable, out tmp);
    return tmp;
  }  
  
  public bool isnotnullable(string name, bool nullable) 
  {
    return !isnullable(name, nullable);
  }    
  
  public string getclinqret(string type)
  {
    string[] ts = new string[] { "bool", "wchar_t", "signed char", "unsigned char", "short",
      "unsigned short", "int", "unsigned int", "long long int", "unsigned long long int",
      "float", "double", "System::DateTime", "System::Decimal", "System::String^",
      "DateTime", "Decimal", "String^" };
    foreach(string s in ts)
    {
      if (type == s || type == ("Nullable<"+s+">") || type == ("System::Nullable<"+s+">"))
        return string.Format("Expr<{0}>", type);
    }
    return string.Format("Expression<{0}>^", type);
  }
  
  public string getclinqretcode(string type)
  {
    string[] ts = new string[] { "bool", "wchar_t", "signed char", "unsigned char", "short",
      "unsigned short", "int", "unsigned int", "long long int", "unsigned long long int",
      "float", "double", "System::DateTime", "System::Decimal", "System::String^",
      "DateTime", "Decimal", "String^" };
    foreach(string s in ts)
    {
      if (type == s || type == ("Nullable<"+s+">") || type == ("System::Nullable<"+s+">"))
        return string.Format("Expr<{0}>", type);
    }
    return string.Format("", type);
  }  
  ]]>
</msxsl:script>
<xsl:template match="/">
  <xsl:text disable-output-escaping="yes">#define DEC_PROPERTY_CACHE(otype, name, sname) \
	static System::Reflection::PropertyInfo^ _ ## name; \
	static property System::Reflection::PropertyInfo^ Property_ ## name { System::Reflection::PropertyInfo^ get() { if (_ ## name == nullptr) _ ## name = (otype::typeid)->GetProperty(sname); return _ ## name; } }

using namespace EeekSoft::CLinq;
</xsl:text>

  <xsl:for-each select="/Database/Namespace">namespace <xsl:value-of select="."/> { </xsl:for-each>
    <xsl:for-each select="/Database/Schema/Table">
    ref class <xsl:value-of select="user:getidentifier(@Name)"/>;</xsl:for-each>
    
    ref class <xsl:value-of select="/Database/@classname" disable-output-escaping="yes" /> : System::Data::DLinq::DataContext
    {
    public:
      <xsl:for-each select="/Database/Schema/Table"><xsl:text disable-output-escaping="yes">System::Data::DLinq::Table&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;^ </xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>;
      </xsl:for-each>

    <xsl:for-each select="/Database/Schema/Table"><xsl:text disable-output-escaping="yes">
      property CQuery&lt;</xsl:text><xsl:for-each select="/Database/Namespace"><xsl:value-of select="."/>::</xsl:for-each><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;^ Q</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>
      {
        <xsl:text disable-output-escaping="yes">CQuery&lt;</xsl:text><xsl:for-each select="/Database/Namespace"><xsl:value-of select="."/>::</xsl:for-each><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;^ get() 
        { 
          return gcnew CQuery&lt;</xsl:text><xsl:for-each select="/Database/Namespace"><xsl:value-of select="."/>::</xsl:for-each><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;(</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>);
        }
      };
    </xsl:for-each>
    <xsl:text disable-output-escaping="yes">
    
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
</xsl:text>
<xsl:for-each select="/Database/Namespace">} </xsl:for-each><xsl:text>

using namespace </xsl:text><xsl:for-each select="/Database/Namespace"><xsl:if test="position()&gt;1">::</xsl:if><xsl:value-of select="."/></xsl:for-each><xsl:text>;
</xsl:text>
<xsl:for-each select="/Database/Schema/Table"><xsl:text>
</xsl:text><xsl:for-each select="/Database/Namespace">namespace <xsl:value-of select="."/> { </xsl:for-each>
  
  [System::Data::DLinq::TableAttribute(Name = "<xsl:value-of select="@Name"/>")]
  ref class <xsl:value-of select="user:getidentifier(@Name)"/>
  {
  private:
<xsl:for-each select="Column"><xsl:text disable-output-escaping="yes">
    </xsl:text><xsl:value-of select="user:typename(@Type,@Nullable)" disable-output-escaping="yes" /> _<xsl:value-of select="user:getidentifier(@Name)"/>;</xsl:for-each>
  public:
<xsl:for-each select="Column">
    [System::Diagnostics::DebuggerNonUserCodeAttribute()]
	  [System::Data::DLinq::Column(Name = "<xsl:value-of select="@Name"/>", Storage = "_<xsl:value-of select="@Name"/>", DBType = "<xsl:value-of select="@DbType"/>"<xsl:if test="@IsIdentity='true'">, Id = true</xsl:if><xsl:if test="@IsAutoGen='true'">, AutoGen = true</xsl:if>)]
	  virtual property <xsl:value-of select="user:typename(@Type,@Nullable)" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes"> </xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>
	  {
		  <xsl:value-of select="user:typename(@Type,@Nullable)" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes"> get() { return this-&gt;_</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>; }
		  void set(<xsl:value-of select="user:typename(@Type,@Nullable)" disable-output-escaping="yes" /> value) 
      {
        <xsl:if test="user:isnotnullable(@Type,@Nullable)"><xsl:text disable-output-escaping="yes">if ((this-&gt;_</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/> != value))</xsl:if>
        <xsl:if test="user:isnullable(@Type,@Nullable)">if ((<xsl:text disable-output-escaping="yes">this-&gt;_</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>.HasValue != value.HasValue) || (<xsl:text disable-output-escaping="yes">this-&gt;_</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">.HasValue &amp;&amp; (this-&gt;_</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>.GetValueOrDefault() != value.GetValueOrDefault())))</xsl:if>
        {
				  <xsl:text disable-output-escaping="yes">this-&gt;OnPropertyChanging</xsl:text>("<xsl:value-of select="user:getidentifier(@Name)"/>");
				  <xsl:text disable-output-escaping="yes">this-&gt;_</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/> = value;
				  <xsl:text disable-output-escaping="yes">this-&gt;OnPropertyChanged("</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>");
			  }
		  }
	  }
</xsl:for-each>
  public:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		<xsl:value-of select="user:getidentifier(@Name)"/>()
		{
		}
    
    <xsl:text disable-output-escaping="yes">
		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanging;

		System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

  protected:
		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanging(System::String^ propertyName)
		{
			if ((this-&gt;PropertyChanging != nullptr))
			{
				this-&gt;PropertyChanging(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}

		[System::Diagnostics::DebuggerNonUserCodeAttribute()]
		virtual void OnPropertyChanged(System::String^ propertyName)
		{
			if ((this-&gt;PropertyChanged != nullptr))
			{
				this-&gt;PropertyChanged(this, gcnew System::ComponentModel::PropertyChangedEventArgs(propertyName));
			}
		}    
    </xsl:text>
  };
<xsl:for-each select="/Database/Namespace">} </xsl:for-each>

namespace EeekSoft { namespace CLinq {
<xsl:variable name="ename"><xsl:text disable-output-escaping="yes">Expr&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;</xsl:text></xsl:variable>
<xsl:variable name="vname"><xsl:text disable-output-escaping="yes">Var&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;</xsl:text></xsl:variable>
  template<xsl:text disable-output-escaping="yes">&lt;&gt; ref class </xsl:text><xsl:value-of select="$ename" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes"> : ExpressionWrapper&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;</xsl:text>
  {
  private:
<xsl:for-each select="Column">
    DEC_PROPERTY_CACHE(<xsl:value-of select="user:getidentifier(../@Name)"/>, <xsl:value-of select="user:getidentifier(@Name)"/>, "<xsl:value-of select="user:getidentifier(@Name)"/>")</xsl:for-each>    
  
  public:
    <xsl:value-of select="$ename" disable-output-escaping="yes" />() { }
    <xsl:value-of select="$ename" disable-output-escaping="yes" />(Expression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;^</xsl:text> value)
		{
			_value = value;
		}
		operator Expression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>^<xsl:text disable-output-escaping="yes">&gt;</xsl:text>^()
		{
			return _value;
		}
    
  public:
<xsl:for-each select="Column">
    property <xsl:value-of select="user:getclinqret(user:typename(@Type,@Nullable))" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes"> </xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>
	  {
		  <xsl:value-of select="user:getclinqret(user:typename(@Type,@Nullable))" disable-output-escaping="yes" /> get() 
      {  return <xsl:value-of disable-output-escaping="yes" select="user:getclinqretcode(user:typename(@Type,@Nullable))" /><xsl:text disable-output-escaping="yes">(gcnew PropertyExpression&lt;</xsl:text><xsl:value-of select="user:typename(@Type,@Nullable)" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;(Property_</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">, this));</xsl:text> }
	  }
</xsl:for-each>
<xsl:text disable-output-escaping="yes">  };

  template&lt;&gt; ref class </xsl:text><xsl:value-of select="$vname" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes"> : ExpressionWrapper&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/><xsl:text disable-output-escaping="yes">^&gt;</xsl:text>
	{
	public:
		<xsl:value-of select="$vname" disable-output-escaping="yes" />(System::String^ name)
		{
			_value = gcnew Variable<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>^<xsl:text disable-output-escaping="yes">&gt;</xsl:text>(name);
		}
		operator Expression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="user:getidentifier(@Name)"/>^<xsl:text disable-output-escaping="yes">&gt;</xsl:text>^()
		{
			return _value;
		}
	};  
} }

</xsl:for-each>
</xsl:template>
</xsl:stylesheet> 
