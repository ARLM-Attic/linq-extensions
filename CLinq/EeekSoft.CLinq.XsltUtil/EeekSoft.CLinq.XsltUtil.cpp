// EeekSoft.CLinq.XsltUtil.cpp : main project file.

using namespace System;
using namespace System::IO;
using namespace System::Xml;
using namespace System::Xml::Xsl;

int main(array<System::String ^> ^args)
{
	if (args->Length != 2) 
	{
		Console::WriteLine(L"xsltutil <input_xml> <input_xsl>");
    return 0;
	}

	XsltSettings stg;
  stg.EnableScript = true;

	XslCompiledTransform xslt;
	xslt.Load(args[1], %stg, gcnew XmlUrlResolver());
	XmlDocument doc;
	doc.Load(args[0]);
	XmlTextWriter wr(Console::Out);
	xslt.Transform(%doc, %wr);
}
