// EeekSoft.CLinq.Utlis.h

#pragma once

using namespace System;
using namespace System::Text;
using namespace System::Expressions;
using namespace System::Reflection;
using namespace System::Collections::Generic;

namespace EeekSoft {
	namespace CLinq {

		/// <summary> 
		/// Returns CLinq exception
		/// </summary>
		[Serializable]
		public ref class CLinqException : Exception
		{
		public:
			CLinqException() { }
			CLinqException(String^ message) : Exception(message) { }
			CLinqException(String^ message, Exception^ inner) : Exception(message, inner) { }
		protected:
			CLinqException(System::Runtime::Serialization::SerializationInfo^ info,
				System::Runtime::Serialization::StreamingContext context) : Exception(info, context) { }
		};


		/// <summary> 
		/// Attribute that is used for mapping constructor parameters to object properties
		/// </summary>
		[AttributeUsage(AttributeTargets::Parameter, AllowMultiple = false)]
		public ref class PropMapAttribute : Attribute
		{
			String^ _prop;
		public:

			PropMapAttribute(String^ prop)
			{
				_prop = prop;
			}

			property String^ Property
			{
				String^ get() { return _prop; }
			}
		};

} }