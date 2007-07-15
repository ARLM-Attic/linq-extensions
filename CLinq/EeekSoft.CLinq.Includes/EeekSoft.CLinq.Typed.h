
/*****************************************************************************/
/** DO NOT MODIFY THIS FILE                                                 **/
/** generated using xsl transformation: EeekSoft.CLinq.Typed.xsl            **/
/*****************************************************************************/

#pragma once
#include "EeekSoft.CLinq.h"
#include "EeekSoft.CLinq.Utils.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Collections::Generic;

namespace EeekSoft {
	namespace CLinq {
    /// <summary>
    /// Type safe wrapper for the 'bool' expresion. Implements operators !=, == and logical operators (&amp;&amp;, ||) and unary !.
    /// </summary>
    public ref class EBool : ExpressionWrapper<bool>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return bool::typeid; } }
    
		public:
			EBool() { }
      EBool(bool val) { _value = gcnew Literal<bool>(val); }
      EBool(Expression<bool>^ value) { _value = value; }
			EBool(EBool% b)	{ _value = b._value; }
			operator Expression<bool>^() { return _value; }
			static operator EBool(Expression<bool>^ value)  { return EBool(value); }
			static operator EBool(bool b) { return EBool(b); }
      
    public:
      static EBool Typed(GenericExpression^ value) 
      { 
        return EBool(gcnew TypedExpression<bool>(value));
      }

      static EBool Convert(GenericExpression^ value) 
      { 
        return EBool(gcnew ConvertExpression<bool>(value));
      }

    public:
      
      /// <summary>
      /// Returns negation of the logical value.
      /// </summary>
      static EBool operator!(EBool value)
      {
        return EBool(gcnew UnaryExpression<bool,bool>
          (value, System::Expressions::ExpressionType::Not));
      }

      /// <summary>
      /// Test values for equality.
      /// </summary>
      static EBool operator==(EBool left, EBool right)
      {
        return EBool(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Test values for inequality.
      /// </summary>
      static EBool operator!=(EBool left, EBool right)
      {
        return EBool(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::NE));
      }

      /// <summary>
      /// Performs logical 'and' operation.
      /// </summary>
      static EBool operator&&(EBool left, EBool right)
      {
        return EBool(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::And));
      }

      /// <summary>
      /// Performs logical 'or' operation.
      /// </summary>
      static EBool operator||(EBool left, EBool right)
      {
        return EBool(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::Or));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'unsigned char' expresion.
    /// </summary>
    public ref class EByte : ExpressionWrapper<unsigned char>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned char::typeid; } }
    
		public:
			EByte() { }
      EByte(unsigned char val) { _value = gcnew Literal<unsigned char>(val); }
      EByte(Expression<unsigned char>^ value) { _value = value; }
			EByte(EByte% b)	{ _value = b._value; }
			operator Expression<unsigned char>^() { return _value; }
			static operator EByte(Expression<unsigned char>^ value)  { return EByte(value); }
			static operator EByte(unsigned char b) { return EByte(b); }
      
    public:
      static EByte Typed(GenericExpression^ value) 
      { 
        return EByte(gcnew TypedExpression<unsigned char>(value));
      }

      static EByte Convert(GenericExpression^ value) 
      { 
        return EByte(gcnew ConvertExpression<unsigned char>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EByte types.
      /// </summary>
      static EByte operator+(EByte left, EByte right)
      {
        return EByte(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EByte types.
      /// </summary>
      static EByte operator*(EByte left, EByte right)
      {
        return EByte(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EByte types.
      /// </summary>
      static EByte operator/(EByte left, EByte right)
      {
        return EByte(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EByte types.
      /// </summary>
      static EByte operator-(EByte left, EByte right)
      {
        return EByte(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EByte types.
      /// </summary>
      static EBool operator==(EByte left, EByte right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EByte types.
      /// </summary>
      static EBool operator!=(EByte left, EByte right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EByte types.
      /// </summary>
      static EBool operator<(EByte left, EByte right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EByte types.
      /// </summary>
      static EBool operator>(EByte left, EByte right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EByte types.
      /// </summary>
      static EBool operator<=(EByte left, EByte right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EByte types.
      /// </summary>
      static EBool operator>=(EByte left, EByte right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'signed char' expresion.
    /// </summary>
    public ref class ESByte : ExpressionWrapper<signed char>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return signed char::typeid; } }
    
		public:
			ESByte() { }
      ESByte(signed char val) { _value = gcnew Literal<signed char>(val); }
      ESByte(Expression<signed char>^ value) { _value = value; }
			ESByte(ESByte% b)	{ _value = b._value; }
			operator Expression<signed char>^() { return _value; }
			static operator ESByte(Expression<signed char>^ value)  { return ESByte(value); }
			static operator ESByte(signed char b) { return ESByte(b); }
      
    public:
      static ESByte Typed(GenericExpression^ value) 
      { 
        return ESByte(gcnew TypedExpression<signed char>(value));
      }

      static ESByte Convert(GenericExpression^ value) 
      { 
        return ESByte(gcnew ConvertExpression<signed char>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of ESByte types.
      /// </summary>
      static ESByte operator+(ESByte left, ESByte right)
      {
        return ESByte(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of ESByte types.
      /// </summary>
      static ESByte operator*(ESByte left, ESByte right)
      {
        return ESByte(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of ESByte types.
      /// </summary>
      static ESByte operator/(ESByte left, ESByte right)
      {
        return ESByte(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of ESByte types.
      /// </summary>
      static ESByte operator-(ESByte left, ESByte right)
      {
        return ESByte(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of ESByte types.
      /// </summary>
      static EBool operator==(ESByte left, ESByte right)
      {
        return EBool(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of ESByte types.
      /// </summary>
      static EBool operator!=(ESByte left, ESByte right)
      {
        return EBool(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of ESByte types.
      /// </summary>
      static EBool operator<(ESByte left, ESByte right)
      {
        return EBool(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of ESByte types.
      /// </summary>
      static EBool operator>(ESByte left, ESByte right)
      {
        return EBool(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of ESByte types.
      /// </summary>
      static EBool operator<=(ESByte left, ESByte right)
      {
        return EBool(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of ESByte types.
      /// </summary>
      static EBool operator>=(ESByte left, ESByte right)
      {
        return EBool(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'float' expresion.
    /// </summary>
    public ref class EFloat : ExpressionWrapper<float>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return float::typeid; } }
    
		public:
			EFloat() { }
      EFloat(float val) { _value = gcnew Literal<float>(val); }
      EFloat(Expression<float>^ value) { _value = value; }
			EFloat(EFloat% b)	{ _value = b._value; }
			operator Expression<float>^() { return _value; }
			static operator EFloat(Expression<float>^ value)  { return EFloat(value); }
			static operator EFloat(float b) { return EFloat(b); }
      
    public:
      static EFloat Typed(GenericExpression^ value) 
      { 
        return EFloat(gcnew TypedExpression<float>(value));
      }

      static EFloat Convert(GenericExpression^ value) 
      { 
        return EFloat(gcnew ConvertExpression<float>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EFloat types.
      /// </summary>
      static EFloat operator+(EFloat left, EFloat right)
      {
        return EFloat(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EFloat types.
      /// </summary>
      static EFloat operator*(EFloat left, EFloat right)
      {
        return EFloat(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EFloat types.
      /// </summary>
      static EFloat operator/(EFloat left, EFloat right)
      {
        return EFloat(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EFloat types.
      /// </summary>
      static EFloat operator-(EFloat left, EFloat right)
      {
        return EFloat(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EFloat types.
      /// </summary>
      static EBool operator==(EFloat left, EFloat right)
      {
        return EBool(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EFloat types.
      /// </summary>
      static EBool operator!=(EFloat left, EFloat right)
      {
        return EBool(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EFloat types.
      /// </summary>
      static EBool operator<(EFloat left, EFloat right)
      {
        return EBool(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EFloat types.
      /// </summary>
      static EBool operator>(EFloat left, EFloat right)
      {
        return EBool(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EFloat types.
      /// </summary>
      static EBool operator<=(EFloat left, EFloat right)
      {
        return EBool(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EFloat types.
      /// </summary>
      static EBool operator>=(EFloat left, EFloat right)
      {
        return EBool(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'double' expresion.
    /// </summary>
    public ref class EDouble : ExpressionWrapper<double>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return double::typeid; } }
    
		public:
			EDouble() { }
      EDouble(double val) { _value = gcnew Literal<double>(val); }
      EDouble(Expression<double>^ value) { _value = value; }
			EDouble(EDouble% b)	{ _value = b._value; }
			operator Expression<double>^() { return _value; }
			static operator EDouble(Expression<double>^ value)  { return EDouble(value); }
			static operator EDouble(double b) { return EDouble(b); }
      
    public:
      static EDouble Typed(GenericExpression^ value) 
      { 
        return EDouble(gcnew TypedExpression<double>(value));
      }

      static EDouble Convert(GenericExpression^ value) 
      { 
        return EDouble(gcnew ConvertExpression<double>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EDouble types.
      /// </summary>
      static EDouble operator+(EDouble left, EDouble right)
      {
        return EDouble(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EDouble types.
      /// </summary>
      static EDouble operator*(EDouble left, EDouble right)
      {
        return EDouble(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EDouble types.
      /// </summary>
      static EDouble operator/(EDouble left, EDouble right)
      {
        return EDouble(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EDouble types.
      /// </summary>
      static EDouble operator-(EDouble left, EDouble right)
      {
        return EDouble(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EDouble types.
      /// </summary>
      static EBool operator==(EDouble left, EDouble right)
      {
        return EBool(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EDouble types.
      /// </summary>
      static EBool operator!=(EDouble left, EDouble right)
      {
        return EBool(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EDouble types.
      /// </summary>
      static EBool operator<(EDouble left, EDouble right)
      {
        return EBool(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EDouble types.
      /// </summary>
      static EBool operator>(EDouble left, EDouble right)
      {
        return EBool(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EDouble types.
      /// </summary>
      static EBool operator<=(EDouble left, EDouble right)
      {
        return EBool(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EDouble types.
      /// </summary>
      static EBool operator>=(EDouble left, EDouble right)
      {
        return EBool(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'System::Decimal' expresion.
    /// </summary>
    public ref class EDecimal : ExpressionWrapper<System::Decimal>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return System::Decimal::typeid; } }
    
		public:
			EDecimal() { }
      EDecimal(System::Decimal val) { _value = gcnew Literal<System::Decimal>(val); }
      EDecimal(Expression<System::Decimal>^ value) { _value = value; }
			EDecimal(EDecimal% b)	{ _value = b._value; }
			operator Expression<System::Decimal>^() { return _value; }
			static operator EDecimal(Expression<System::Decimal>^ value)  { return EDecimal(value); }
			static operator EDecimal(System::Decimal b) { return EDecimal(b); }
      
    public:
      static EDecimal Typed(GenericExpression^ value) 
      { 
        return EDecimal(gcnew TypedExpression<System::Decimal>(value));
      }

      static EDecimal Convert(GenericExpression^ value) 
      { 
        return EDecimal(gcnew ConvertExpression<System::Decimal>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EDecimal types.
      /// </summary>
      static EDecimal operator+(EDecimal left, EDecimal right)
      {
        return EDecimal(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EDecimal types.
      /// </summary>
      static EDecimal operator*(EDecimal left, EDecimal right)
      {
        return EDecimal(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EDecimal types.
      /// </summary>
      static EDecimal operator/(EDecimal left, EDecimal right)
      {
        return EDecimal(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EDecimal types.
      /// </summary>
      static EDecimal operator-(EDecimal left, EDecimal right)
      {
        return EDecimal(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EDecimal types.
      /// </summary>
      static EBool operator==(EDecimal left, EDecimal right)
      {
        return EBool(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EDecimal types.
      /// </summary>
      static EBool operator!=(EDecimal left, EDecimal right)
      {
        return EBool(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EDecimal types.
      /// </summary>
      static EBool operator<(EDecimal left, EDecimal right)
      {
        return EBool(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EDecimal types.
      /// </summary>
      static EBool operator>(EDecimal left, EDecimal right)
      {
        return EBool(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EDecimal types.
      /// </summary>
      static EBool operator<=(EDecimal left, EDecimal right)
      {
        return EBool(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EDecimal types.
      /// </summary>
      static EBool operator>=(EDecimal left, EDecimal right)
      {
        return EBool(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'short' expresion.
    /// </summary>
    public ref class EShort : ExpressionWrapper<short>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return short::typeid; } }
    
		public:
			EShort() { }
      EShort(short val) { _value = gcnew Literal<short>(val); }
      EShort(Expression<short>^ value) { _value = value; }
			EShort(EShort% b)	{ _value = b._value; }
			operator Expression<short>^() { return _value; }
			static operator EShort(Expression<short>^ value)  { return EShort(value); }
			static operator EShort(short b) { return EShort(b); }
      
    public:
      static EShort Typed(GenericExpression^ value) 
      { 
        return EShort(gcnew TypedExpression<short>(value));
      }

      static EShort Convert(GenericExpression^ value) 
      { 
        return EShort(gcnew ConvertExpression<short>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EShort types.
      /// </summary>
      static EShort operator+(EShort left, EShort right)
      {
        return EShort(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EShort types.
      /// </summary>
      static EShort operator*(EShort left, EShort right)
      {
        return EShort(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EShort types.
      /// </summary>
      static EShort operator/(EShort left, EShort right)
      {
        return EShort(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EShort types.
      /// </summary>
      static EShort operator-(EShort left, EShort right)
      {
        return EShort(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EShort types.
      /// </summary>
      static EBool operator==(EShort left, EShort right)
      {
        return EBool(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EShort types.
      /// </summary>
      static EBool operator!=(EShort left, EShort right)
      {
        return EBool(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EShort types.
      /// </summary>
      static EBool operator<(EShort left, EShort right)
      {
        return EBool(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EShort types.
      /// </summary>
      static EBool operator>(EShort left, EShort right)
      {
        return EBool(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EShort types.
      /// </summary>
      static EBool operator<=(EShort left, EShort right)
      {
        return EBool(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EShort types.
      /// </summary>
      static EBool operator>=(EShort left, EShort right)
      {
        return EBool(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'int' expresion. Implements standard math and comparsion operators.
    /// </summary>
    public ref class EInt : ExpressionWrapper<int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return int::typeid; } }
    
		public:
			EInt() { }
      EInt(int val) { _value = gcnew Literal<int>(val); }
      EInt(Expression<int>^ value) { _value = value; }
			EInt(EInt% b)	{ _value = b._value; }
			operator Expression<int>^() { return _value; }
			static operator EInt(Expression<int>^ value)  { return EInt(value); }
			static operator EInt(int b) { return EInt(b); }
      
    public:
      static EInt Typed(GenericExpression^ value) 
      { 
        return EInt(gcnew TypedExpression<int>(value));
      }

      static EInt Convert(GenericExpression^ value) 
      { 
        return EInt(gcnew ConvertExpression<int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EInt types.
      /// </summary>
      static EInt operator+(EInt left, EInt right)
      {
        return EInt(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EInt types.
      /// </summary>
      static EInt operator*(EInt left, EInt right)
      {
        return EInt(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EInt types.
      /// </summary>
      static EInt operator/(EInt left, EInt right)
      {
        return EInt(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EInt types.
      /// </summary>
      static EInt operator-(EInt left, EInt right)
      {
        return EInt(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EInt types.
      /// </summary>
      static EBool operator==(EInt left, EInt right)
      {
        return EBool(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EInt types.
      /// </summary>
      static EBool operator!=(EInt left, EInt right)
      {
        return EBool(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EInt types.
      /// </summary>
      static EBool operator<(EInt left, EInt right)
      {
        return EBool(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EInt types.
      /// </summary>
      static EBool operator>(EInt left, EInt right)
      {
        return EBool(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EInt types.
      /// </summary>
      static EBool operator<=(EInt left, EInt right)
      {
        return EBool(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EInt types.
      /// </summary>
      static EBool operator>=(EInt left, EInt right)
      {
        return EBool(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

      /// <summary>
      /// Shift left operator for tuple of EInt types.
      /// </summary>
      static EInt operator<<(EInt left, EInt right)
      {
        return EInt(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::LShift));
      }

      /// <summary>
      /// Shift right operator for tuple of EInt types.
      /// </summary>
      static EInt operator>>(EInt left, EInt right)
      {
        return EInt(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::RShift));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'long long int' expresion.
    /// </summary>
    public ref class ELong : ExpressionWrapper<long long int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return long long int::typeid; } }
    
		public:
			ELong() { }
      ELong(long long int val) { _value = gcnew Literal<long long int>(val); }
      ELong(Expression<long long int>^ value) { _value = value; }
			ELong(ELong% b)	{ _value = b._value; }
			operator Expression<long long int>^() { return _value; }
			static operator ELong(Expression<long long int>^ value)  { return ELong(value); }
			static operator ELong(long long int b) { return ELong(b); }
      
    public:
      static ELong Typed(GenericExpression^ value) 
      { 
        return ELong(gcnew TypedExpression<long long int>(value));
      }

      static ELong Convert(GenericExpression^ value) 
      { 
        return ELong(gcnew ConvertExpression<long long int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of ELong types.
      /// </summary>
      static ELong operator+(ELong left, ELong right)
      {
        return ELong(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of ELong types.
      /// </summary>
      static ELong operator*(ELong left, ELong right)
      {
        return ELong(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of ELong types.
      /// </summary>
      static ELong operator/(ELong left, ELong right)
      {
        return ELong(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of ELong types.
      /// </summary>
      static ELong operator-(ELong left, ELong right)
      {
        return ELong(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of ELong types.
      /// </summary>
      static EBool operator==(ELong left, ELong right)
      {
        return EBool(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of ELong types.
      /// </summary>
      static EBool operator!=(ELong left, ELong right)
      {
        return EBool(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of ELong types.
      /// </summary>
      static EBool operator<(ELong left, ELong right)
      {
        return EBool(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of ELong types.
      /// </summary>
      static EBool operator>(ELong left, ELong right)
      {
        return EBool(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of ELong types.
      /// </summary>
      static EBool operator<=(ELong left, ELong right)
      {
        return EBool(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of ELong types.
      /// </summary>
      static EBool operator>=(ELong left, ELong right)
      {
        return EBool(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'unsigned int' expresion.
    /// </summary>
    public ref class EUInt : ExpressionWrapper<unsigned int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned int::typeid; } }
    
		public:
			EUInt() { }
      EUInt(unsigned int val) { _value = gcnew Literal<unsigned int>(val); }
      EUInt(Expression<unsigned int>^ value) { _value = value; }
			EUInt(EUInt% b)	{ _value = b._value; }
			operator Expression<unsigned int>^() { return _value; }
			static operator EUInt(Expression<unsigned int>^ value)  { return EUInt(value); }
			static operator EUInt(unsigned int b) { return EUInt(b); }
      
    public:
      static EUInt Typed(GenericExpression^ value) 
      { 
        return EUInt(gcnew TypedExpression<unsigned int>(value));
      }

      static EUInt Convert(GenericExpression^ value) 
      { 
        return EUInt(gcnew ConvertExpression<unsigned int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EUInt types.
      /// </summary>
      static EUInt operator+(EUInt left, EUInt right)
      {
        return EUInt(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EUInt types.
      /// </summary>
      static EUInt operator*(EUInt left, EUInt right)
      {
        return EUInt(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EUInt types.
      /// </summary>
      static EUInt operator/(EUInt left, EUInt right)
      {
        return EUInt(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EUInt types.
      /// </summary>
      static EUInt operator-(EUInt left, EUInt right)
      {
        return EUInt(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EUInt types.
      /// </summary>
      static EBool operator==(EUInt left, EUInt right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EUInt types.
      /// </summary>
      static EBool operator!=(EUInt left, EUInt right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EUInt types.
      /// </summary>
      static EBool operator<(EUInt left, EUInt right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EUInt types.
      /// </summary>
      static EBool operator>(EUInt left, EUInt right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EUInt types.
      /// </summary>
      static EBool operator<=(EUInt left, EUInt right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EUInt types.
      /// </summary>
      static EBool operator>=(EUInt left, EUInt right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'unsigned short' expresion.
    /// </summary>
    public ref class EUShort : ExpressionWrapper<unsigned short>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned short::typeid; } }
    
		public:
			EUShort() { }
      EUShort(unsigned short val) { _value = gcnew Literal<unsigned short>(val); }
      EUShort(Expression<unsigned short>^ value) { _value = value; }
			EUShort(EUShort% b)	{ _value = b._value; }
			operator Expression<unsigned short>^() { return _value; }
			static operator EUShort(Expression<unsigned short>^ value)  { return EUShort(value); }
			static operator EUShort(unsigned short b) { return EUShort(b); }
      
    public:
      static EUShort Typed(GenericExpression^ value) 
      { 
        return EUShort(gcnew TypedExpression<unsigned short>(value));
      }

      static EUShort Convert(GenericExpression^ value) 
      { 
        return EUShort(gcnew ConvertExpression<unsigned short>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EUShort types.
      /// </summary>
      static EUShort operator+(EUShort left, EUShort right)
      {
        return EUShort(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EUShort types.
      /// </summary>
      static EUShort operator*(EUShort left, EUShort right)
      {
        return EUShort(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EUShort types.
      /// </summary>
      static EUShort operator/(EUShort left, EUShort right)
      {
        return EUShort(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EUShort types.
      /// </summary>
      static EUShort operator-(EUShort left, EUShort right)
      {
        return EUShort(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EUShort types.
      /// </summary>
      static EBool operator==(EUShort left, EUShort right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EUShort types.
      /// </summary>
      static EBool operator!=(EUShort left, EUShort right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EUShort types.
      /// </summary>
      static EBool operator<(EUShort left, EUShort right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EUShort types.
      /// </summary>
      static EBool operator>(EUShort left, EUShort right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EUShort types.
      /// </summary>
      static EBool operator<=(EUShort left, EUShort right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EUShort types.
      /// </summary>
      static EBool operator>=(EUShort left, EUShort right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'unsigned long long int' expresion.
    /// </summary>
    public ref class EULong : ExpressionWrapper<unsigned long long int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned long long int::typeid; } }
    
		public:
			EULong() { }
      EULong(unsigned long long int val) { _value = gcnew Literal<unsigned long long int>(val); }
      EULong(Expression<unsigned long long int>^ value) { _value = value; }
			EULong(EULong% b)	{ _value = b._value; }
			operator Expression<unsigned long long int>^() { return _value; }
			static operator EULong(Expression<unsigned long long int>^ value)  { return EULong(value); }
			static operator EULong(unsigned long long int b) { return EULong(b); }
      
    public:
      static EULong Typed(GenericExpression^ value) 
      { 
        return EULong(gcnew TypedExpression<unsigned long long int>(value));
      }

      static EULong Convert(GenericExpression^ value) 
      { 
        return EULong(gcnew ConvertExpression<unsigned long long int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of EULong types.
      /// </summary>
      static EULong operator+(EULong left, EULong right)
      {
        return EULong(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of EULong types.
      /// </summary>
      static EULong operator*(EULong left, EULong right)
      {
        return EULong(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of EULong types.
      /// </summary>
      static EULong operator/(EULong left, EULong right)
      {
        return EULong(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of EULong types.
      /// </summary>
      static EULong operator-(EULong left, EULong right)
      {
        return EULong(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// Comparsion operator for tuple of EULong types.
      /// </summary>
      static EBool operator==(EULong left, EULong right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EULong types.
      /// </summary>
      static EBool operator!=(EULong left, EULong right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of EULong types.
      /// </summary>
      static EBool operator<(EULong left, EULong right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of EULong types.
      /// </summary>
      static EBool operator>(EULong left, EULong right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of EULong types.
      /// </summary>
      static EBool operator<=(EULong left, EULong right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of EULong types.
      /// </summary>
      static EBool operator>=(EULong left, EULong right)
      {
        return EBool(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'wchar_t' expresion.
    /// </summary>
    public ref class EChar : ExpressionWrapper<wchar_t>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return wchar_t::typeid; } }
    
		public:
			EChar() { }
      EChar(wchar_t val) { _value = gcnew Literal<wchar_t>(val); }
      EChar(Expression<wchar_t>^ value) { _value = value; }
			EChar(EChar% b)	{ _value = b._value; }
			operator Expression<wchar_t>^() { return _value; }
			static operator EChar(Expression<wchar_t>^ value)  { return EChar(value); }
			static operator EChar(wchar_t b) { return EChar(b); }
      
    public:
      static EChar Typed(GenericExpression^ value) 
      { 
        return EChar(gcnew TypedExpression<wchar_t>(value));
      }

      static EChar Convert(GenericExpression^ value) 
      { 
        return EChar(gcnew ConvertExpression<wchar_t>(value));
      }

    public:
      
      /// <summary>
      /// Test values for equality.
      /// </summary>
      static EBool operator==(EChar left, EChar right)
      {
        return EBool(gcnew BinaryExpression<bool,wchar_t,wchar_t>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Test values for inequality.
      /// </summary>
      static EBool operator!=(EChar left, EChar right)
      {
        return EBool(gcnew BinaryExpression<bool,wchar_t,wchar_t>
          (left, right, System::Expressions::ExpressionType::NE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Type safe wrapper for the 'String^' expresion. Implements standard string operators and methods.
    /// </summary>
    public ref class EString : ExpressionWrapper<String^>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return String::typeid; } }
    
		public:
			EString() { }
      EString(String^ val) { _value = gcnew Literal<String^>(val); }
      EString(Expression<String^>^ value) { _value = value; }
			EString(EString% b)	{ _value = b._value; }
			operator Expression<String^>^() { return _value; }
			static operator EString(Expression<String^>^ value)  { return EString(value); }
			static operator EString(String^ b) { return EString(b); }
      
    public:
      static EString Typed(GenericExpression^ value) 
      { 
        return EString(gcnew TypedExpression<String^>(value));
      }

      static EString Convert(GenericExpression^ value) 
      { 
        return EString(gcnew ConvertExpression<String^>(value));
      }

    public:
      
      /// <summary>
      /// Operator for string concatenation.
      /// </summary>
      static EString operator+(EString left, EString right)
      {
        return EString(gcnew BinaryExpression<String^,String^,String^>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Comparsion operator for tuple of EString types.
      /// </summary>
      static EBool operator==(EString left, EString right)
      {
        return EBool(gcnew BinaryExpression<bool,String^,String^>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of EString types.
      /// </summary>
      static EBool operator!=(EString left, EString right)
      {
        return EBool(gcnew BinaryExpression<bool,String^,String^>
          (left, right, System::Expressions::ExpressionType::NE));
      }

  
    public:
      
    private:
    	static MethodInfo^ __Substring_EInt;
    	static property MethodInfo^ _Substring_EInt { 
        MethodInfo^ get() { if (__Substring_EInt == nullptr) 
          __Substring_EInt = (String::typeid)->GetMethod("Substring", gcnew array<Type^>{ EInt::WrappedType }); return __Substring_EInt; 
        } }
    public:
      /// <summary>
      /// Retrieves a substring from this instance.
      /// </summary>
      EString Substring(EInt startIndex)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Substring_EInt, this, gcnew array<GenericExpression^>{startIndex}));
      }

    private:
    	static MethodInfo^ __Substring_EInt_EInt;
    	static property MethodInfo^ _Substring_EInt_EInt { 
        MethodInfo^ get() { if (__Substring_EInt_EInt == nullptr) 
          __Substring_EInt_EInt = (String::typeid)->GetMethod("Substring", gcnew array<Type^>{ EInt::WrappedType, EInt::WrappedType }); return __Substring_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Retrieves a substring from this instance.
      /// </summary>
      EString Substring(EInt startIndex, EInt length)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Substring_EInt_EInt, this, gcnew array<GenericExpression^>{startIndex, length}));
      }

    private:
    	static MethodInfo^ __Contains_EString;
    	static property MethodInfo^ _Contains_EString { 
        MethodInfo^ get() { if (__Contains_EString == nullptr) 
          __Contains_EString = (String::typeid)->GetMethod("Contains", gcnew array<Type^>{ EString::WrappedType }); return __Contains_EString; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating whether the specified String object occurs within this string.
      /// </summary>
      EBool Contains(EString value)
  		{
	  		return EBool(gcnew MethodInvokeExpression<bool>
          (_Contains_EString, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __StartsWith_EString;
    	static property MethodInfo^ _StartsWith_EString { 
        MethodInfo^ get() { if (__StartsWith_EString == nullptr) 
          __StartsWith_EString = (String::typeid)->GetMethod("StartsWith", gcnew array<Type^>{ EString::WrappedType }); return __StartsWith_EString; 
        } }
    public:
      /// <summary>
      /// Determines whether the beginning of an instance of String matches a specified string.
      /// </summary>
      EBool StartsWith(EString value)
  		{
	  		return EBool(gcnew MethodInvokeExpression<bool>
          (_StartsWith_EString, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __EndsWith_EString;
    	static property MethodInfo^ _EndsWith_EString { 
        MethodInfo^ get() { if (__EndsWith_EString == nullptr) 
          __EndsWith_EString = (String::typeid)->GetMethod("EndsWith", gcnew array<Type^>{ EString::WrappedType }); return __EndsWith_EString; 
        } }
    public:
      /// <summary>
      /// Determines whether the end of an instance of String matches a specified string.
      /// </summary>
      EBool EndsWith(EString value)
  		{
	  		return EBool(gcnew MethodInvokeExpression<bool>
          (_EndsWith_EString, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __IndexOf_EChar;
    	static property MethodInfo^ _IndexOf_EChar { 
        MethodInfo^ get() { if (__IndexOf_EChar == nullptr) 
          __IndexOf_EChar = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ EChar::WrappedType }); return __IndexOf_EChar; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      EInt IndexOf(EChar value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_IndexOf_EChar, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __IndexOf_EString;
    	static property MethodInfo^ _IndexOf_EString { 
        MethodInfo^ get() { if (__IndexOf_EString == nullptr) 
          __IndexOf_EString = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ EString::WrappedType }); return __IndexOf_EString; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      EInt IndexOf(EString value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_IndexOf_EString, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __IndexOf_EChar_EInt;
    	static property MethodInfo^ _IndexOf_EChar_EInt { 
        MethodInfo^ get() { if (__IndexOf_EChar_EInt == nullptr) 
          __IndexOf_EChar_EInt = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ EChar::WrappedType, EInt::WrappedType }); return __IndexOf_EChar_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      EInt IndexOf(EChar value, EInt startIndex)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_IndexOf_EChar_EInt, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __IndexOf_EString_EInt;
    	static property MethodInfo^ _IndexOf_EString_EInt { 
        MethodInfo^ get() { if (__IndexOf_EString_EInt == nullptr) 
          __IndexOf_EString_EInt = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ EString::WrappedType, EInt::WrappedType }); return __IndexOf_EString_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      EInt IndexOf(EString value, EInt startIndex)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_IndexOf_EString_EInt, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __IndexOf_EChar_EInt_EInt;
    	static property MethodInfo^ _IndexOf_EChar_EInt_EInt { 
        MethodInfo^ get() { if (__IndexOf_EChar_EInt_EInt == nullptr) 
          __IndexOf_EChar_EInt_EInt = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ EChar::WrappedType, EInt::WrappedType, EInt::WrappedType }); return __IndexOf_EChar_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      EInt IndexOf(EChar value, EInt startIndex, EInt count)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_IndexOf_EChar_EInt_EInt, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __IndexOf_EString_EInt_EInt;
    	static property MethodInfo^ _IndexOf_EString_EInt_EInt { 
        MethodInfo^ get() { if (__IndexOf_EString_EInt_EInt == nullptr) 
          __IndexOf_EString_EInt_EInt = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ EString::WrappedType, EInt::WrappedType, EInt::WrappedType }); return __IndexOf_EString_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      EInt IndexOf(EString value, EInt startIndex, EInt count)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_IndexOf_EString_EInt_EInt, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_EChar;
    	static property MethodInfo^ _LastIndexOf_EChar { 
        MethodInfo^ get() { if (__LastIndexOf_EChar == nullptr) 
          __LastIndexOf_EChar = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ EChar::WrappedType }); return __LastIndexOf_EChar; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      EInt LastIndexOf(EChar value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_EChar, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_EString;
    	static property MethodInfo^ _LastIndexOf_EString { 
        MethodInfo^ get() { if (__LastIndexOf_EString == nullptr) 
          __LastIndexOf_EString = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ EString::WrappedType }); return __LastIndexOf_EString; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      EInt LastIndexOf(EString value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_EString, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_EChar_EInt;
    	static property MethodInfo^ _LastIndexOf_EChar_EInt { 
        MethodInfo^ get() { if (__LastIndexOf_EChar_EInt == nullptr) 
          __LastIndexOf_EChar_EInt = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ EChar::WrappedType, EInt::WrappedType }); return __LastIndexOf_EChar_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      EInt LastIndexOf(EChar value, EInt startIndex)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_EChar_EInt, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_EString_EInt;
    	static property MethodInfo^ _LastIndexOf_EString_EInt { 
        MethodInfo^ get() { if (__LastIndexOf_EString_EInt == nullptr) 
          __LastIndexOf_EString_EInt = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ EString::WrappedType, EInt::WrappedType }); return __LastIndexOf_EString_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      EInt LastIndexOf(EString value, EInt startIndex)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_EString_EInt, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_EChar_EInt_EInt;
    	static property MethodInfo^ _LastIndexOf_EChar_EInt_EInt { 
        MethodInfo^ get() { if (__LastIndexOf_EChar_EInt_EInt == nullptr) 
          __LastIndexOf_EChar_EInt_EInt = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ EChar::WrappedType, EInt::WrappedType, EInt::WrappedType }); return __LastIndexOf_EChar_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      EInt LastIndexOf(EChar value, EInt startIndex, EInt count)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_EChar_EInt_EInt, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_EString_EInt_EInt;
    	static property MethodInfo^ _LastIndexOf_EString_EInt_EInt { 
        MethodInfo^ get() { if (__LastIndexOf_EString_EInt_EInt == nullptr) 
          __LastIndexOf_EString_EInt_EInt = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ EString::WrappedType, EInt::WrappedType, EInt::WrappedType }); return __LastIndexOf_EString_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      EInt LastIndexOf(EString value, EInt startIndex, EInt count)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_EString_EInt_EInt, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __Insert_EInt_EString;
    	static property MethodInfo^ _Insert_EInt_EString { 
        MethodInfo^ get() { if (__Insert_EInt_EString == nullptr) 
          __Insert_EInt_EString = (String::typeid)->GetMethod("Insert", gcnew array<Type^>{ EInt::WrappedType, EString::WrappedType }); return __Insert_EInt_EString; 
        } }
    public:
      /// <summary>
      /// Inserts a specified instance of String at a specified index position in this instance.
      /// </summary>
      EString Insert(EInt startIndex, EString value)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Insert_EInt_EString, this, gcnew array<GenericExpression^>{startIndex, value}));
      }

    private:
    	static MethodInfo^ __Remove_EInt;
    	static property MethodInfo^ _Remove_EInt { 
        MethodInfo^ get() { if (__Remove_EInt == nullptr) 
          __Remove_EInt = (String::typeid)->GetMethod("Remove", gcnew array<Type^>{ EInt::WrappedType }); return __Remove_EInt; 
        } }
    public:
      /// <summary>
      /// Deletes a specified number of characters from this instance.
      /// </summary>
      EString Remove(EInt startIndex)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Remove_EInt, this, gcnew array<GenericExpression^>{startIndex}));
      }

    private:
    	static MethodInfo^ __Remove_EInt_EInt;
    	static property MethodInfo^ _Remove_EInt_EInt { 
        MethodInfo^ get() { if (__Remove_EInt_EInt == nullptr) 
          __Remove_EInt_EInt = (String::typeid)->GetMethod("Remove", gcnew array<Type^>{ EInt::WrappedType, EInt::WrappedType }); return __Remove_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Deletes a specified number of characters from this instance.
      /// </summary>
      EString Remove(EInt startIndex, EInt count)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Remove_EInt_EInt, this, gcnew array<GenericExpression^>{startIndex, count}));
      }

    private:
    	static MethodInfo^ __Replace_EChar_EChar;
    	static property MethodInfo^ _Replace_EChar_EChar { 
        MethodInfo^ get() { if (__Replace_EChar_EChar == nullptr) 
          __Replace_EChar_EChar = (String::typeid)->GetMethod("Replace", gcnew array<Type^>{ EChar::WrappedType, EChar::WrappedType }); return __Replace_EChar_EChar; 
        } }
    public:
      /// <summary>
      /// Replaces all occurrences of a specified Unicode character or String in this instance, with another specified Unicode character or String.
      /// </summary>
      EString Replace(EChar oldChar, EChar newChar)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Replace_EChar_EChar, this, gcnew array<GenericExpression^>{oldChar, newChar}));
      }

    private:
    	static MethodInfo^ __Replace_EString_EString;
    	static property MethodInfo^ _Replace_EString_EString { 
        MethodInfo^ get() { if (__Replace_EString_EString == nullptr) 
          __Replace_EString_EString = (String::typeid)->GetMethod("Replace", gcnew array<Type^>{ EString::WrappedType, EString::WrappedType }); return __Replace_EString_EString; 
        } }
    public:
      /// <summary>
      /// Replaces all occurrences of a specified Unicode character or String in this instance, with another specified Unicode character or String.
      /// </summary>
      EString Replace(EString oldValue, EString newValue)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Replace_EString_EString, this, gcnew array<GenericExpression^>{oldValue, newValue}));
      }

    private:
    	static MethodInfo^ __Trim;
    	static property MethodInfo^ _Trim { 
        MethodInfo^ get() { if (__Trim == nullptr) 
          __Trim = (String::typeid)->GetMethod("Trim", gcnew array<Type^>{  }); return __Trim; 
        } }
    public:
      /// <summary>
      /// Removes all leading and trailing occurrences of a set of specified characters from the current String object.
      /// </summary>
      EString Trim()
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Trim, this, gcnew array<GenericExpression^>{}));
      }

    private:
    	static MethodInfo^ __ToLower;
    	static property MethodInfo^ _ToLower { 
        MethodInfo^ get() { if (__ToLower == nullptr) 
          __ToLower = (String::typeid)->GetMethod("ToLower", gcnew array<Type^>{  }); return __ToLower; 
        } }
    public:
      /// <summary>
      /// Returns a copy of this String converted to lowercase.
      /// </summary>
      EString ToLower()
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_ToLower, this, gcnew array<GenericExpression^>{}));
      }

    private:
    	static MethodInfo^ __ToUpper;
    	static property MethodInfo^ _ToUpper { 
        MethodInfo^ get() { if (__ToUpper == nullptr) 
          __ToUpper = (String::typeid)->GetMethod("ToUpper", gcnew array<Type^>{  }); return __ToUpper; 
        } }
    public:
      /// <summary>
      /// Returns a copy of this String converted to uppercase.
      /// </summary>
      EString ToUpper()
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_ToUpper, this, gcnew array<GenericExpression^>{}));
      }

    private:
    	static MethodInfo^ __PadRight_EInt;
    	static property MethodInfo^ _PadRight_EInt { 
        MethodInfo^ get() { if (__PadRight_EInt == nullptr) 
          __PadRight_EInt = (String::typeid)->GetMethod("PadRight", gcnew array<Type^>{ EInt::WrappedType }); return __PadRight_EInt; 
        } }
    public:
      /// <summary>
      /// Left-aligns the characters in this string, padding on the right with spaces or a specified Unicode character, for a specified total length.
      /// </summary>
      EString PadRight(EInt totalWidth)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_PadRight_EInt, this, gcnew array<GenericExpression^>{totalWidth}));
      }

    private:
    	static MethodInfo^ __PadRight_EInt_EChar;
    	static property MethodInfo^ _PadRight_EInt_EChar { 
        MethodInfo^ get() { if (__PadRight_EInt_EChar == nullptr) 
          __PadRight_EInt_EChar = (String::typeid)->GetMethod("PadRight", gcnew array<Type^>{ EInt::WrappedType, EChar::WrappedType }); return __PadRight_EInt_EChar; 
        } }
    public:
      /// <summary>
      /// Left-aligns the characters in this string, padding on the right with spaces or a specified Unicode character, for a specified total length.
      /// </summary>
      EString PadRight(EInt totalWidth, EChar paddingChar)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_PadRight_EInt_EChar, this, gcnew array<GenericExpression^>{totalWidth, paddingChar}));
      }

    private:
    	static MethodInfo^ __PadLeft_EInt;
    	static property MethodInfo^ _PadLeft_EInt { 
        MethodInfo^ get() { if (__PadLeft_EInt == nullptr) 
          __PadLeft_EInt = (String::typeid)->GetMethod("PadLeft", gcnew array<Type^>{ EInt::WrappedType }); return __PadLeft_EInt; 
        } }
    public:
      /// <summary>
      /// Right-aligns the characters in this instance, padding on the left with spaces or a specified Unicode character for a specified total length.
      /// </summary>
      EString PadLeft(EInt totalWidth)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_PadLeft_EInt, this, gcnew array<GenericExpression^>{totalWidth}));
      }

    private:
    	static MethodInfo^ __PadLeft_EInt_EChar;
    	static property MethodInfo^ _PadLeft_EInt_EChar { 
        MethodInfo^ get() { if (__PadLeft_EInt_EChar == nullptr) 
          __PadLeft_EInt_EChar = (String::typeid)->GetMethod("PadLeft", gcnew array<Type^>{ EInt::WrappedType, EChar::WrappedType }); return __PadLeft_EInt_EChar; 
        } }
    public:
      /// <summary>
      /// Right-aligns the characters in this instance, padding on the left with spaces or a specified Unicode character for a specified total length.
      /// </summary>
      EString PadLeft(EInt totalWidth, EChar paddingChar)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_PadLeft_EInt_EChar, this, gcnew array<GenericExpression^>{totalWidth, paddingChar}));
      }

    private:
    	static MethodInfo^ __Equals_EString;
    	static property MethodInfo^ _Equals_EString { 
        MethodInfo^ get() { if (__Equals_EString == nullptr) 
          __Equals_EString = (String::typeid)->GetMethod("Equals", gcnew array<Type^>{ EString::WrappedType }); return __Equals_EString; 
        } }
    public:
      /// <summary>
      /// Determines whether two String objects have the same value.
      /// </summary>
      EBool Equals(EString str)
  		{
	  		return EBool(gcnew MethodInvokeExpression<bool>
          (_Equals_EString, this, gcnew array<GenericExpression^>{str}));
      }

    private:
    	static MethodInfo^ __CompareTo_EString;
    	static property MethodInfo^ _CompareTo_EString { 
        MethodInfo^ get() { if (__CompareTo_EString == nullptr) 
          __CompareTo_EString = (String::typeid)->GetMethod("CompareTo", gcnew array<Type^>{ EString::WrappedType }); return __CompareTo_EString; 
        } }
    public:
      /// <summary>
      /// Compares this instance with a specified object or String and returns an indication of their relative values.
      /// </summary>
      EInt CompareTo(EString str)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_CompareTo_EString, this, gcnew array<GenericExpression^>{str}));
      }

    private:
    	static MethodInfo^ __Compare_EString_EString;
    	static property MethodInfo^ _Compare_EString_EString { 
        MethodInfo^ get() { if (__Compare_EString_EString == nullptr) 
          __Compare_EString_EString = (String::typeid)->GetMethod("Compare", gcnew array<Type^>{ EString::WrappedType, EString::WrappedType }); return __Compare_EString_EString; 
        } }
    public:
      /// <summary>
      /// Compares two specified String objects.
      /// </summary>
      static EInt Compare(EString strA, EString strB)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Compare_EString_EString, nullptr, gcnew array<GenericExpression^>{strA, strB}));
      }

    private:
    	static MethodInfo^ __Concat_cli__array_Expression_String_____;
    	static property MethodInfo^ _Concat_cli__array_Expression_String_____ { 
        MethodInfo^ get() { if (__Concat_cli__array_Expression_String_____ == nullptr) 
          __Concat_cli__array_Expression_String_____ = (String::typeid)->GetMethod("Concat", gcnew array<Type^>{ cli::array<String^>::typeid }); return __Concat_cli__array_Expression_String_____; 
        } }
    public:
      /// <summary>
      /// Concatenates one or more instances of String.
      /// </summary>
      static EString Concat(... cli::array<Expression<String^>^>^ strs)
  		{
	  		return EString(gcnew MethodInvokeExpression<String^>
          (_Concat_cli__array_Expression_String_____, nullptr, gcnew array<GenericExpression^>{ gcnew ParamsExpression<String^>(strs) }));
      }

    };
    

    /// <summary>
    /// Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
    /// </summary>
    public ref class EMath 
    {
    private:
      EMath() { }
      
    public:
      
  
    public:
      
    private:
    	static MethodInfo^ __Abs_EDecimal;
    	static property MethodInfo^ _Abs_EDecimal { 
        MethodInfo^ get() { if (__Abs_EDecimal == nullptr) 
          __Abs_EDecimal = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ EDecimal::WrappedType }); return __Abs_EDecimal; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static EDecimal Abs(EDecimal value)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Abs_EDecimal, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_EDouble;
    	static property MethodInfo^ _Abs_EDouble { 
        MethodInfo^ get() { if (__Abs_EDouble == nullptr) 
          __Abs_EDouble = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ EDouble::WrappedType }); return __Abs_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static EDouble Abs(EDouble value)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Abs_EDouble, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_EFloat;
    	static property MethodInfo^ _Abs_EFloat { 
        MethodInfo^ get() { if (__Abs_EFloat == nullptr) 
          __Abs_EFloat = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ EFloat::WrappedType }); return __Abs_EFloat; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static EFloat Abs(EFloat value)
  		{
	  		return EFloat(gcnew MethodInvokeExpression<float>
          (_Abs_EFloat, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_EInt;
    	static property MethodInfo^ _Abs_EInt { 
        MethodInfo^ get() { if (__Abs_EInt == nullptr) 
          __Abs_EInt = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ EInt::WrappedType }); return __Abs_EInt; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static EInt Abs(EInt value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Abs_EInt, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_ELong;
    	static property MethodInfo^ _Abs_ELong { 
        MethodInfo^ get() { if (__Abs_ELong == nullptr) 
          __Abs_ELong = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ ELong::WrappedType }); return __Abs_ELong; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static ELong Abs(ELong value)
  		{
	  		return ELong(gcnew MethodInvokeExpression<long long int>
          (_Abs_ELong, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_ESByte;
    	static property MethodInfo^ _Abs_ESByte { 
        MethodInfo^ get() { if (__Abs_ESByte == nullptr) 
          __Abs_ESByte = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ ESByte::WrappedType }); return __Abs_ESByte; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static ESByte Abs(ESByte value)
  		{
	  		return ESByte(gcnew MethodInvokeExpression<signed char>
          (_Abs_ESByte, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_EShort;
    	static property MethodInfo^ _Abs_EShort { 
        MethodInfo^ get() { if (__Abs_EShort == nullptr) 
          __Abs_EShort = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ EShort::WrappedType }); return __Abs_EShort; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static EShort Abs(EShort value)
  		{
	  		return EShort(gcnew MethodInvokeExpression<short>
          (_Abs_EShort, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Acos_EDouble;
    	static property MethodInfo^ _Acos_EDouble { 
        MethodInfo^ get() { if (__Acos_EDouble == nullptr) 
          __Acos_EDouble = (System::Math::typeid)->GetMethod("Acos", gcnew array<Type^>{ EDouble::WrappedType }); return __Acos_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose cosine is the specified number.
      /// </summary>
      static EDouble Acos(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Acos_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Asin_EDouble;
    	static property MethodInfo^ _Asin_EDouble { 
        MethodInfo^ get() { if (__Asin_EDouble == nullptr) 
          __Asin_EDouble = (System::Math::typeid)->GetMethod("Asin", gcnew array<Type^>{ EDouble::WrappedType }); return __Asin_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose sine is the specified number.
      /// </summary>
      static EDouble Asin(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Asin_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Atan_EDouble;
    	static property MethodInfo^ _Atan_EDouble { 
        MethodInfo^ get() { if (__Atan_EDouble == nullptr) 
          __Atan_EDouble = (System::Math::typeid)->GetMethod("Atan", gcnew array<Type^>{ EDouble::WrappedType }); return __Atan_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose tangent is the specified number.
      /// </summary>
      static EDouble Atan(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Atan_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Atan2_EDouble_EDouble;
    	static property MethodInfo^ _Atan2_EDouble_EDouble { 
        MethodInfo^ get() { if (__Atan2_EDouble_EDouble == nullptr) 
          __Atan2_EDouble_EDouble = (System::Math::typeid)->GetMethod("Atan2", gcnew array<Type^>{ EDouble::WrappedType, EDouble::WrappedType }); return __Atan2_EDouble_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose tangent is the quotient of two specified numbers.
      /// </summary>
      static EDouble Atan2(EDouble y, EDouble x)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Atan2_EDouble_EDouble, nullptr, gcnew array<GenericExpression^>{y, x}));
      }

    private:
    	static MethodInfo^ __BigMul_EInt_EInt;
    	static property MethodInfo^ _BigMul_EInt_EInt { 
        MethodInfo^ get() { if (__BigMul_EInt_EInt == nullptr) 
          __BigMul_EInt_EInt = (System::Math::typeid)->GetMethod("BigMul", gcnew array<Type^>{ EInt::WrappedType, EInt::WrappedType }); return __BigMul_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Produces the full product of two 32-bit numbers.
      /// </summary>
      static ELong BigMul(EInt a, EInt b)
  		{
	  		return ELong(gcnew MethodInvokeExpression<long long int>
          (_BigMul_EInt_EInt, nullptr, gcnew array<GenericExpression^>{a, b}));
      }

    private:
    	static MethodInfo^ __Ceiling_EDecimal;
    	static property MethodInfo^ _Ceiling_EDecimal { 
        MethodInfo^ get() { if (__Ceiling_EDecimal == nullptr) 
          __Ceiling_EDecimal = (System::Math::typeid)->GetMethod("Ceiling", gcnew array<Type^>{ EDecimal::WrappedType }); return __Ceiling_EDecimal; 
        } }
    public:
      /// <summary>
      /// Returns the smallest number greater than or equal to the specified number.
      /// </summary>
      static EDecimal Ceiling(EDecimal d)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Ceiling_EDecimal, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Ceiling_EDouble;
    	static property MethodInfo^ _Ceiling_EDouble { 
        MethodInfo^ get() { if (__Ceiling_EDouble == nullptr) 
          __Ceiling_EDouble = (System::Math::typeid)->GetMethod("Ceiling", gcnew array<Type^>{ EDouble::WrappedType }); return __Ceiling_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the smallest number greater than or equal to the specified number.
      /// </summary>
      static EDouble Ceiling(EDouble a)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Ceiling_EDouble, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Cos_EDouble;
    	static property MethodInfo^ _Cos_EDouble { 
        MethodInfo^ get() { if (__Cos_EDouble == nullptr) 
          __Cos_EDouble = (System::Math::typeid)->GetMethod("Cos", gcnew array<Type^>{ EDouble::WrappedType }); return __Cos_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the cosine of the specified angle.
      /// </summary>
      static EDouble Cos(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Cos_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Cosh_EDouble;
    	static property MethodInfo^ _Cosh_EDouble { 
        MethodInfo^ get() { if (__Cosh_EDouble == nullptr) 
          __Cosh_EDouble = (System::Math::typeid)->GetMethod("Cosh", gcnew array<Type^>{ EDouble::WrappedType }); return __Cosh_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the hyperbolic cosine of the specified angle.
      /// </summary>
      static EDouble Cosh(EDouble value)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Cosh_EDouble, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Exp_EDouble;
    	static property MethodInfo^ _Exp_EDouble { 
        MethodInfo^ get() { if (__Exp_EDouble == nullptr) 
          __Exp_EDouble = (System::Math::typeid)->GetMethod("Exp", gcnew array<Type^>{ EDouble::WrappedType }); return __Exp_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns e raised to the specified power.
      /// </summary>
      static EDouble Exp(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Exp_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Floor_EDecimal;
    	static property MethodInfo^ _Floor_EDecimal { 
        MethodInfo^ get() { if (__Floor_EDecimal == nullptr) 
          __Floor_EDecimal = (System::Math::typeid)->GetMethod("Floor", gcnew array<Type^>{ EDecimal::WrappedType }); return __Floor_EDecimal; 
        } }
    public:
      /// <summary>
      /// Returns the largest number less than or equal to the specified number.
      /// </summary>
      static EDecimal Floor(EDecimal d)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Floor_EDecimal, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Floor_EDouble;
    	static property MethodInfo^ _Floor_EDouble { 
        MethodInfo^ get() { if (__Floor_EDouble == nullptr) 
          __Floor_EDouble = (System::Math::typeid)->GetMethod("Floor", gcnew array<Type^>{ EDouble::WrappedType }); return __Floor_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the largest number less than or equal to the specified number.
      /// </summary>
      static EDouble Floor(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Floor_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Log_EDouble;
    	static property MethodInfo^ _Log_EDouble { 
        MethodInfo^ get() { if (__Log_EDouble == nullptr) 
          __Log_EDouble = (System::Math::typeid)->GetMethod("Log", gcnew array<Type^>{ EDouble::WrappedType }); return __Log_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the logarithm of a specified number.
      /// </summary>
      static EDouble Log(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Log_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Log_EDouble_EDouble;
    	static property MethodInfo^ _Log_EDouble_EDouble { 
        MethodInfo^ get() { if (__Log_EDouble_EDouble == nullptr) 
          __Log_EDouble_EDouble = (System::Math::typeid)->GetMethod("Log", gcnew array<Type^>{ EDouble::WrappedType, EDouble::WrappedType }); return __Log_EDouble_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the logarithm of a specified number.
      /// </summary>
      static EDouble Log(EDouble a, EDouble newBase)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Log_EDouble_EDouble, nullptr, gcnew array<GenericExpression^>{a, newBase}));
      }

    private:
    	static MethodInfo^ __Log10_EDouble;
    	static property MethodInfo^ _Log10_EDouble { 
        MethodInfo^ get() { if (__Log10_EDouble == nullptr) 
          __Log10_EDouble = (System::Math::typeid)->GetMethod("Log10", gcnew array<Type^>{ EDouble::WrappedType }); return __Log10_EDouble; 
        } }
    public:
      /// <summary>
      /// Log10  Returns the base 10 logarithm of a specified number.
      /// </summary>
      static EDouble Log10(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Log10_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Max_EByte_EByte;
    	static property MethodInfo^ _Max_EByte_EByte { 
        MethodInfo^ get() { if (__Max_EByte_EByte == nullptr) 
          __Max_EByte_EByte = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EByte::WrappedType, EByte::WrappedType }); return __Max_EByte_EByte; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EByte Max(EByte val1, EByte val2)
  		{
	  		return EByte(gcnew MethodInvokeExpression<unsigned char>
          (_Max_EByte_EByte, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EDecimal_EDecimal;
    	static property MethodInfo^ _Max_EDecimal_EDecimal { 
        MethodInfo^ get() { if (__Max_EDecimal_EDecimal == nullptr) 
          __Max_EDecimal_EDecimal = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EDecimal::WrappedType, EDecimal::WrappedType }); return __Max_EDecimal_EDecimal; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EDecimal Max(EDecimal val1, EDecimal val2)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Max_EDecimal_EDecimal, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EDouble_EDouble;
    	static property MethodInfo^ _Max_EDouble_EDouble { 
        MethodInfo^ get() { if (__Max_EDouble_EDouble == nullptr) 
          __Max_EDouble_EDouble = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EDouble::WrappedType, EDouble::WrappedType }); return __Max_EDouble_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EDouble Max(EDouble val1, EDouble val2)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Max_EDouble_EDouble, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EFloat_EFloat;
    	static property MethodInfo^ _Max_EFloat_EFloat { 
        MethodInfo^ get() { if (__Max_EFloat_EFloat == nullptr) 
          __Max_EFloat_EFloat = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EFloat::WrappedType, EFloat::WrappedType }); return __Max_EFloat_EFloat; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EFloat Max(EFloat val1, EFloat val2)
  		{
	  		return EFloat(gcnew MethodInvokeExpression<float>
          (_Max_EFloat_EFloat, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EInt_EInt;
    	static property MethodInfo^ _Max_EInt_EInt { 
        MethodInfo^ get() { if (__Max_EInt_EInt == nullptr) 
          __Max_EInt_EInt = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EInt::WrappedType, EInt::WrappedType }); return __Max_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EInt Max(EInt val1, EInt val2)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Max_EInt_EInt, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_ELong_ELong;
    	static property MethodInfo^ _Max_ELong_ELong { 
        MethodInfo^ get() { if (__Max_ELong_ELong == nullptr) 
          __Max_ELong_ELong = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ ELong::WrappedType, ELong::WrappedType }); return __Max_ELong_ELong; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static ELong Max(ELong val1, ELong val2)
  		{
	  		return ELong(gcnew MethodInvokeExpression<long long int>
          (_Max_ELong_ELong, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_ESByte_ESByte;
    	static property MethodInfo^ _Max_ESByte_ESByte { 
        MethodInfo^ get() { if (__Max_ESByte_ESByte == nullptr) 
          __Max_ESByte_ESByte = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ ESByte::WrappedType, ESByte::WrappedType }); return __Max_ESByte_ESByte; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static ESByte Max(ESByte val1, ESByte val2)
  		{
	  		return ESByte(gcnew MethodInvokeExpression<signed char>
          (_Max_ESByte_ESByte, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EShort_EShort;
    	static property MethodInfo^ _Max_EShort_EShort { 
        MethodInfo^ get() { if (__Max_EShort_EShort == nullptr) 
          __Max_EShort_EShort = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EShort::WrappedType, EShort::WrappedType }); return __Max_EShort_EShort; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EShort Max(EShort val1, EShort val2)
  		{
	  		return EShort(gcnew MethodInvokeExpression<short>
          (_Max_EShort_EShort, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EUInt_EUInt;
    	static property MethodInfo^ _Max_EUInt_EUInt { 
        MethodInfo^ get() { if (__Max_EUInt_EUInt == nullptr) 
          __Max_EUInt_EUInt = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EUInt::WrappedType, EUInt::WrappedType }); return __Max_EUInt_EUInt; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EUInt Max(EUInt val1, EUInt val2)
  		{
	  		return EUInt(gcnew MethodInvokeExpression<unsigned int>
          (_Max_EUInt_EUInt, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EULong_EULong;
    	static property MethodInfo^ _Max_EULong_EULong { 
        MethodInfo^ get() { if (__Max_EULong_EULong == nullptr) 
          __Max_EULong_EULong = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EULong::WrappedType, EULong::WrappedType }); return __Max_EULong_EULong; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EULong Max(EULong val1, EULong val2)
  		{
	  		return EULong(gcnew MethodInvokeExpression<unsigned long long int>
          (_Max_EULong_EULong, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_EUShort_EUShort;
    	static property MethodInfo^ _Max_EUShort_EUShort { 
        MethodInfo^ get() { if (__Max_EUShort_EUShort == nullptr) 
          __Max_EUShort_EUShort = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ EUShort::WrappedType, EUShort::WrappedType }); return __Max_EUShort_EUShort; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static EUShort Max(EUShort val1, EUShort val2)
  		{
	  		return EUShort(gcnew MethodInvokeExpression<unsigned short>
          (_Max_EUShort_EUShort, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EByte_EByte;
    	static property MethodInfo^ _Min_EByte_EByte { 
        MethodInfo^ get() { if (__Min_EByte_EByte == nullptr) 
          __Min_EByte_EByte = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EByte::WrappedType, EByte::WrappedType }); return __Min_EByte_EByte; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EByte Min(EByte val1, EByte val2)
  		{
	  		return EByte(gcnew MethodInvokeExpression<unsigned char>
          (_Min_EByte_EByte, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EDecimal_EDecimal;
    	static property MethodInfo^ _Min_EDecimal_EDecimal { 
        MethodInfo^ get() { if (__Min_EDecimal_EDecimal == nullptr) 
          __Min_EDecimal_EDecimal = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EDecimal::WrappedType, EDecimal::WrappedType }); return __Min_EDecimal_EDecimal; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EDecimal Min(EDecimal val1, EDecimal val2)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Min_EDecimal_EDecimal, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EDouble_EDouble;
    	static property MethodInfo^ _Min_EDouble_EDouble { 
        MethodInfo^ get() { if (__Min_EDouble_EDouble == nullptr) 
          __Min_EDouble_EDouble = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EDouble::WrappedType, EDouble::WrappedType }); return __Min_EDouble_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EDouble Min(EDouble val1, EDouble val2)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Min_EDouble_EDouble, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EFloat_EFloat;
    	static property MethodInfo^ _Min_EFloat_EFloat { 
        MethodInfo^ get() { if (__Min_EFloat_EFloat == nullptr) 
          __Min_EFloat_EFloat = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EFloat::WrappedType, EFloat::WrappedType }); return __Min_EFloat_EFloat; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EFloat Min(EFloat val1, EFloat val2)
  		{
	  		return EFloat(gcnew MethodInvokeExpression<float>
          (_Min_EFloat_EFloat, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EInt_EInt;
    	static property MethodInfo^ _Min_EInt_EInt { 
        MethodInfo^ get() { if (__Min_EInt_EInt == nullptr) 
          __Min_EInt_EInt = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EInt::WrappedType, EInt::WrappedType }); return __Min_EInt_EInt; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EInt Min(EInt val1, EInt val2)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Min_EInt_EInt, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_ELong_ELong;
    	static property MethodInfo^ _Min_ELong_ELong { 
        MethodInfo^ get() { if (__Min_ELong_ELong == nullptr) 
          __Min_ELong_ELong = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ ELong::WrappedType, ELong::WrappedType }); return __Min_ELong_ELong; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static ELong Min(ELong val1, ELong val2)
  		{
	  		return ELong(gcnew MethodInvokeExpression<long long int>
          (_Min_ELong_ELong, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_ESByte_ESByte;
    	static property MethodInfo^ _Min_ESByte_ESByte { 
        MethodInfo^ get() { if (__Min_ESByte_ESByte == nullptr) 
          __Min_ESByte_ESByte = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ ESByte::WrappedType, ESByte::WrappedType }); return __Min_ESByte_ESByte; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static ESByte Min(ESByte val1, ESByte val2)
  		{
	  		return ESByte(gcnew MethodInvokeExpression<signed char>
          (_Min_ESByte_ESByte, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EShort_EShort;
    	static property MethodInfo^ _Min_EShort_EShort { 
        MethodInfo^ get() { if (__Min_EShort_EShort == nullptr) 
          __Min_EShort_EShort = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EShort::WrappedType, EShort::WrappedType }); return __Min_EShort_EShort; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EShort Min(EShort val1, EShort val2)
  		{
	  		return EShort(gcnew MethodInvokeExpression<short>
          (_Min_EShort_EShort, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EUInt_EUInt;
    	static property MethodInfo^ _Min_EUInt_EUInt { 
        MethodInfo^ get() { if (__Min_EUInt_EUInt == nullptr) 
          __Min_EUInt_EUInt = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EUInt::WrappedType, EUInt::WrappedType }); return __Min_EUInt_EUInt; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EUInt Min(EUInt val1, EUInt val2)
  		{
	  		return EUInt(gcnew MethodInvokeExpression<unsigned int>
          (_Min_EUInt_EUInt, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EULong_EULong;
    	static property MethodInfo^ _Min_EULong_EULong { 
        MethodInfo^ get() { if (__Min_EULong_EULong == nullptr) 
          __Min_EULong_EULong = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EULong::WrappedType, EULong::WrappedType }); return __Min_EULong_EULong; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EULong Min(EULong val1, EULong val2)
  		{
	  		return EULong(gcnew MethodInvokeExpression<unsigned long long int>
          (_Min_EULong_EULong, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_EUShort_EUShort;
    	static property MethodInfo^ _Min_EUShort_EUShort { 
        MethodInfo^ get() { if (__Min_EUShort_EUShort == nullptr) 
          __Min_EUShort_EUShort = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ EUShort::WrappedType, EUShort::WrappedType }); return __Min_EUShort_EUShort; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static EUShort Min(EUShort val1, EUShort val2)
  		{
	  		return EUShort(gcnew MethodInvokeExpression<unsigned short>
          (_Min_EUShort_EUShort, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Pow_EDouble_EDouble;
    	static property MethodInfo^ _Pow_EDouble_EDouble { 
        MethodInfo^ get() { if (__Pow_EDouble_EDouble == nullptr) 
          __Pow_EDouble_EDouble = (System::Math::typeid)->GetMethod("Pow", gcnew array<Type^>{ EDouble::WrappedType, EDouble::WrappedType }); return __Pow_EDouble_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns a specified number raised to the specified power.
      /// </summary>
      static EDouble Pow(EDouble x, EDouble y)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Pow_EDouble_EDouble, nullptr, gcnew array<GenericExpression^>{x, y}));
      }

    private:
    	static MethodInfo^ __Round_EDecimal;
    	static property MethodInfo^ _Round_EDecimal { 
        MethodInfo^ get() { if (__Round_EDecimal == nullptr) 
          __Round_EDecimal = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ EDecimal::WrappedType }); return __Round_EDecimal; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of EDecimal places.
      /// </summary>
      static EDecimal Round(EDecimal d)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Round_EDecimal, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Round_EDouble;
    	static property MethodInfo^ _Round_EDouble { 
        MethodInfo^ get() { if (__Round_EDouble == nullptr) 
          __Round_EDouble = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ EDouble::WrappedType }); return __Round_EDouble; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of EDecimal places.
      /// </summary>
      static EDouble Round(EDouble a)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Round_EDouble, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Round_EDecimal_EInt;
    	static property MethodInfo^ _Round_EDecimal_EInt { 
        MethodInfo^ get() { if (__Round_EDecimal_EInt == nullptr) 
          __Round_EDecimal_EInt = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ EDecimal::WrappedType, EInt::WrappedType }); return __Round_EDecimal_EInt; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of EDecimal places.
      /// </summary>
      static EDecimal Round(EDecimal d, EInt EDecimals)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Round_EDecimal_EInt, nullptr, gcnew array<GenericExpression^>{d, EDecimals}));
      }

    private:
    	static MethodInfo^ __Round_EDouble_EInt;
    	static property MethodInfo^ _Round_EDouble_EInt { 
        MethodInfo^ get() { if (__Round_EDouble_EInt == nullptr) 
          __Round_EDouble_EInt = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ EDouble::WrappedType, EInt::WrappedType }); return __Round_EDouble_EInt; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of EDecimal places.
      /// </summary>
      static EDouble Round(EDouble value, EInt digits)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Round_EDouble_EInt, nullptr, gcnew array<GenericExpression^>{value, digits}));
      }

    private:
    	static MethodInfo^ __Sign_EDecimal;
    	static property MethodInfo^ _Sign_EDecimal { 
        MethodInfo^ get() { if (__Sign_EDecimal == nullptr) 
          __Sign_EDecimal = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ EDecimal::WrappedType }); return __Sign_EDecimal; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static EInt Sign(EDecimal value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Sign_EDecimal, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_EDouble;
    	static property MethodInfo^ _Sign_EDouble { 
        MethodInfo^ get() { if (__Sign_EDouble == nullptr) 
          __Sign_EDouble = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ EDouble::WrappedType }); return __Sign_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static EInt Sign(EDouble value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Sign_EDouble, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_EFloat;
    	static property MethodInfo^ _Sign_EFloat { 
        MethodInfo^ get() { if (__Sign_EFloat == nullptr) 
          __Sign_EFloat = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ EFloat::WrappedType }); return __Sign_EFloat; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static EInt Sign(EFloat value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Sign_EFloat, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_EInt;
    	static property MethodInfo^ _Sign_EInt { 
        MethodInfo^ get() { if (__Sign_EInt == nullptr) 
          __Sign_EInt = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ EInt::WrappedType }); return __Sign_EInt; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static EInt Sign(EInt value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Sign_EInt, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_ELong;
    	static property MethodInfo^ _Sign_ELong { 
        MethodInfo^ get() { if (__Sign_ELong == nullptr) 
          __Sign_ELong = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ ELong::WrappedType }); return __Sign_ELong; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static EInt Sign(ELong value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Sign_ELong, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_ESByte;
    	static property MethodInfo^ _Sign_ESByte { 
        MethodInfo^ get() { if (__Sign_ESByte == nullptr) 
          __Sign_ESByte = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ ESByte::WrappedType }); return __Sign_ESByte; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static EInt Sign(ESByte value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Sign_ESByte, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_EShort;
    	static property MethodInfo^ _Sign_EShort { 
        MethodInfo^ get() { if (__Sign_EShort == nullptr) 
          __Sign_EShort = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ EShort::WrappedType }); return __Sign_EShort; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static EInt Sign(EShort value)
  		{
	  		return EInt(gcnew MethodInvokeExpression<int>
          (_Sign_EShort, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sin_EDouble;
    	static property MethodInfo^ _Sin_EDouble { 
        MethodInfo^ get() { if (__Sin_EDouble == nullptr) 
          __Sin_EDouble = (System::Math::typeid)->GetMethod("Sin", gcnew array<Type^>{ EDouble::WrappedType }); return __Sin_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the sine of the specified angle.
      /// </summary>
      static EDouble Sin(EDouble a)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Sin_EDouble, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Sinh_EDouble;
    	static property MethodInfo^ _Sinh_EDouble { 
        MethodInfo^ get() { if (__Sinh_EDouble == nullptr) 
          __Sinh_EDouble = (System::Math::typeid)->GetMethod("Sinh", gcnew array<Type^>{ EDouble::WrappedType }); return __Sinh_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the hyperbolic sine of the specified angle.
      /// </summary>
      static EDouble Sinh(EDouble value)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Sinh_EDouble, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sqrt_EDouble;
    	static property MethodInfo^ _Sqrt_EDouble { 
        MethodInfo^ get() { if (__Sqrt_EDouble == nullptr) 
          __Sqrt_EDouble = (System::Math::typeid)->GetMethod("Sqrt", gcnew array<Type^>{ EDouble::WrappedType }); return __Sqrt_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the square root of a specified number.
      /// </summary>
      static EDouble Sqrt(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Sqrt_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Tan_EDouble;
    	static property MethodInfo^ _Tan_EDouble { 
        MethodInfo^ get() { if (__Tan_EDouble == nullptr) 
          __Tan_EDouble = (System::Math::typeid)->GetMethod("Tan", gcnew array<Type^>{ EDouble::WrappedType }); return __Tan_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the tangent of the specified angle.
      /// </summary>
      static EDouble Tan(EDouble a)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Tan_EDouble, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Tanh_EDouble;
    	static property MethodInfo^ _Tanh_EDouble { 
        MethodInfo^ get() { if (__Tanh_EDouble == nullptr) 
          __Tanh_EDouble = (System::Math::typeid)->GetMethod("Tanh", gcnew array<Type^>{ EDouble::WrappedType }); return __Tanh_EDouble; 
        } }
    public:
      /// <summary>
      /// Returns the hyperbolic tangent of the specified angle.
      /// </summary>
      static EDouble Tanh(EDouble value)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Tanh_EDouble, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Truncate_EDecimal;
    	static property MethodInfo^ _Truncate_EDecimal { 
        MethodInfo^ get() { if (__Truncate_EDecimal == nullptr) 
          __Truncate_EDecimal = (System::Math::typeid)->GetMethod("Truncate", gcnew array<Type^>{ EDecimal::WrappedType }); return __Truncate_EDecimal; 
        } }
    public:
      /// <summary>
      /// Calculates the integral part of a number.
      /// </summary>
      static EDecimal Truncate(EDecimal d)
  		{
	  		return EDecimal(gcnew MethodInvokeExpression<System::Decimal>
          (_Truncate_EDecimal, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Truncate_EDouble;
    	static property MethodInfo^ _Truncate_EDouble { 
        MethodInfo^ get() { if (__Truncate_EDouble == nullptr) 
          __Truncate_EDouble = (System::Math::typeid)->GetMethod("Truncate", gcnew array<Type^>{ EDouble::WrappedType }); return __Truncate_EDouble; 
        } }
    public:
      /// <summary>
      /// Calculates the integral part of a number.
      /// </summary>
      static EDouble Truncate(EDouble d)
  		{
	  		return EDouble(gcnew MethodInvokeExpression<double>
          (_Truncate_EDouble, nullptr, gcnew array<GenericExpression^>{d}));
      }

    };
    

    /// <summary>
    /// Class that represents variable of type unsigned char.
    /// </summary>
    public ref class VByte : ExpressionWrapper<unsigned char>
    {
		public:
			VByte(String^ name)
			{
				_value = gcnew Variable<unsigned char>(name);
			}
			operator Expression<unsigned char>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type signed char.
    /// </summary>
    public ref class VSByte : ExpressionWrapper<signed char>
    {
		public:
			VSByte(String^ name)
			{
				_value = gcnew Variable<signed char>(name);
			}
			operator Expression<signed char>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type float.
    /// </summary>
    public ref class VFloat : ExpressionWrapper<float>
    {
		public:
			VFloat(String^ name)
			{
				_value = gcnew Variable<float>(name);
			}
			operator Expression<float>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type double.
    /// </summary>
    public ref class VDouble : ExpressionWrapper<double>
    {
		public:
			VDouble(String^ name)
			{
				_value = gcnew Variable<double>(name);
			}
			operator Expression<double>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type System::Decimal.
    /// </summary>
    public ref class VDecimal : ExpressionWrapper<System::Decimal>
    {
		public:
			VDecimal(String^ name)
			{
				_value = gcnew Variable<System::Decimal>(name);
			}
			operator Expression<System::Decimal>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type long long int (Int64).
    /// </summary>
    public ref class VLong : ExpressionWrapper<long long int>
    {
		public:
			VLong(String^ name)
			{
				_value = gcnew Variable<long long int>(name);
			}
			operator Expression<long long int>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type short (Int16).
    /// </summary>
    public ref class VShort : ExpressionWrapper<short>
    {
		public:
			VShort(String^ name)
			{
				_value = gcnew Variable<short>(name);
			}
			operator Expression<short>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type int (Int32).
    /// </summary>
    public ref class VInt : ExpressionWrapper<int>
    {
		public:
			VInt(String^ name)
			{
				_value = gcnew Variable<int>(name);
			}
			operator Expression<int>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type unsigned long long int (UInt64).
    /// </summary>
    public ref class VULong : ExpressionWrapper<unsigned long long int>
    {
		public:
			VULong(String^ name)
			{
				_value = gcnew Variable<unsigned long long int>(name);
			}
			operator Expression<unsigned long long int>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type unsigned short (UInt16).
    /// </summary>
    public ref class VUShort : ExpressionWrapper<unsigned short>
    {
		public:
			VUShort(String^ name)
			{
				_value = gcnew Variable<unsigned short>(name);
			}
			operator Expression<unsigned short>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type unsigned int (UInt32).
    /// </summary>
    public ref class VUInt : ExpressionWrapper<unsigned int>
    {
		public:
			VUInt(String^ name)
			{
				_value = gcnew Variable<unsigned int>(name);
			}
			operator Expression<unsigned int>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type bool.
    /// </summary>
    public ref class VBool : ExpressionWrapper<bool>
    {
		public:
			VBool(String^ name)
			{
				_value = gcnew Variable<bool>(name);
			}
			operator Expression<bool>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type unicode wchar_t (Char).
    /// </summary>
    public ref class VChar : ExpressionWrapper<wchar_t>
    {
		public:
			VChar(String^ name)
			{
				_value = gcnew Variable<wchar_t>(name);
			}
			operator Expression<wchar_t>^()
			{
				return _value;
			}
		};    

    /// <summary>
    /// Class that represents variable of type System::String.
    /// </summary>
    public ref class VString : ExpressionWrapper<String^>
    {
		public:
			VString(String^ name)
			{
				_value = gcnew Variable<String^>(name);
			}
			operator Expression<String^>^()
			{
				return _value;
			}
		};    

  } 
}
