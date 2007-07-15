<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:user="urn:my-scripts">
<msxsl:script language="C#" implements-prefix="user">
<![CDATA[
  string[] splitparams(string p) {
    return p.Replace('^','_').Replace(':','_').Replace('<','_').Replace('>','_').Replace("... ","").Split(',');
  }

  public string getparameternames(string parameters) {
    string[] ps = parameters.Split(',');
    System.Text.StringBuilder sb = new System.Text.StringBuilder();
    foreach(string op in ps)
    { 
      if (op=="") break; 
      string opt = op.Trim();
      int opi = opt.LastIndexOf(' ');      
      sb.Append(opt.Substring(opi + 1, opt.Length - opi - 1) + ", "); 
    }
    return sb.Length==0?"":(sb.ToString().Substring(0, sb.Length-2));
  }
  
  public string getcacheidentifier(string name, string parameters) {
    string[] ps = splitparams(parameters);
    System.Text.StringBuilder sb = new System.Text.StringBuilder();
    sb.AppendFormat("_{0}_",name);
    foreach(string op in ps)
    { 
      if (op=="") break; 
      string opt = op.Trim();
      int opi = opt.LastIndexOf(' ');      
      sb.Append(opt.Substring(0, opi).Replace(' ', '_')+"_"); 
    }
    return sb.ToString().Substring(0, sb.Length-1);
  }
  
  public string getparametertypes(string parameters, string clrparams) {
    if (clrparams!=null&&clrparams!="") 
      return clrparams;     
    string[] ps = parameters.Split(',');
    System.Text.StringBuilder sb = new System.Text.StringBuilder();
    foreach(string op in ps)
    { 
      if (op=="") break; 
      string opt = op.Trim();
      int opi = opt.LastIndexOf(' ');      
      sb.Append(opt.Substring(0, opi)+"::WrappedType, "); 
    }
    return sb.Length==0?"":(sb.ToString().Substring(0, sb.Length-2));
  }  
  
  public string removerefchar(string ident) {
    if (ident.EndsWith("^")) return ident.Substring(0, ident.Length-1); else return ident;
  }
  
  public string replacetemplatekeys(string str, string tr, string te)
  {
    return str.Replace("$TR", tr).Replace("$TE", te);
  }
]]>
</msxsl:script>

<xsl:template match="/">
<xsl:text disable-output-escaping="yes">
/*****************************************************************************/
/** DO NOT MODIFY THIS FILE                                                 **/
/** generated using xsl transformation: EeekSoft.CLinq.Typed.xsl            **/
/*****************************************************************************/
#pragma once
#include "clinqcore.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Collections::Generic;
using namespace EeekSoft::CLinq;

namespace EeekSoft {
	namespace CLinq {</xsl:text>
    <xsl:apply-templates select="/typed/wrapperClass" />
    <xsl:apply-templates select="/typed/staticClass" />
    <xsl:apply-templates select="/typed/varClass" />
  } 
}
</xsl:template>
  
  
<xsl:template match="varClass">
<xsl:text disable-output-escaping="yes">
    /// &lt;summary&gt;</xsl:text>
    /// <xsl:value-of select="@comment" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">
    /// &lt;/summary&gt;
    template&lt;&gt; public ref class Var&lt;</xsl:text><xsl:value-of select="@type" /><xsl:text disable-output-escaping="yes">&gt; : ExpressionWrapper&lt;</xsl:text><xsl:value-of select="@type" /><xsl:text disable-output-escaping="yes">&gt;
    {
		public:
			Var&lt;</xsl:text><xsl:value-of select="@type" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>(String^ name)
			{
				_value = gcnew Variable<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>(name);
			}
			operator Expression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>^()
			{
				return _value;
			}
		};    
</xsl:template>  
  
<xsl:template match="wrapperClass">
<xsl:variable name="name"><xsl:text disable-output-escaping="yes">Expr&lt;</xsl:text><xsl:value-of select="@type"/><xsl:text disable-output-escaping="yes">&gt;</xsl:text></xsl:variable>
<xsl:text disable-output-escaping="yes">
    /// &lt;summary&gt;</xsl:text>
    /// <xsl:value-of select="@comment" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">
    /// &lt;/summary&gt;
    template&lt;&gt; public ref class Expr&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt; : ExpressionWrapper&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return <xsl:value-of select="user:removerefchar(@type)" disable-output-escaping="yes" />::typeid; } }
    
		public:
			<xsl:value-of select="$name" disable-output-escaping="yes" />() { }
      <xsl:if test="@literal='true'">
			<xsl:value-of select="$name" disable-output-escaping="yes" />(<xsl:value-of select="@type" disable-output-escaping="yes" /> val) { _value = gcnew Literal<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>(val); }
      </xsl:if>
			<xsl:value-of select="$name" disable-output-escaping="yes" />(Expression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>^ value) { _value = value; }
			<xsl:value-of select="$name" disable-output-escaping="yes" />(<xsl:value-of select="$name" disable-output-escaping="yes" />% b)	{ _value = b._value; }
			operator Expression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator <xsl:value-of select="$name" disable-output-escaping="yes" />(Expression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>^ value)  { return <xsl:value-of select="$name" disable-output-escaping="yes" />(value); }
			static operator <xsl:value-of select="$name" disable-output-escaping="yes" />(<xsl:value-of select="@type" disable-output-escaping="yes" /> b) { return <xsl:value-of select="$name" disable-output-escaping="yes" />(b); }
      
      <xsl:for-each select="conversion">
      operator Expr<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@to" /><xsl:text disable-output-escaping="yes">&gt;() { return Expr&lt;</xsl:text><xsl:value-of select="@to" /><xsl:text disable-output-escaping="yes">&gt;::Convert(_value); }</xsl:text></xsl:for-each>

    public:
    static <xsl:value-of select="$name" disable-output-escaping="yes" /> Typed(GenericExpression^ value) 
      { 
        return <xsl:value-of select="$name" disable-output-escaping="yes" />(gcnew TypedExpression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>(value));
      }

      static <xsl:value-of select="$name" disable-output-escaping="yes" /> Convert(GenericExpression^ value) 
      { 
        return <xsl:value-of select="$name" disable-output-escaping="yes" />(gcnew ConvertExpression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@type" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">&gt;</xsl:text>(value));
      }

    public:
      <!-- standard -->
      <xsl:for-each select="operator">
        <xsl:call-template name="operator" />
      </xsl:for-each>

      <!-- copy from template -->
      <xsl:variable name="TE" select="$name" />
      <xsl:variable name="TR" select="@type" />
      <xsl:for-each select="include">
        <xsl:variable name="tn" select="@template" />
        <xsl:for-each select="/typed/template[@name=$tn]/operator">
          <xsl:call-template name="operator">
            <xsl:with-param name="TR" select="$TR" />
            <xsl:with-param name="TE" select="$TE" />
          </xsl:call-template>
        </xsl:for-each>
      </xsl:for-each>
  
    public:
      <xsl:apply-templates select="method" />
    };
    
</xsl:template>

<xsl:template match="staticClass">
<xsl:text disable-output-escaping="yes">
    /// &lt;summary&gt;</xsl:text>
    /// <xsl:value-of select="@comment" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">
    /// &lt;/summary&gt;
    template&lt;&gt; public ref class Expr&lt;</xsl:text><xsl:value-of select="@type" /><xsl:text disable-output-escaping="yes">^&gt;
    {
    private:
      Expr&lt;</xsl:text><xsl:value-of select="@type" /><xsl:text disable-output-escaping="yes">^&gt;</xsl:text>() { }
      
    public:
      <xsl:apply-templates select="operator" />
  
    public:
      <xsl:apply-templates select="method" />
    };
    
</xsl:template>
  
<xsl:template match="operator" name="operator">
<xsl:param name="TR" />
<xsl:param name="TE" />
<xsl:variable name="parameters" select="user:replacetemplatekeys(@parameters,$TR,$TE)" />
<xsl:variable name="ntype" select="user:replacetemplatekeys(@ntype,$TR,$TE)" />
<xsl:variable name="wtype" select="user:replacetemplatekeys(@wtype,$TR,$TE)" />
<xsl:variable name="comment" select="user:replacetemplatekeys(@comment,$TR,$TE)" />
<xsl:text disable-output-escaping="yes">
      /// &lt;summary&gt;</xsl:text>
      /// <xsl:value-of select="$comment" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">
      /// &lt;/summary&gt;
      </xsl:text><xsl:if test="@static='true'">static </xsl:if><xsl:value-of select="$wtype" disable-output-escaping="yes"/> operator<xsl:value-of select="@name" disable-output-escaping="yes" />(<xsl:value-of select="$parameters" disable-output-escaping="yes"/>)
      {
        return <xsl:value-of select="$wtype" disable-output-escaping="yes"/>(gcnew <xsl:value-of select="@arity"/><xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="$ntype" disable-output-escaping="yes"/><xsl:text disable-output-escaping="yes">&gt;</xsl:text>
          (<xsl:value-of select="user:getparameternames($parameters)" disable-output-escaping="yes"/>, System::Expressions::ExpressionType::<xsl:value-of select="@type" disable-output-escaping="yes" />));
      }
</xsl:template>
  
<xsl:template match="method">
    private:
    	static MethodInfo^ _<xsl:value-of select="user:getcacheidentifier(@name,@parameters)"/>;
    	static property MethodInfo^ <xsl:value-of select="user:getcacheidentifier(@name,@parameters)"/> { 
        MethodInfo^ get() { if (_<xsl:value-of select="user:getcacheidentifier(@name,@parameters)"/> == nullptr) 
          _<xsl:value-of select="user:getcacheidentifier(@name,@parameters)"/> = (<xsl:value-of select="user:removerefchar(../@type)" /><xsl:text disable-output-escaping="yes">::typeid)->GetMethod("</xsl:text><xsl:value-of select="@name"/>", gcnew array<xsl:text disable-output-escaping="yes">&lt;Type^&gt;</xsl:text>{ <xsl:value-of select="user:getparametertypes(@parameters,@exparams)" disable-output-escaping="yes" /> }); return _<xsl:value-of select="user:getcacheidentifier(@name,@parameters)"/>; 
        } }
    public:<xsl:text disable-output-escaping="yes">
      /// &lt;summary&gt;</xsl:text>
      /// <xsl:value-of select="@comment" disable-output-escaping="yes" /><xsl:text disable-output-escaping="yes">
      /// &lt;/summary&gt;
      </xsl:text><xsl:if test="@static='true'"><xsl:text>static </xsl:text></xsl:if><xsl:value-of select="@wtype" disable-output-escaping="yes" /><xsl:text> </xsl:text><xsl:value-of select="@name" />(<xsl:value-of select="@parameters" disable-output-escaping="yes" />)
  		{
	  		return <xsl:value-of select="@wtype" disable-output-escaping="yes" />(gcnew MethodInvokeExpression<xsl:text disable-output-escaping="yes">&lt;</xsl:text><xsl:value-of select="@ntype"/><xsl:text disable-output-escaping="yes">&gt;
          (</xsl:text><xsl:value-of select="user:getcacheidentifier(@name,@parameters)"/><xsl:text disable-output-escaping="yes">, </xsl:text><xsl:if test="@static='true'">nullptr</xsl:if><xsl:if test="not(@static='true')">this</xsl:if>
            <xsl:if test="not(boolean(@exparamconv))"><xsl:text disable-output-escaping="yes">, gcnew array&lt;GenericExpression^&gt;{</xsl:text><xsl:value-of select="user:getparameternames(@parameters)" disable-output-escaping="yes"/>}</xsl:if>
            <xsl:if test="boolean(@exparamconv)"><xsl:text disable-output-escaping="yes">, gcnew array&lt;GenericExpression^&gt;{</xsl:text> gcnew <xsl:value-of select="@exparamconv" disable-output-escaping="yes" />(<xsl:value-of select="user:getparameternames(@parameters)" disable-output-escaping="yes"/>) }</xsl:if>));
      }
</xsl:template>  
</xsl:stylesheet>
