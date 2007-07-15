// EeekSoft.CLinq.CodeGen.cpp : main project file.

using namespace System;
using namespace System::IO;
using namespace System::Xml;
using namespace System::Xml::Xsl;
using namespace System::Resources;
using namespace System::Reflection;

ref class Generator
{
public:
	static void ShowHelp()
	{
		Console::WriteLine("usage: clinqgen [options] /out:<output file> [<intput file>]");
		Console::WriteLine("options:");
		Console::WriteLine(" /out:<file name>   name of the generated header file");
		Console::WriteLine(" /namespace:<name>  specifies target namespace (in the 'Some.Namespace' format)");
		Console::WriteLine(" /class:<name>		  name of the generated class");
	}

private:
	String ^_ns, ^_cls, ^_outf;
	XmlDocument ^_doc;
	
public:
	Generator(String^ ns, String^ cls, XmlDocument^ doc, String^ outf)
	{
		_outf = outf; _cls = cls; _doc = doc; _ns = ns;
	}

	void GenerateCode()
	{
		array<String^>^ ns_parts = _ns->Split('.');

		XmlAttribute^ a = _doc->CreateAttribute("classname");
		a->Value = _cls;
		_doc->DocumentElement->Attributes->Append(a);

		for(int i=0; i<ns_parts->Length; i++)
		{
			if (ns_parts[i]->Trim()->Length == 0) continue;
			XmlElement^ el = _doc->CreateElement("Namespace");
			el->InnerText = ns_parts[i];
			_doc->DocumentElement->AppendChild(el);
		}

		XsltSettings^ stg = gcnew XsltSettings();
    stg->EnableScript = true;
		XslCompiledTransform^ xslt = gcnew XslCompiledTransform();
		XmlTextReader reader(Assembly::GetExecutingAssembly()->GetManifestResourceStream("transform.xslt"));
		xslt->Load(%reader, stg, gcnew XmlUrlResolver());
		XmlTextWriter^ wr = gcnew XmlTextWriter(gcnew StreamWriter(_outf));
		xslt->Transform(_doc, wr);
	}
};

int main(array<System::String ^> ^args)
{
	String^ outf = "";
	String^ inf = "";
	String^ ns = "";
	String^ cls = "";
	if (args->Length < 1)
	{
		Generator::ShowHelp();
		return 0;
	}
	for(int i = 0; i < args->Length; i++)
	{
		if (args[i]->StartsWith("/out:")) outf = args[i]->Substring(5);
		else if (args[i]->StartsWith("/namespace:")) ns = args[i]->Substring(11);
		else if (args[i]->StartsWith("/class:")) cls = args[i]->Substring(7);
		else if (i == args->Length - 1) inf = args[i];
	}

	XmlDocument^ doc = gcnew XmlDocument();
	if (inf == "")
		doc->Load(Console::In);
	else
		doc->Load(inf);
	
	if (cls == "") cls = System::IO::Path::GetFileNameWithoutExtension(outf);
	(gcnew Generator(ns, cls, doc, outf))->GenerateCode();
}
