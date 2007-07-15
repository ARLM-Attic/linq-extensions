<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:msxsl="urn:schemas-microsoft-com:xslt" xmlns:user="urn:my-scripts">
  <xsl:output method="html" />
  <msxsl:script language="C#" implements-prefix="user">
   <![CDATA[
  public string getsafename(string type) {
    return type.Replace('^', '_').Replace(':', '_').Replace(' ', '_');
  }
  
  public string formattype(string tn) {
    string[] std = new string[] { "unsigned char","unsigned char","signed char","float","double","long long int",
      "short","int","unsigned long long int","unsigned short","unsigned int","bool","wchar_t" };
    if (Array.IndexOf(std,tn)>=0) return string.Format("<span class=\"k\">{0}</span>", tn); else return tn.Replace("&","&amp;").Replace(">","&gt;").Replace("<","&lt;");
  }
  
  public string formatspecial(string tn) {
    string[] std = new string[] { "Expr", "Var" };
    if (Array.IndexOf(std,tn)>=0) return string.Format("<span class=\"w\">{0}</span>", tn); else return tn;
  }  
  
  public string replacetemplatekeys(string str, string tr, string te) {
    return str.Replace("$TR", tr).Replace("$TE", te);
  }  
  
  public string formatwtype(string type) {
    System.Text.RegularExpressions.Regex reg = new System.Text.RegularExpressions.Regex("(?<pre>[^<]*)<(?<in>[^>]*)>(?<post>.*)");
    System.Text.RegularExpressions.Match m = reg.Match(type);
    if (!m.Success) 
      return formattype(type);
    else
      return formatspecial(m.Groups["pre"].Value)+"&lt;"+formattype(m.Groups["in"].Value)+"&gt;"+m.Groups["post"].Value;
  }
  
  public string getparametertypes(string parameters) {
    string[] ps = parameters.Split(',');
    System.Text.StringBuilder sb = new System.Text.StringBuilder();
    foreach(string op in ps)
    { 
      if (op=="") break; 
      sb.Append(formatwtype(op.Trim()));
      sb.Append(", ");
    }
    return sb.Length==0?"":(sb.ToString().Substring(0, sb.Length-2));
  }    
]]>
  </msxsl:script>

  <xsl:template match="/">
    <html>
      <head>
        <title>CLinq classes</title>
        <style type="text/css">
          <![CDATA[
          body { font:100% calibri, sans-serif; }
          th, td { padding-left:10px; padding-right:10px; text-align:left; }
          table { margin-left: 30px; }
          p.s { margin:0px; font-weight:bold; }
          code.s, span.s { color:#808000; }
          code.c, span.c { color:#008000; }
          code.k, span.k { color:#0000a0; }
          code.w, span.w { color:#008080; }
          code, pre { font:80% consolas, 'courier new', monospace; }
          h1 { text-align:center;  }
          h2.hr { border-bottom:dashed 2px #aaaaaa; }
          td.ico { width: 35px; }
          td.code { width: 400px; }
          ]]>
        </style>
      </head>
      <body>
        <h1>
          <a id="doc">CLinq classes</a>
        </h1>
        <h2>CLinq core classes</h2>
        <p>
          <code>CQuery</code> is a class that represents data query. This class contain several methods for
          constructing queries, like <code>Where</code>, <code>Select</code>, <code>Average</code> and other
          (these methods are called query operators in LINQ terminology).
        </p>
        <table>
          <tr>
            <th></th>
            <th>Class name</th>
            <th>Description</th>
          </tr>
          <xsl:for-each select="/typed/docSpecialClass">
            <xsl:call-template name="classTable">
              <xsl:with-param name="owner">Special</xsl:with-param>
            </xsl:call-template>
          </xsl:for-each>
        </table>
        
        <h2>Wrapper classes</h2>
        <p>
          Wrapper classes are type-safe wrappers for all standard C++/CLI types. You can use wrapper classes in 
          your code when writing expressions instead of <code>Expression&lt;T&gt;</code> to make the code more readable. Wrapper
          classes also override standard operators that are available for every type and can contain methods (for
          example <code>EString::Substring</code> etc.). The following wrapper classes are included in CLinq:
        </p>
        <table>
          <tr>
            <th></th>
            <th>Wrapper class</th>
            <th>Description</th>
          </tr>
          <xsl:for-each select="/typed/wrapperClass | /typed/docWrapperClass">
            <xsl:call-template name="classTable">
              <xsl:with-param name="owner">Expr</xsl:with-param>
            </xsl:call-template>
          </xsl:for-each>
        </table>
        <h2>Variable classes</h2>
        <p>
          Variable classes represent typed variable of specific type and are declared for all standard C++/CLI types.
          You can use variable classes instead of <code>Variable&lt;T&gt;</code> if you want to make code more readable. Please
          note that variable classes can be converted to wrapper classes using assignment. The following variable
          classes are included in CLinq:
        </p>
        <table>
          <tr>
            <th></th>
            <th>Variable class</th>
            <th>Description</th>
          </tr>
          <xsl:for-each select="/typed/varClass">
            <xsl:call-template name="classTable">
              <xsl:with-param name="owner">Var</xsl:with-param>
            </xsl:call-template>
          </xsl:for-each>
        </table>
        <h2>Static classes</h2>
        <p>
          Static classes contains methods that can be used in CLinq expression and accept wrapper classes
          as a parameters. The following static classes are included in CLinq (click on the class to see list of
          its methods):
        </p>
        <table>
          <tr>
            <th></th>
            <th>Static class</th>
            <th>Description</th>
          </tr>
          <xsl:for-each select="/typed/staticClass">
            <xsl:call-template name="classTable">
              <xsl:with-param name="owner">Expr</xsl:with-param>
            </xsl:call-template>
          </xsl:for-each>
        </table>
        <h1>Detailed information</h1>
        <h2 class="hr">CLinq core classes</h2>
        <xsl:apply-templates select="/typed/docSpecialClass" />
        <h2 class="hr">Wrapper classes</h2>
        <xsl:apply-templates select="/typed/wrapperClass | /typed/docWrapperClass" />
        <h2 class="hr">Variable classes</h2>
        <xsl:apply-templates select="/typed/varClass" />
        <h2 class="hr">Static classes</h2>
        <xsl:apply-templates select="/typed/staticClass" />
      </body>
    </html>
  </xsl:template>

  <xsl:template name="classTable">
    <xsl:param name="owner" />
    <tr>
      <td>
        <img src="class.png" alt="Class" />
      </td>
      <td>
        <a>
          <xsl:attribute name="href">#<xsl:value-of select="$owner" />_<xsl:value-of select="user:getsafename(@type)" /></xsl:attribute>
          <xsl:if test="$owner='Special'">
            <xsl:value-of select="@name" />
          </xsl:if>
          <xsl:if test="not($owner='Special')">
            <span calss="w"><xsl:value-of select="$owner" /></span>&lt;<xsl:value-of select="@type" />&gt;
          </xsl:if>
        </a>
      </td>
      <td>
        <xsl:value-of select="@comment" />
      </td>
    </tr>
  </xsl:template>
  
  <xsl:template match="varClass">
    <h3>
      <a>
        <xsl:attribute name="id">Var_<xsl:value-of select="user:getsafename(@type)" /></xsl:attribute>
        Var&lt;<xsl:value-of select="@type" />&gt;
      </a>
    </h3>
    <p>
      <xsl:value-of select="@comment" />
    </p>
    <p class="s">Sample:</p>
<pre>
<span class="c">// Create CLinq variable of type '<xsl:value-of select="@type" />'</span><br />
  <span class="w">Expr</span>&lt;<xsl:value-of disable-output-escaping="yes" select="user:formattype(@type)" />&gt;  var = <span class="w">Var</span>&lt;<xsl:value-of disable-output-escaping="yes" select="user:formattype(@type)" />&gt;(<span class="s">"var"</span>);<xsl:text>

</xsl:text><span class="c">// Variables can be converted to Expression&lt;T&gt; type, so when you have a function
// that accepts coresponding expression, you can call it like this:</span><br />
<span class="k">void</span> UseExpr(Expression&lt;<xsl:value-of disable-output-escaping="yes" select="user:formattype(@type)" />&gt; expr) { <span class="c">/* ... */</span> }
UseExpr(var);
</pre>
<a href="#doc">Back to top</a>
  </xsl:template>

  <xsl:template match="wrapperClass | staticClass | docWrapperClass | docSpecialClass">
    <h3>
      <a>
        <xsl:if test="name(.)='docSpecialClass'">
          <xsl:attribute name="id">Special_<xsl:value-of select="user:getsafename(@type)" /></xsl:attribute>
          <xsl:value-of select="@name" />
        </xsl:if>
        <xsl:if test="not(name(.)='docSpecialClass')">
          <xsl:attribute name="id">Expr_<xsl:value-of select="user:getsafename(@type)" /></xsl:attribute>
          Expr&lt;<xsl:value-of select="@type" />&gt;
        </xsl:if>
      </a>
    </h3>
    <p>
      <xsl:value-of select="@comment" />
    </p>
    <xsl:if test="count(property) &gt; 0">
    <h4>Properties</h4>
    <table>
    <xsl:for-each select="property">
      <xsl:call-template name="property" />
    </xsl:for-each>
    </table>
    </xsl:if>    
    
    <xsl:if test="name(.) = 'wrapperClass'">
    <h4>Operators</h4>
    <table>
    <xsl:for-each select="operator">
      <xsl:call-template name="operator" />
    </xsl:for-each>
    <xsl:variable name="TE">Expr&lt;<xsl:value-of select="@type"/>&gt;</xsl:variable>
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
    </table>
    </xsl:if>

    <xsl:if test="count(method) &gt; 0">
    <h4>Methods</h4>
    <table>
    <xsl:for-each select="method">
      <xsl:call-template name="method" />
    </xsl:for-each>
    <xsl:variable name="TE">Expr&lt;<xsl:value-of select="@type"/>&gt;</xsl:variable>
    <xsl:variable name="TR" select="@type" />
    <xsl:for-each select="include">
      <xsl:variable name="tn" select="@template" />
      <xsl:for-each select="/typed/template[@name=$tn]/method">
        <xsl:call-template name="method">
          <xsl:with-param name="TR" select="$TR" />
          <xsl:with-param name="TE" select="$TE" />
        </xsl:call-template>
      </xsl:for-each>
    </xsl:for-each>
    </table>
    </xsl:if>
    
    
    <a href="#doc">Back to top</a>
  </xsl:template>

  <xsl:template name="operator">
    <xsl:param name="TR" />
    <xsl:param name="TE" />
    <xsl:variable name="parameters" select="user:replacetemplatekeys(@parameters,$TR,$TE)" />
    <xsl:variable name="ntype" select="user:replacetemplatekeys(@ntype,$TR,$TE)" />
    <xsl:variable name="wtype" select="user:replacetemplatekeys(@wtype,$TR,$TE)" />
    <xsl:variable name="comment" select="user:replacetemplatekeys(@comment,$TR,$TE)" />
    <tr>
      <td class="ico">
        <xsl:if test="@static='true'"><img src="static.png" alt="Static member" /></xsl:if>
        <img src="operator.png" alt="Operator" />
      </td>
      <td class="code">
        <code>
          <xsl:value-of select="user:formatwtype($wtype)" disable-output-escaping="yes"/><span class="k"> operator </span><xsl:value-of select="@name" />
          (<xsl:value-of select="user:getparametertypes($parameters)" disable-output-escaping="yes"/>)
        </code>
      </td>
      <td>
        <xsl:value-of select="$comment" />
      </td>
    </tr>
  </xsl:template>

  <xsl:template name="method">
    <xsl:param name="TR" />
    <xsl:param name="TE" />
    <xsl:variable name="parameters" select="user:replacetemplatekeys(@parameters,$TR,$TE)" />
    <xsl:variable name="ntype" select="user:replacetemplatekeys(@ntype,$TR,$TE)" />
    <xsl:variable name="wtype" select="user:replacetemplatekeys(@wtype,$TR,$TE)" />
    <xsl:variable name="comment" select="user:replacetemplatekeys(@comment,$TR,$TE)" />
    <tr>
      <td class="ico">
        <xsl:if test="@static='true'"><img src="static.png" alt="Static member" /></xsl:if>
        <img src="method.png" alt="Method" />
      </td>
      <td class="code">
        <code>
          <xsl:value-of select="user:formatwtype($wtype)" disable-output-escaping="yes"/><xsl:text> </xsl:text><xsl:value-of select="@name" />
          (<xsl:value-of select="user:getparametertypes($parameters)" disable-output-escaping="yes"/>)
        </code>
      </td>
      <td>
        <xsl:value-of select="$comment" />
      </td>
    </tr>
    
  </xsl:template>

  <xsl:template name="property">
    <tr>
      <td class="ico">
        <xsl:if test="@static='true'">
          <img src="static.png" alt="Static member" />
        </xsl:if>
        <img src="property.png" alt="property" />
      </td>
      <td class="code">
        <code>
          <xsl:value-of select="user:formatwtype(@wtype)" disable-output-escaping="yes"/><xsl:text> </xsl:text><xsl:value-of select="@name" />
        </code>
      </td>
      <td>
        <xsl:value-of select="@comment" />
      </td>
    </tr>

  </xsl:template>  
</xsl:stylesheet>
