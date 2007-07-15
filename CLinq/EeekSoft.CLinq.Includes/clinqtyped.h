
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
	namespace CLinq {
    /// <summary>
    /// Template specialization for the 'bool' expresion. Implements operators !=, == and logical operators (&amp;&amp;, ||) and unary !.
    /// </summary>
    template<> public ref class Expr<bool> : ExpressionWrapper<bool>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return bool::typeid; } }
    
		public:
			Expr<bool>() { }
      Expr<bool>(bool val) { _value = gcnew Literal<bool>(val); }
      Expr<bool>(Expression<bool>^ value) { _value = value; }
			Expr<bool>(Expr<bool>% b)	{ _value = b._value; }
			operator Expression<bool>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<bool>(Expression<bool>^ value)  { return Expr<bool>(value); }
			static operator Expr<bool>(bool b) { return Expr<bool>(b); }
      
      

    public:
    static Expr<bool> Typed(GenericExpression^ value) 
      { 
        return Expr<bool>(gcnew TypedExpression<bool>(value));
      }

      static Expr<bool> Convert(GenericExpression^ value) 
      { 
        return Expr<bool>(gcnew ConvertExpression<bool>(value));
      }

    public:
      
      /// <summary>
      /// Returns negation of the logical value.
      /// </summary>
      static Expr<bool> operator!(Expr<bool> value)
      {
        return Expr<bool>(gcnew UnaryExpression<bool,bool>
          (value, System::Expressions::ExpressionType::Not));
      }

      /// <summary>
      /// Test values for equality.
      /// </summary>
      static Expr<bool> operator==(Expr<bool> left, Expr<bool> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Test values for inequality.
      /// </summary>
      static Expr<bool> operator!=(Expr<bool> left, Expr<bool> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::NE));
      }

      /// <summary>
      /// Performs logical 'and' operation.
      /// </summary>
      static Expr<bool> operator&&(Expr<bool> left, Expr<bool> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::And));
      }

      /// <summary>
      /// Performs logical 'or' operation.
      /// </summary>
      static Expr<bool> operator||(Expr<bool> left, Expr<bool> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,bool,bool>
          (left, right, System::Expressions::ExpressionType::Or));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<double>' expresion. Supports standard math and comparison operators.
    /// </summary>
    template<> public ref class Expr<Nullable<double>> : ExpressionWrapper<Nullable<double>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<double>::typeid; } }
    
		public:
			Expr<Nullable<double>>() { }
      Expr<Nullable<double>>(Nullable<double> val) { _value = gcnew Literal<Nullable<double>>(val); }
      Expr<Nullable<double>>(Expression<Nullable<double>>^ value) { _value = value; }
			Expr<Nullable<double>>(Expr<Nullable<double>>% b)	{ _value = b._value; }
			operator Expression<Nullable<double>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<double>>(Expression<Nullable<double>>^ value)  { return Expr<Nullable<double>>(value); }
			static operator Expr<Nullable<double>>(Nullable<double> b) { return Expr<Nullable<double>>(b); }
      
      

    public:
    static Expr<Nullable<double>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<double>>(gcnew TypedExpression<Nullable<double>>(value));
      }

      static Expr<Nullable<double>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<double>>(gcnew ConvertExpression<Nullable<double>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<Nullable<double>> operator+(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<Nullable<double>>(gcnew BinaryExpression<Nullable<double>,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<Nullable<double>> operator*(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<Nullable<double>>(gcnew BinaryExpression<Nullable<double>,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<Nullable<double>> operator/(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<Nullable<double>>(gcnew BinaryExpression<Nullable<double>,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<Nullable<double>> operator-(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<Nullable<double>>(gcnew BinaryExpression<Nullable<double>,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<double>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<double>> left, Expr<Nullable<double>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<double>,Nullable<double>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<float>' expresion. Supports standard math and comparison operators.
    /// </summary>
    template<> public ref class Expr<Nullable<float>> : ExpressionWrapper<Nullable<float>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<float>::typeid; } }
    
		public:
			Expr<Nullable<float>>() { }
      Expr<Nullable<float>>(Nullable<float> val) { _value = gcnew Literal<Nullable<float>>(val); }
      Expr<Nullable<float>>(Expression<Nullable<float>>^ value) { _value = value; }
			Expr<Nullable<float>>(Expr<Nullable<float>>% b)	{ _value = b._value; }
			operator Expression<Nullable<float>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<float>>(Expression<Nullable<float>>^ value)  { return Expr<Nullable<float>>(value); }
			static operator Expr<Nullable<float>>(Nullable<float> b) { return Expr<Nullable<float>>(b); }
      
      

    public:
    static Expr<Nullable<float>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<float>>(gcnew TypedExpression<Nullable<float>>(value));
      }

      static Expr<Nullable<float>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<float>>(gcnew ConvertExpression<Nullable<float>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<Nullable<float>> operator+(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<Nullable<float>>(gcnew BinaryExpression<Nullable<float>,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<Nullable<float>> operator*(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<Nullable<float>>(gcnew BinaryExpression<Nullable<float>,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<Nullable<float>> operator/(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<Nullable<float>>(gcnew BinaryExpression<Nullable<float>,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<Nullable<float>> operator-(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<Nullable<float>>(gcnew BinaryExpression<Nullable<float>,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<float>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<float>> left, Expr<Nullable<float>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<float>,Nullable<float>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<System::Decimal>' expresion. Supports standard math and comparison operators.
    /// </summary>
    template<> public ref class Expr<Nullable<System::Decimal>> : ExpressionWrapper<Nullable<System::Decimal>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<System::Decimal>::typeid; } }
    
		public:
			Expr<Nullable<System::Decimal>>() { }
      Expr<Nullable<System::Decimal>>(Nullable<System::Decimal> val) { _value = gcnew Literal<Nullable<System::Decimal>>(val); }
      Expr<Nullable<System::Decimal>>(Expression<Nullable<System::Decimal>>^ value) { _value = value; }
			Expr<Nullable<System::Decimal>>(Expr<Nullable<System::Decimal>>% b)	{ _value = b._value; }
			operator Expression<Nullable<System::Decimal>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<System::Decimal>>(Expression<Nullable<System::Decimal>>^ value)  { return Expr<Nullable<System::Decimal>>(value); }
			static operator Expr<Nullable<System::Decimal>>(Nullable<System::Decimal> b) { return Expr<Nullable<System::Decimal>>(b); }
      
      

    public:
    static Expr<Nullable<System::Decimal>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<System::Decimal>>(gcnew TypedExpression<Nullable<System::Decimal>>(value));
      }

      static Expr<Nullable<System::Decimal>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<System::Decimal>>(gcnew ConvertExpression<Nullable<System::Decimal>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<Nullable<System::Decimal>> operator+(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<Nullable<System::Decimal>>(gcnew BinaryExpression<Nullable<System::Decimal>,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<Nullable<System::Decimal>> operator*(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<Nullable<System::Decimal>>(gcnew BinaryExpression<Nullable<System::Decimal>,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<Nullable<System::Decimal>> operator/(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<Nullable<System::Decimal>>(gcnew BinaryExpression<Nullable<System::Decimal>,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<Nullable<System::Decimal>> operator-(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<Nullable<System::Decimal>>(gcnew BinaryExpression<Nullable<System::Decimal>,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<System::Decimal>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<System::Decimal>> left, Expr<Nullable<System::Decimal>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<System::Decimal>,Nullable<System::Decimal>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<long long int>' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<Nullable<long long int>> : ExpressionWrapper<Nullable<long long int>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<long long int>::typeid; } }
    
		public:
			Expr<Nullable<long long int>>() { }
      Expr<Nullable<long long int>>(Nullable<long long int> val) { _value = gcnew Literal<Nullable<long long int>>(val); }
      Expr<Nullable<long long int>>(Expression<Nullable<long long int>>^ value) { _value = value; }
			Expr<Nullable<long long int>>(Expr<Nullable<long long int>>% b)	{ _value = b._value; }
			operator Expression<Nullable<long long int>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<long long int>>(Expression<Nullable<long long int>>^ value)  { return Expr<Nullable<long long int>>(value); }
			static operator Expr<Nullable<long long int>>(Nullable<long long int> b) { return Expr<Nullable<long long int>>(b); }
      
      

    public:
    static Expr<Nullable<long long int>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<long long int>>(gcnew TypedExpression<Nullable<long long int>>(value));
      }

      static Expr<Nullable<long long int>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<long long int>>(gcnew ConvertExpression<Nullable<long long int>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<Nullable<long long int>> operator+(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<Nullable<long long int>>(gcnew BinaryExpression<Nullable<long long int>,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<Nullable<long long int>> operator*(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<Nullable<long long int>>(gcnew BinaryExpression<Nullable<long long int>,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<Nullable<long long int>> operator/(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<Nullable<long long int>>(gcnew BinaryExpression<Nullable<long long int>,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<Nullable<long long int>> operator-(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<Nullable<long long int>>(gcnew BinaryExpression<Nullable<long long int>,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<long long int>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<long long int>> left, Expr<Nullable<long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<long long int>,Nullable<long long int>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<unsigned long long int>' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<Nullable<unsigned long long int>> : ExpressionWrapper<Nullable<unsigned long long int>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<unsigned long long int>::typeid; } }
    
		public:
			Expr<Nullable<unsigned long long int>>() { }
      Expr<Nullable<unsigned long long int>>(Nullable<unsigned long long int> val) { _value = gcnew Literal<Nullable<unsigned long long int>>(val); }
      Expr<Nullable<unsigned long long int>>(Expression<Nullable<unsigned long long int>>^ value) { _value = value; }
			Expr<Nullable<unsigned long long int>>(Expr<Nullable<unsigned long long int>>% b)	{ _value = b._value; }
			operator Expression<Nullable<unsigned long long int>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<unsigned long long int>>(Expression<Nullable<unsigned long long int>>^ value)  { return Expr<Nullable<unsigned long long int>>(value); }
			static operator Expr<Nullable<unsigned long long int>>(Nullable<unsigned long long int> b) { return Expr<Nullable<unsigned long long int>>(b); }
      
      

    public:
    static Expr<Nullable<unsigned long long int>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned long long int>>(gcnew TypedExpression<Nullable<unsigned long long int>>(value));
      }

      static Expr<Nullable<unsigned long long int>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned long long int>>(gcnew ConvertExpression<Nullable<unsigned long long int>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<Nullable<unsigned long long int>> operator+(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<Nullable<unsigned long long int>>(gcnew BinaryExpression<Nullable<unsigned long long int>,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<Nullable<unsigned long long int>> operator*(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<Nullable<unsigned long long int>>(gcnew BinaryExpression<Nullable<unsigned long long int>,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<Nullable<unsigned long long int>> operator/(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<Nullable<unsigned long long int>>(gcnew BinaryExpression<Nullable<unsigned long long int>,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<Nullable<unsigned long long int>> operator-(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<Nullable<unsigned long long int>>(gcnew BinaryExpression<Nullable<unsigned long long int>,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<unsigned long long int>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<unsigned long long int>> left, Expr<Nullable<unsigned long long int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned long long int>,Nullable<unsigned long long int>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<int>' expresion. Supports standard math and comparison operators (including modulo and shifts).
    /// </summary>
    template<> public ref class Expr<Nullable<int>> : ExpressionWrapper<Nullable<int>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<int>::typeid; } }
    
		public:
			Expr<Nullable<int>>() { }
      Expr<Nullable<int>>(Nullable<int> val) { _value = gcnew Literal<Nullable<int>>(val); }
      Expr<Nullable<int>>(Expression<Nullable<int>>^ value) { _value = value; }
			Expr<Nullable<int>>(Expr<Nullable<int>>% b)	{ _value = b._value; }
			operator Expression<Nullable<int>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<int>>(Expression<Nullable<int>>^ value)  { return Expr<Nullable<int>>(value); }
			static operator Expr<Nullable<int>>(Nullable<int> b) { return Expr<Nullable<int>>(b); }
      
      

    public:
    static Expr<Nullable<int>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<int>>(gcnew TypedExpression<Nullable<int>>(value));
      }

      static Expr<Nullable<int>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<int>>(gcnew ConvertExpression<Nullable<int>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<Nullable<int>> operator+(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<Nullable<int>>(gcnew BinaryExpression<Nullable<int>,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<Nullable<int>> operator*(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<Nullable<int>>(gcnew BinaryExpression<Nullable<int>,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<Nullable<int>> operator/(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<Nullable<int>>(gcnew BinaryExpression<Nullable<int>,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<Nullable<int>> operator-(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<Nullable<int>>(gcnew BinaryExpression<Nullable<int>,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

      /// <summary>
      /// Shift left operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<Nullable<int>> operator<<(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<Nullable<int>>(gcnew BinaryExpression<Nullable<int>,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::LShift));
      }

      /// <summary>
      /// Shift right operator for tuple of Expr<Nullable<int>> types.
      /// </summary>
      static Expr<Nullable<int>> operator>>(Expr<Nullable<int>> left, Expr<Nullable<int>> right)
      {
        return Expr<Nullable<int>>(gcnew BinaryExpression<Nullable<int>,Nullable<int>,Nullable<int>>
          (left, right, System::Expressions::ExpressionType::RShift));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<unsigned int>' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<Nullable<unsigned int>> : ExpressionWrapper<Nullable<unsigned int>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<unsigned int>::typeid; } }
    
		public:
			Expr<Nullable<unsigned int>>() { }
      Expr<Nullable<unsigned int>>(Nullable<unsigned int> val) { _value = gcnew Literal<Nullable<unsigned int>>(val); }
      Expr<Nullable<unsigned int>>(Expression<Nullable<unsigned int>>^ value) { _value = value; }
			Expr<Nullable<unsigned int>>(Expr<Nullable<unsigned int>>% b)	{ _value = b._value; }
			operator Expression<Nullable<unsigned int>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<unsigned int>>(Expression<Nullable<unsigned int>>^ value)  { return Expr<Nullable<unsigned int>>(value); }
			static operator Expr<Nullable<unsigned int>>(Nullable<unsigned int> b) { return Expr<Nullable<unsigned int>>(b); }
      
      

    public:
    static Expr<Nullable<unsigned int>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned int>>(gcnew TypedExpression<Nullable<unsigned int>>(value));
      }

      static Expr<Nullable<unsigned int>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned int>>(gcnew ConvertExpression<Nullable<unsigned int>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<Nullable<unsigned int>> operator+(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<Nullable<unsigned int>>(gcnew BinaryExpression<Nullable<unsigned int>,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<Nullable<unsigned int>> operator*(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<Nullable<unsigned int>>(gcnew BinaryExpression<Nullable<unsigned int>,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<Nullable<unsigned int>> operator/(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<Nullable<unsigned int>>(gcnew BinaryExpression<Nullable<unsigned int>,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<Nullable<unsigned int>> operator-(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<Nullable<unsigned int>>(gcnew BinaryExpression<Nullable<unsigned int>,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<unsigned int>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<unsigned int>> left, Expr<Nullable<unsigned int>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned int>,Nullable<unsigned int>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<short>' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<Nullable<short>> : ExpressionWrapper<Nullable<short>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<short>::typeid; } }
    
		public:
			Expr<Nullable<short>>() { }
      Expr<Nullable<short>>(Nullable<short> val) { _value = gcnew Literal<Nullable<short>>(val); }
      Expr<Nullable<short>>(Expression<Nullable<short>>^ value) { _value = value; }
			Expr<Nullable<short>>(Expr<Nullable<short>>% b)	{ _value = b._value; }
			operator Expression<Nullable<short>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<short>>(Expression<Nullable<short>>^ value)  { return Expr<Nullable<short>>(value); }
			static operator Expr<Nullable<short>>(Nullable<short> b) { return Expr<Nullable<short>>(b); }
      
      

    public:
    static Expr<Nullable<short>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<short>>(gcnew TypedExpression<Nullable<short>>(value));
      }

      static Expr<Nullable<short>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<short>>(gcnew ConvertExpression<Nullable<short>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<Nullable<short>> operator+(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<Nullable<short>>(gcnew BinaryExpression<Nullable<short>,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<Nullable<short>> operator*(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<Nullable<short>>(gcnew BinaryExpression<Nullable<short>,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<Nullable<short>> operator/(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<Nullable<short>>(gcnew BinaryExpression<Nullable<short>,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<Nullable<short>> operator-(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<Nullable<short>>(gcnew BinaryExpression<Nullable<short>,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<short>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<short>> left, Expr<Nullable<short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<short>,Nullable<short>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<unsigned short>' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<Nullable<unsigned short>> : ExpressionWrapper<Nullable<unsigned short>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<unsigned short>::typeid; } }
    
		public:
			Expr<Nullable<unsigned short>>() { }
      Expr<Nullable<unsigned short>>(Nullable<unsigned short> val) { _value = gcnew Literal<Nullable<unsigned short>>(val); }
      Expr<Nullable<unsigned short>>(Expression<Nullable<unsigned short>>^ value) { _value = value; }
			Expr<Nullable<unsigned short>>(Expr<Nullable<unsigned short>>% b)	{ _value = b._value; }
			operator Expression<Nullable<unsigned short>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<unsigned short>>(Expression<Nullable<unsigned short>>^ value)  { return Expr<Nullable<unsigned short>>(value); }
			static operator Expr<Nullable<unsigned short>>(Nullable<unsigned short> b) { return Expr<Nullable<unsigned short>>(b); }
      
      

    public:
    static Expr<Nullable<unsigned short>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned short>>(gcnew TypedExpression<Nullable<unsigned short>>(value));
      }

      static Expr<Nullable<unsigned short>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned short>>(gcnew ConvertExpression<Nullable<unsigned short>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<Nullable<unsigned short>> operator+(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<Nullable<unsigned short>>(gcnew BinaryExpression<Nullable<unsigned short>,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<Nullable<unsigned short>> operator*(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<Nullable<unsigned short>>(gcnew BinaryExpression<Nullable<unsigned short>,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<Nullable<unsigned short>> operator/(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<Nullable<unsigned short>>(gcnew BinaryExpression<Nullable<unsigned short>,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<Nullable<unsigned short>> operator-(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<Nullable<unsigned short>>(gcnew BinaryExpression<Nullable<unsigned short>,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<unsigned short>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<unsigned short>> left, Expr<Nullable<unsigned short>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned short>,Nullable<unsigned short>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<unsigned char>' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<Nullable<unsigned char>> : ExpressionWrapper<Nullable<unsigned char>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<unsigned char>::typeid; } }
    
		public:
			Expr<Nullable<unsigned char>>() { }
      Expr<Nullable<unsigned char>>(Nullable<unsigned char> val) { _value = gcnew Literal<Nullable<unsigned char>>(val); }
      Expr<Nullable<unsigned char>>(Expression<Nullable<unsigned char>>^ value) { _value = value; }
			Expr<Nullable<unsigned char>>(Expr<Nullable<unsigned char>>% b)	{ _value = b._value; }
			operator Expression<Nullable<unsigned char>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<unsigned char>>(Expression<Nullable<unsigned char>>^ value)  { return Expr<Nullable<unsigned char>>(value); }
			static operator Expr<Nullable<unsigned char>>(Nullable<unsigned char> b) { return Expr<Nullable<unsigned char>>(b); }
      
      

    public:
    static Expr<Nullable<unsigned char>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned char>>(gcnew TypedExpression<Nullable<unsigned char>>(value));
      }

      static Expr<Nullable<unsigned char>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<unsigned char>>(gcnew ConvertExpression<Nullable<unsigned char>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<Nullable<unsigned char>> operator+(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<Nullable<unsigned char>>(gcnew BinaryExpression<Nullable<unsigned char>,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<Nullable<unsigned char>> operator*(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<Nullable<unsigned char>>(gcnew BinaryExpression<Nullable<unsigned char>,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<Nullable<unsigned char>> operator/(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<Nullable<unsigned char>>(gcnew BinaryExpression<Nullable<unsigned char>,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<Nullable<unsigned char>> operator-(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<Nullable<unsigned char>>(gcnew BinaryExpression<Nullable<unsigned char>,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<unsigned char>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<unsigned char>> left, Expr<Nullable<unsigned char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<unsigned char>,Nullable<unsigned char>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<signed char>' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<Nullable<signed char>> : ExpressionWrapper<Nullable<signed char>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<signed char>::typeid; } }
    
		public:
			Expr<Nullable<signed char>>() { }
      Expr<Nullable<signed char>>(Nullable<signed char> val) { _value = gcnew Literal<Nullable<signed char>>(val); }
      Expr<Nullable<signed char>>(Expression<Nullable<signed char>>^ value) { _value = value; }
			Expr<Nullable<signed char>>(Expr<Nullable<signed char>>% b)	{ _value = b._value; }
			operator Expression<Nullable<signed char>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<signed char>>(Expression<Nullable<signed char>>^ value)  { return Expr<Nullable<signed char>>(value); }
			static operator Expr<Nullable<signed char>>(Nullable<signed char> b) { return Expr<Nullable<signed char>>(b); }
      
      

    public:
    static Expr<Nullable<signed char>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<signed char>>(gcnew TypedExpression<Nullable<signed char>>(value));
      }

      static Expr<Nullable<signed char>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<signed char>>(gcnew ConvertExpression<Nullable<signed char>>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<Nullable<signed char>> operator+(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<Nullable<signed char>>(gcnew BinaryExpression<Nullable<signed char>,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<Nullable<signed char>> operator*(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<Nullable<signed char>>(gcnew BinaryExpression<Nullable<signed char>,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<Nullable<signed char>> operator/(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<Nullable<signed char>>(gcnew BinaryExpression<Nullable<signed char>,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<Nullable<signed char>> operator-(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<Nullable<signed char>>(gcnew BinaryExpression<Nullable<signed char>,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<bool> operator==(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<bool> operator<(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<bool> operator>(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<Nullable<signed char>> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<Nullable<signed char>> left, Expr<Nullable<signed char>> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,Nullable<signed char>,Nullable<signed char>>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'double' expresion. Supports standard math and comparison operators.
    /// </summary>
    template<> public ref class Expr<double> : ExpressionWrapper<double>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return double::typeid; } }
    
		public:
			Expr<double>() { }
      Expr<double>(double val) { _value = gcnew Literal<double>(val); }
      Expr<double>(Expression<double>^ value) { _value = value; }
			Expr<double>(Expr<double>% b)	{ _value = b._value; }
			operator Expression<double>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<double>(Expression<double>^ value)  { return Expr<double>(value); }
			static operator Expr<double>(double b) { return Expr<double>(b); }
      
      

    public:
    static Expr<double> Typed(GenericExpression^ value) 
      { 
        return Expr<double>(gcnew TypedExpression<double>(value));
      }

      static Expr<double> Convert(GenericExpression^ value) 
      { 
        return Expr<double>(gcnew ConvertExpression<double>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<double> operator+(Expr<double> left, Expr<double> right)
      {
        return Expr<double>(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<double> operator*(Expr<double> left, Expr<double> right)
      {
        return Expr<double>(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<double> operator/(Expr<double> left, Expr<double> right)
      {
        return Expr<double>(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<double> operator-(Expr<double> left, Expr<double> right)
      {
        return Expr<double>(gcnew BinaryExpression<double,double,double>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<bool> operator==(Expr<double> left, Expr<double> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<double> left, Expr<double> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<bool> operator<(Expr<double> left, Expr<double> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<bool> operator>(Expr<double> left, Expr<double> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<double> left, Expr<double> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<double> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<double> left, Expr<double> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,double,double>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'float' expresion. Supports standard math and comparison operators.
    /// </summary>
    template<> public ref class Expr<float> : ExpressionWrapper<float>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return float::typeid; } }
    
		public:
			Expr<float>() { }
      Expr<float>(float val) { _value = gcnew Literal<float>(val); }
      Expr<float>(Expression<float>^ value) { _value = value; }
			Expr<float>(Expr<float>% b)	{ _value = b._value; }
			operator Expression<float>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<float>(Expression<float>^ value)  { return Expr<float>(value); }
			static operator Expr<float>(float b) { return Expr<float>(b); }
      
      
      operator Expr<double>() { return Expr<double>::Convert(_value); }

    public:
    static Expr<float> Typed(GenericExpression^ value) 
      { 
        return Expr<float>(gcnew TypedExpression<float>(value));
      }

      static Expr<float> Convert(GenericExpression^ value) 
      { 
        return Expr<float>(gcnew ConvertExpression<float>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<float> operator+(Expr<float> left, Expr<float> right)
      {
        return Expr<float>(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<float> operator*(Expr<float> left, Expr<float> right)
      {
        return Expr<float>(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<float> operator/(Expr<float> left, Expr<float> right)
      {
        return Expr<float>(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<float> operator-(Expr<float> left, Expr<float> right)
      {
        return Expr<float>(gcnew BinaryExpression<float,float,float>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<bool> operator==(Expr<float> left, Expr<float> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<float> left, Expr<float> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<bool> operator<(Expr<float> left, Expr<float> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<bool> operator>(Expr<float> left, Expr<float> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<float> left, Expr<float> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<float> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<float> left, Expr<float> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,float,float>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'System::Decimal' expresion. Supports standard math and comparison operators.
    /// </summary>
    template<> public ref class Expr<System::Decimal> : ExpressionWrapper<System::Decimal>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return System::Decimal::typeid; } }
    
		public:
			Expr<System::Decimal>() { }
      Expr<System::Decimal>(System::Decimal val) { _value = gcnew Literal<System::Decimal>(val); }
      Expr<System::Decimal>(Expression<System::Decimal>^ value) { _value = value; }
			Expr<System::Decimal>(Expr<System::Decimal>% b)	{ _value = b._value; }
			operator Expression<System::Decimal>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<System::Decimal>(Expression<System::Decimal>^ value)  { return Expr<System::Decimal>(value); }
			static operator Expr<System::Decimal>(System::Decimal b) { return Expr<System::Decimal>(b); }
      
      

    public:
    static Expr<System::Decimal> Typed(GenericExpression^ value) 
      { 
        return Expr<System::Decimal>(gcnew TypedExpression<System::Decimal>(value));
      }

      static Expr<System::Decimal> Convert(GenericExpression^ value) 
      { 
        return Expr<System::Decimal>(gcnew ConvertExpression<System::Decimal>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<System::Decimal> operator+(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<System::Decimal>(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<System::Decimal> operator*(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<System::Decimal>(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<System::Decimal> operator/(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<System::Decimal>(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<System::Decimal> operator-(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<System::Decimal>(gcnew BinaryExpression<System::Decimal,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<bool> operator==(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<bool> operator<(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<bool> operator>(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<System::Decimal> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<System::Decimal> left, Expr<System::Decimal> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,System::Decimal,System::Decimal>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'long long int' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<long long int> : ExpressionWrapper<long long int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return long long int::typeid; } }
    
		public:
			Expr<long long int>() { }
      Expr<long long int>(long long int val) { _value = gcnew Literal<long long int>(val); }
      Expr<long long int>(Expression<long long int>^ value) { _value = value; }
			Expr<long long int>(Expr<long long int>% b)	{ _value = b._value; }
			operator Expression<long long int>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<long long int>(Expression<long long int>^ value)  { return Expr<long long int>(value); }
			static operator Expr<long long int>(long long int b) { return Expr<long long int>(b); }
      
      

    public:
    static Expr<long long int> Typed(GenericExpression^ value) 
      { 
        return Expr<long long int>(gcnew TypedExpression<long long int>(value));
      }

      static Expr<long long int> Convert(GenericExpression^ value) 
      { 
        return Expr<long long int>(gcnew ConvertExpression<long long int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<long long int> operator+(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<long long int>(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<long long int> operator*(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<long long int>(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<long long int> operator/(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<long long int>(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<long long int> operator-(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<long long int>(gcnew BinaryExpression<long long int,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<bool> operator==(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<bool> operator<(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<bool> operator>(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<long long int> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<long long int> left, Expr<long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,long long int,long long int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'unsigned long long int' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<unsigned long long int> : ExpressionWrapper<unsigned long long int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned long long int::typeid; } }
    
		public:
			Expr<unsigned long long int>() { }
      Expr<unsigned long long int>(unsigned long long int val) { _value = gcnew Literal<unsigned long long int>(val); }
      Expr<unsigned long long int>(Expression<unsigned long long int>^ value) { _value = value; }
			Expr<unsigned long long int>(Expr<unsigned long long int>% b)	{ _value = b._value; }
			operator Expression<unsigned long long int>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<unsigned long long int>(Expression<unsigned long long int>^ value)  { return Expr<unsigned long long int>(value); }
			static operator Expr<unsigned long long int>(unsigned long long int b) { return Expr<unsigned long long int>(b); }
      
      

    public:
    static Expr<unsigned long long int> Typed(GenericExpression^ value) 
      { 
        return Expr<unsigned long long int>(gcnew TypedExpression<unsigned long long int>(value));
      }

      static Expr<unsigned long long int> Convert(GenericExpression^ value) 
      { 
        return Expr<unsigned long long int>(gcnew ConvertExpression<unsigned long long int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<unsigned long long int> operator+(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<unsigned long long int>(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<unsigned long long int> operator*(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<unsigned long long int>(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<unsigned long long int> operator/(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<unsigned long long int>(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<unsigned long long int> operator-(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<unsigned long long int>(gcnew BinaryExpression<unsigned long long int,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<bool> operator==(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<bool> operator<(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<bool> operator>(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<unsigned long long int> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<unsigned long long int> left, Expr<unsigned long long int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned long long int,unsigned long long int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'int' expresion. Supports standard math and comparison operators (including modulo and shifts).
    /// </summary>
    template<> public ref class Expr<int> : ExpressionWrapper<int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return int::typeid; } }
    
		public:
			Expr<int>() { }
      Expr<int>(int val) { _value = gcnew Literal<int>(val); }
      Expr<int>(Expression<int>^ value) { _value = value; }
			Expr<int>(Expr<int>% b)	{ _value = b._value; }
			operator Expression<int>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<int>(Expression<int>^ value)  { return Expr<int>(value); }
			static operator Expr<int>(int b) { return Expr<int>(b); }
      
      
      operator Expr<long long int>() { return Expr<long long int>::Convert(_value); }
      operator Expr<unsigned long long int>() { return Expr<unsigned long long int>::Convert(_value); }

    public:
    static Expr<int> Typed(GenericExpression^ value) 
      { 
        return Expr<int>(gcnew TypedExpression<int>(value));
      }

      static Expr<int> Convert(GenericExpression^ value) 
      { 
        return Expr<int>(gcnew ConvertExpression<int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<int> operator+(Expr<int> left, Expr<int> right)
      {
        return Expr<int>(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<int> operator*(Expr<int> left, Expr<int> right)
      {
        return Expr<int>(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<int> operator/(Expr<int> left, Expr<int> right)
      {
        return Expr<int>(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<int> operator-(Expr<int> left, Expr<int> right)
      {
        return Expr<int>(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<bool> operator==(Expr<int> left, Expr<int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<int> left, Expr<int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<bool> operator<(Expr<int> left, Expr<int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<bool> operator>(Expr<int> left, Expr<int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<int> left, Expr<int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<int> left, Expr<int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,int,int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

      /// <summary>
      /// Shift left operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<int> operator<<(Expr<int> left, Expr<int> right)
      {
        return Expr<int>(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::LShift));
      }

      /// <summary>
      /// Shift right operator for tuple of Expr<int> types.
      /// </summary>
      static Expr<int> operator>>(Expr<int> left, Expr<int> right)
      {
        return Expr<int>(gcnew BinaryExpression<int,int,int>
          (left, right, System::Expressions::ExpressionType::RShift));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'unsigned int' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<unsigned int> : ExpressionWrapper<unsigned int>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned int::typeid; } }
    
		public:
			Expr<unsigned int>() { }
      Expr<unsigned int>(unsigned int val) { _value = gcnew Literal<unsigned int>(val); }
      Expr<unsigned int>(Expression<unsigned int>^ value) { _value = value; }
			Expr<unsigned int>(Expr<unsigned int>% b)	{ _value = b._value; }
			operator Expression<unsigned int>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<unsigned int>(Expression<unsigned int>^ value)  { return Expr<unsigned int>(value); }
			static operator Expr<unsigned int>(unsigned int b) { return Expr<unsigned int>(b); }
      
      
      operator Expr<long long int>() { return Expr<long long int>::Convert(_value); }
      operator Expr<unsigned long long int>() { return Expr<unsigned long long int>::Convert(_value); }

    public:
    static Expr<unsigned int> Typed(GenericExpression^ value) 
      { 
        return Expr<unsigned int>(gcnew TypedExpression<unsigned int>(value));
      }

      static Expr<unsigned int> Convert(GenericExpression^ value) 
      { 
        return Expr<unsigned int>(gcnew ConvertExpression<unsigned int>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<unsigned int> operator+(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<unsigned int>(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<unsigned int> operator*(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<unsigned int>(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<unsigned int> operator/(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<unsigned int>(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<unsigned int> operator-(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<unsigned int>(gcnew BinaryExpression<unsigned int,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<bool> operator==(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<bool> operator<(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<bool> operator>(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<unsigned int> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<unsigned int> left, Expr<unsigned int> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned int,unsigned int>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'short' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<short> : ExpressionWrapper<short>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return short::typeid; } }
    
		public:
			Expr<short>() { }
      Expr<short>(short val) { _value = gcnew Literal<short>(val); }
      Expr<short>(Expression<short>^ value) { _value = value; }
			Expr<short>(Expr<short>% b)	{ _value = b._value; }
			operator Expression<short>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<short>(Expression<short>^ value)  { return Expr<short>(value); }
			static operator Expr<short>(short b) { return Expr<short>(b); }
      
      
      operator Expr<long long int>() { return Expr<long long int>::Convert(_value); }
      operator Expr<unsigned long long int>() { return Expr<unsigned long long int>::Convert(_value); }
      operator Expr<int>() { return Expr<int>::Convert(_value); }
      operator Expr<unsigned int>() { return Expr<unsigned int>::Convert(_value); }

    public:
    static Expr<short> Typed(GenericExpression^ value) 
      { 
        return Expr<short>(gcnew TypedExpression<short>(value));
      }

      static Expr<short> Convert(GenericExpression^ value) 
      { 
        return Expr<short>(gcnew ConvertExpression<short>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<short> operator+(Expr<short> left, Expr<short> right)
      {
        return Expr<short>(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<short> operator*(Expr<short> left, Expr<short> right)
      {
        return Expr<short>(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<short> operator/(Expr<short> left, Expr<short> right)
      {
        return Expr<short>(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<short> operator-(Expr<short> left, Expr<short> right)
      {
        return Expr<short>(gcnew BinaryExpression<short,short,short>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<bool> operator==(Expr<short> left, Expr<short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<short> left, Expr<short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<bool> operator<(Expr<short> left, Expr<short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<bool> operator>(Expr<short> left, Expr<short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<short> left, Expr<short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<short> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<short> left, Expr<short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,short,short>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'unsigned short' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<unsigned short> : ExpressionWrapper<unsigned short>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned short::typeid; } }
    
		public:
			Expr<unsigned short>() { }
      Expr<unsigned short>(unsigned short val) { _value = gcnew Literal<unsigned short>(val); }
      Expr<unsigned short>(Expression<unsigned short>^ value) { _value = value; }
			Expr<unsigned short>(Expr<unsigned short>% b)	{ _value = b._value; }
			operator Expression<unsigned short>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<unsigned short>(Expression<unsigned short>^ value)  { return Expr<unsigned short>(value); }
			static operator Expr<unsigned short>(unsigned short b) { return Expr<unsigned short>(b); }
      
      
      operator Expr<long long int>() { return Expr<long long int>::Convert(_value); }
      operator Expr<unsigned long long int>() { return Expr<unsigned long long int>::Convert(_value); }
      operator Expr<int>() { return Expr<int>::Convert(_value); }
      operator Expr<unsigned int>() { return Expr<unsigned int>::Convert(_value); }

    public:
    static Expr<unsigned short> Typed(GenericExpression^ value) 
      { 
        return Expr<unsigned short>(gcnew TypedExpression<unsigned short>(value));
      }

      static Expr<unsigned short> Convert(GenericExpression^ value) 
      { 
        return Expr<unsigned short>(gcnew ConvertExpression<unsigned short>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<unsigned short> operator+(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<unsigned short>(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<unsigned short> operator*(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<unsigned short>(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<unsigned short> operator/(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<unsigned short>(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<unsigned short> operator-(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<unsigned short>(gcnew BinaryExpression<unsigned short,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<bool> operator==(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<bool> operator<(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<bool> operator>(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<unsigned short> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<unsigned short> left, Expr<unsigned short> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned short,unsigned short>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'unsigned char' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<unsigned char> : ExpressionWrapper<unsigned char>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return unsigned char::typeid; } }
    
		public:
			Expr<unsigned char>() { }
      Expr<unsigned char>(unsigned char val) { _value = gcnew Literal<unsigned char>(val); }
      Expr<unsigned char>(Expression<unsigned char>^ value) { _value = value; }
			Expr<unsigned char>(Expr<unsigned char>% b)	{ _value = b._value; }
			operator Expression<unsigned char>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<unsigned char>(Expression<unsigned char>^ value)  { return Expr<unsigned char>(value); }
			static operator Expr<unsigned char>(unsigned char b) { return Expr<unsigned char>(b); }
      
      
      operator Expr<long long int>() { return Expr<long long int>::Convert(_value); }
      operator Expr<unsigned long long int>() { return Expr<unsigned long long int>::Convert(_value); }
      operator Expr<int>() { return Expr<int>::Convert(_value); }
      operator Expr<unsigned int>() { return Expr<unsigned int>::Convert(_value); }
      operator Expr<short>() { return Expr<short>::Convert(_value); }
      operator Expr<unsigned short>() { return Expr<unsigned short>::Convert(_value); }

    public:
    static Expr<unsigned char> Typed(GenericExpression^ value) 
      { 
        return Expr<unsigned char>(gcnew TypedExpression<unsigned char>(value));
      }

      static Expr<unsigned char> Convert(GenericExpression^ value) 
      { 
        return Expr<unsigned char>(gcnew ConvertExpression<unsigned char>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<unsigned char> operator+(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<unsigned char>(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<unsigned char> operator*(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<unsigned char>(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<unsigned char> operator/(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<unsigned char>(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<unsigned char> operator-(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<unsigned char>(gcnew BinaryExpression<unsigned char,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<bool> operator==(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<bool> operator<(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<bool> operator>(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<unsigned char> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<unsigned char> left, Expr<unsigned char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,unsigned char,unsigned char>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'signed char' expresion. Supports standard math and comparison operators (including modulo).
    /// </summary>
    template<> public ref class Expr<signed char> : ExpressionWrapper<signed char>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return signed char::typeid; } }
    
		public:
			Expr<signed char>() { }
      Expr<signed char>(signed char val) { _value = gcnew Literal<signed char>(val); }
      Expr<signed char>(Expression<signed char>^ value) { _value = value; }
			Expr<signed char>(Expr<signed char>% b)	{ _value = b._value; }
			operator Expression<signed char>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<signed char>(Expression<signed char>^ value)  { return Expr<signed char>(value); }
			static operator Expr<signed char>(signed char b) { return Expr<signed char>(b); }
      
      
      operator Expr<long long int>() { return Expr<long long int>::Convert(_value); }
      operator Expr<unsigned long long int>() { return Expr<unsigned long long int>::Convert(_value); }
      operator Expr<int>() { return Expr<int>::Convert(_value); }
      operator Expr<unsigned int>() { return Expr<unsigned int>::Convert(_value); }
      operator Expr<short>() { return Expr<short>::Convert(_value); }
      operator Expr<unsigned short>() { return Expr<unsigned short>::Convert(_value); }

    public:
    static Expr<signed char> Typed(GenericExpression^ value) 
      { 
        return Expr<signed char>(gcnew TypedExpression<signed char>(value));
      }

      static Expr<signed char> Convert(GenericExpression^ value) 
      { 
        return Expr<signed char>(gcnew ConvertExpression<signed char>(value));
      }

    public:
      
      /// <summary>
      /// Addition operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<signed char> operator+(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<signed char>(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// Multiplication operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<signed char> operator*(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<signed char>(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Multiply));
      }

      /// <summary>
      /// Division operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<signed char> operator/(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<signed char>(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Divide));
      }

      /// <summary>
      /// Subtraction operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<signed char> operator-(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<signed char>(gcnew BinaryExpression<signed char,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::Subtract));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<bool> operator==(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Less than operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<bool> operator<(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::LT));
      }

      /// <summary>
      /// Greather than operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<bool> operator>(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::GT));
      }

      /// <summary>
      /// Less or equals operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<bool> operator<=(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::LE));
      }

      /// <summary>
      /// Greather or equals than operator for tuple of Expr<signed char> types.
      /// </summary>
      static Expr<bool> operator>=(Expr<signed char> left, Expr<signed char> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,signed char,signed char>
          (left, right, System::Expressions::ExpressionType::GE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'wchar_t' expresion. Supports comparison operators.
    /// </summary>
    template<> public ref class Expr<wchar_t> : ExpressionWrapper<wchar_t>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return wchar_t::typeid; } }
    
		public:
			Expr<wchar_t>() { }
      Expr<wchar_t>(wchar_t val) { _value = gcnew Literal<wchar_t>(val); }
      Expr<wchar_t>(Expression<wchar_t>^ value) { _value = value; }
			Expr<wchar_t>(Expr<wchar_t>% b)	{ _value = b._value; }
			operator Expression<wchar_t>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<wchar_t>(Expression<wchar_t>^ value)  { return Expr<wchar_t>(value); }
			static operator Expr<wchar_t>(wchar_t b) { return Expr<wchar_t>(b); }
      
      

    public:
    static Expr<wchar_t> Typed(GenericExpression^ value) 
      { 
        return Expr<wchar_t>(gcnew TypedExpression<wchar_t>(value));
      }

      static Expr<wchar_t> Convert(GenericExpression^ value) 
      { 
        return Expr<wchar_t>(gcnew ConvertExpression<wchar_t>(value));
      }

    public:
      
      /// <summary>
      /// Test values for equality.
      /// </summary>
      static Expr<bool> operator==(Expr<wchar_t> left, Expr<wchar_t> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,wchar_t,wchar_t>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Test values for inequality.
      /// </summary>
      static Expr<bool> operator!=(Expr<wchar_t> left, Expr<wchar_t> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,wchar_t,wchar_t>
          (left, right, System::Expressions::ExpressionType::NE));
      }

  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'String^' expresion. Support standard string operators and methods.
    /// </summary>
    template<> public ref class Expr<String^> : ExpressionWrapper<String^>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return String::typeid; } }
    
		public:
			Expr<String^>() { }
      Expr<String^>(String^ val) { _value = gcnew Literal<String^>(val); }
      Expr<String^>(Expression<String^>^ value) { _value = value; }
			Expr<String^>(Expr<String^>% b)	{ _value = b._value; }
			operator Expression<String^>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<String^>(Expression<String^>^ value)  { return Expr<String^>(value); }
			static operator Expr<String^>(String^ b) { return Expr<String^>(b); }
      
      

    public:
    static Expr<String^> Typed(GenericExpression^ value) 
      { 
        return Expr<String^>(gcnew TypedExpression<String^>(value));
      }

      static Expr<String^> Convert(GenericExpression^ value) 
      { 
        return Expr<String^>(gcnew ConvertExpression<String^>(value));
      }

    public:
      
      /// <summary>
      /// Operator for string concatenation.
      /// </summary>
      static Expr<String^> operator+(Expr<String^> left, Expr<String^> right)
      {
        return Expr<String^>(gcnew BinaryExpression<String^,String^,String^>
          (left, right, System::Expressions::ExpressionType::Add));
      }

      /// <summary>
      /// comparison operator for tuple of Expr<String^> types.
      /// </summary>
      static Expr<bool> operator==(Expr<String^> left, Expr<String^> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,String^,String^>
          (left, right, System::Expressions::ExpressionType::EQ));
      }

      /// <summary>
      /// Inequallity operator for tuple of Expr<String^> types.
      /// </summary>
      static Expr<bool> operator!=(Expr<String^> left, Expr<String^> right)
      {
        return Expr<bool>(gcnew BinaryExpression<bool,String^,String^>
          (left, right, System::Expressions::ExpressionType::NE));
      }

  
    public:
      
    private:
    	static MethodInfo^ __Substring_Expr_int_;
    	static property MethodInfo^ _Substring_Expr_int_ { 
        MethodInfo^ get() { if (__Substring_Expr_int_ == nullptr) 
          __Substring_Expr_int_ = (String::typeid)->GetMethod("Substring", gcnew array<Type^>{ Expr<int>::WrappedType }); return __Substring_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Retrieves a substring from this instance.
      /// </summary>
      Expr<String^> Substring(Expr<int> startIndex)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Substring_Expr_int_, this, gcnew array<GenericExpression^>{startIndex}));
      }

    private:
    	static MethodInfo^ __Substring_Expr_int__Expr_int_;
    	static property MethodInfo^ _Substring_Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__Substring_Expr_int__Expr_int_ == nullptr) 
          __Substring_Expr_int__Expr_int_ = (String::typeid)->GetMethod("Substring", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<int>::WrappedType }); return __Substring_Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Retrieves a substring from this instance.
      /// </summary>
      Expr<String^> Substring(Expr<int> startIndex, Expr<int> length)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Substring_Expr_int__Expr_int_, this, gcnew array<GenericExpression^>{startIndex, length}));
      }

    private:
    	static MethodInfo^ __Contains_Expr_String__;
    	static property MethodInfo^ _Contains_Expr_String__ { 
        MethodInfo^ get() { if (__Contains_Expr_String__ == nullptr) 
          __Contains_Expr_String__ = (String::typeid)->GetMethod("Contains", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __Contains_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating whether the specified String object occurs within this string.
      /// </summary>
      Expr<bool> Contains(Expr<String^> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_Contains_Expr_String__, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __StartsWith_Expr_String__;
    	static property MethodInfo^ _StartsWith_Expr_String__ { 
        MethodInfo^ get() { if (__StartsWith_Expr_String__ == nullptr) 
          __StartsWith_Expr_String__ = (String::typeid)->GetMethod("StartsWith", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __StartsWith_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Determines whether the beginning of an instance of String matches a specified string.
      /// </summary>
      Expr<bool> StartsWith(Expr<String^> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_StartsWith_Expr_String__, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __EndsWith_Expr_String__;
    	static property MethodInfo^ _EndsWith_Expr_String__ { 
        MethodInfo^ get() { if (__EndsWith_Expr_String__ == nullptr) 
          __EndsWith_Expr_String__ = (String::typeid)->GetMethod("EndsWith", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __EndsWith_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Determines whether the end of an instance of String matches a specified string.
      /// </summary>
      Expr<bool> EndsWith(Expr<String^> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_EndsWith_Expr_String__, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __IndexOf_Expr_wchar_t_;
    	static property MethodInfo^ _IndexOf_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__IndexOf_Expr_wchar_t_ == nullptr) 
          __IndexOf_Expr_wchar_t_ = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __IndexOf_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      Expr<int> IndexOf(Expr<wchar_t> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_IndexOf_Expr_wchar_t_, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __IndexOf_Expr_String__;
    	static property MethodInfo^ _IndexOf_Expr_String__ { 
        MethodInfo^ get() { if (__IndexOf_Expr_String__ == nullptr) 
          __IndexOf_Expr_String__ = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __IndexOf_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      Expr<int> IndexOf(Expr<String^> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_IndexOf_Expr_String__, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __IndexOf_Expr_wchar_t__Expr_int_;
    	static property MethodInfo^ _IndexOf_Expr_wchar_t__Expr_int_ { 
        MethodInfo^ get() { if (__IndexOf_Expr_wchar_t__Expr_int_ == nullptr) 
          __IndexOf_Expr_wchar_t__Expr_int_ = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ Expr<wchar_t>::WrappedType, Expr<int>::WrappedType }); return __IndexOf_Expr_wchar_t__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      Expr<int> IndexOf(Expr<wchar_t> value, Expr<int> startIndex)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_IndexOf_Expr_wchar_t__Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __IndexOf_Expr_String___Expr_int_;
    	static property MethodInfo^ _IndexOf_Expr_String___Expr_int_ { 
        MethodInfo^ get() { if (__IndexOf_Expr_String___Expr_int_ == nullptr) 
          __IndexOf_Expr_String___Expr_int_ = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ Expr<String^>::WrappedType, Expr<int>::WrappedType }); return __IndexOf_Expr_String___Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      Expr<int> IndexOf(Expr<String^> value, Expr<int> startIndex)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_IndexOf_Expr_String___Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __IndexOf_Expr_wchar_t__Expr_int__Expr_int_;
    	static property MethodInfo^ _IndexOf_Expr_wchar_t__Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__IndexOf_Expr_wchar_t__Expr_int__Expr_int_ == nullptr) 
          __IndexOf_Expr_wchar_t__Expr_int__Expr_int_ = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ Expr<wchar_t>::WrappedType, Expr<int>::WrappedType, Expr<int>::WrappedType }); return __IndexOf_Expr_wchar_t__Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      Expr<int> IndexOf(Expr<wchar_t> value, Expr<int> startIndex, Expr<int> count)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_IndexOf_Expr_wchar_t__Expr_int__Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __IndexOf_Expr_String___Expr_int__Expr_int_;
    	static property MethodInfo^ _IndexOf_Expr_String___Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__IndexOf_Expr_String___Expr_int__Expr_int_ == nullptr) 
          __IndexOf_Expr_String___Expr_int__Expr_int_ = (String::typeid)->GetMethod("IndexOf", gcnew array<Type^>{ Expr<String^>::WrappedType, Expr<int>::WrappedType, Expr<int>::WrappedType }); return __IndexOf_Expr_String___Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index of the first occurrence of a String, or one or more characters, within this string.
      /// </summary>
      Expr<int> IndexOf(Expr<String^> value, Expr<int> startIndex, Expr<int> count)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_IndexOf_Expr_String___Expr_int__Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_Expr_wchar_t_;
    	static property MethodInfo^ _LastIndexOf_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__LastIndexOf_Expr_wchar_t_ == nullptr) 
          __LastIndexOf_Expr_wchar_t_ = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __LastIndexOf_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      Expr<int> LastIndexOf(Expr<wchar_t> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_Expr_wchar_t_, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_Expr_String__;
    	static property MethodInfo^ _LastIndexOf_Expr_String__ { 
        MethodInfo^ get() { if (__LastIndexOf_Expr_String__ == nullptr) 
          __LastIndexOf_Expr_String__ = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __LastIndexOf_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      Expr<int> LastIndexOf(Expr<String^> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_Expr_String__, this, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_Expr_wchar_t__Expr_int_;
    	static property MethodInfo^ _LastIndexOf_Expr_wchar_t__Expr_int_ { 
        MethodInfo^ get() { if (__LastIndexOf_Expr_wchar_t__Expr_int_ == nullptr) 
          __LastIndexOf_Expr_wchar_t__Expr_int_ = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ Expr<wchar_t>::WrappedType, Expr<int>::WrappedType }); return __LastIndexOf_Expr_wchar_t__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      Expr<int> LastIndexOf(Expr<wchar_t> value, Expr<int> startIndex)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_Expr_wchar_t__Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_Expr_String___Expr_int_;
    	static property MethodInfo^ _LastIndexOf_Expr_String___Expr_int_ { 
        MethodInfo^ get() { if (__LastIndexOf_Expr_String___Expr_int_ == nullptr) 
          __LastIndexOf_Expr_String___Expr_int_ = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ Expr<String^>::WrappedType, Expr<int>::WrappedType }); return __LastIndexOf_Expr_String___Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      Expr<int> LastIndexOf(Expr<String^> value, Expr<int> startIndex)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_Expr_String___Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_Expr_wchar_t__Expr_int__Expr_int_;
    	static property MethodInfo^ _LastIndexOf_Expr_wchar_t__Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__LastIndexOf_Expr_wchar_t__Expr_int__Expr_int_ == nullptr) 
          __LastIndexOf_Expr_wchar_t__Expr_int__Expr_int_ = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ Expr<wchar_t>::WrappedType, Expr<int>::WrappedType, Expr<int>::WrappedType }); return __LastIndexOf_Expr_wchar_t__Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      Expr<int> LastIndexOf(Expr<wchar_t> value, Expr<int> startIndex, Expr<int> count)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_Expr_wchar_t__Expr_int__Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __LastIndexOf_Expr_String___Expr_int__Expr_int_;
    	static property MethodInfo^ _LastIndexOf_Expr_String___Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__LastIndexOf_Expr_String___Expr_int__Expr_int_ == nullptr) 
          __LastIndexOf_Expr_String___Expr_int__Expr_int_ = (String::typeid)->GetMethod("LastIndexOf", gcnew array<Type^>{ Expr<String^>::WrappedType, Expr<int>::WrappedType, Expr<int>::WrappedType }); return __LastIndexOf_Expr_String___Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Reports the index position of the last occurrence of a specified Unicode character or String within this instance.
      /// </summary>
      Expr<int> LastIndexOf(Expr<String^> value, Expr<int> startIndex, Expr<int> count)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_LastIndexOf_Expr_String___Expr_int__Expr_int_, this, gcnew array<GenericExpression^>{value, startIndex, count}));
      }

    private:
    	static MethodInfo^ __Insert_Expr_int__Expr_String__;
    	static property MethodInfo^ _Insert_Expr_int__Expr_String__ { 
        MethodInfo^ get() { if (__Insert_Expr_int__Expr_String__ == nullptr) 
          __Insert_Expr_int__Expr_String__ = (String::typeid)->GetMethod("Insert", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<String^>::WrappedType }); return __Insert_Expr_int__Expr_String__; 
        } }
    public:
      /// <summary>
      /// Inserts a specified instance of String at a specified index position in this instance.
      /// </summary>
      Expr<String^> Insert(Expr<int> startIndex, Expr<String^> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Insert_Expr_int__Expr_String__, this, gcnew array<GenericExpression^>{startIndex, value}));
      }

    private:
    	static MethodInfo^ __Remove_Expr_int_;
    	static property MethodInfo^ _Remove_Expr_int_ { 
        MethodInfo^ get() { if (__Remove_Expr_int_ == nullptr) 
          __Remove_Expr_int_ = (String::typeid)->GetMethod("Remove", gcnew array<Type^>{ Expr<int>::WrappedType }); return __Remove_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Deletes a specified number of characters from this instance.
      /// </summary>
      Expr<String^> Remove(Expr<int> startIndex)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Remove_Expr_int_, this, gcnew array<GenericExpression^>{startIndex}));
      }

    private:
    	static MethodInfo^ __Remove_Expr_int__Expr_int_;
    	static property MethodInfo^ _Remove_Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__Remove_Expr_int__Expr_int_ == nullptr) 
          __Remove_Expr_int__Expr_int_ = (String::typeid)->GetMethod("Remove", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<int>::WrappedType }); return __Remove_Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Deletes a specified number of characters from this instance.
      /// </summary>
      Expr<String^> Remove(Expr<int> startIndex, Expr<int> count)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Remove_Expr_int__Expr_int_, this, gcnew array<GenericExpression^>{startIndex, count}));
      }

    private:
    	static MethodInfo^ __Replace_Expr_wchar_t__Expr_wchar_t_;
    	static property MethodInfo^ _Replace_Expr_wchar_t__Expr_wchar_t_ { 
        MethodInfo^ get() { if (__Replace_Expr_wchar_t__Expr_wchar_t_ == nullptr) 
          __Replace_Expr_wchar_t__Expr_wchar_t_ = (String::typeid)->GetMethod("Replace", gcnew array<Type^>{ Expr<wchar_t>::WrappedType, Expr<wchar_t>::WrappedType }); return __Replace_Expr_wchar_t__Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Replaces all occurrences of a specified Unicode character or String in this instance, with another specified Unicode character or String.
      /// </summary>
      Expr<String^> Replace(Expr<wchar_t> oldChar, Expr<wchar_t> newChar)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Replace_Expr_wchar_t__Expr_wchar_t_, this, gcnew array<GenericExpression^>{oldChar, newChar}));
      }

    private:
    	static MethodInfo^ __Replace_Expr_String___Expr_String__;
    	static property MethodInfo^ _Replace_Expr_String___Expr_String__ { 
        MethodInfo^ get() { if (__Replace_Expr_String___Expr_String__ == nullptr) 
          __Replace_Expr_String___Expr_String__ = (String::typeid)->GetMethod("Replace", gcnew array<Type^>{ Expr<String^>::WrappedType, Expr<String^>::WrappedType }); return __Replace_Expr_String___Expr_String__; 
        } }
    public:
      /// <summary>
      /// Replaces all occurrences of a specified Unicode character or String in this instance, with another specified Unicode character or String.
      /// </summary>
      Expr<String^> Replace(Expr<String^> oldValue, Expr<String^> newValue)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Replace_Expr_String___Expr_String__, this, gcnew array<GenericExpression^>{oldValue, newValue}));
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
      Expr<String^> Trim()
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
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
      Expr<String^> ToLower()
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
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
      Expr<String^> ToUpper()
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToUpper, this, gcnew array<GenericExpression^>{}));
      }

    private:
    	static MethodInfo^ __PadRight_Expr_int_;
    	static property MethodInfo^ _PadRight_Expr_int_ { 
        MethodInfo^ get() { if (__PadRight_Expr_int_ == nullptr) 
          __PadRight_Expr_int_ = (String::typeid)->GetMethod("PadRight", gcnew array<Type^>{ Expr<int>::WrappedType }); return __PadRight_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Left-aligns the characters in this string, padding on the right with spaces or a specified Unicode character, for a specified total length.
      /// </summary>
      Expr<String^> PadRight(Expr<int> totalWidth)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_PadRight_Expr_int_, this, gcnew array<GenericExpression^>{totalWidth}));
      }

    private:
    	static MethodInfo^ __PadRight_Expr_int__Expr_wchar_t_;
    	static property MethodInfo^ _PadRight_Expr_int__Expr_wchar_t_ { 
        MethodInfo^ get() { if (__PadRight_Expr_int__Expr_wchar_t_ == nullptr) 
          __PadRight_Expr_int__Expr_wchar_t_ = (String::typeid)->GetMethod("PadRight", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<wchar_t>::WrappedType }); return __PadRight_Expr_int__Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Left-aligns the characters in this string, padding on the right with spaces or a specified Unicode character, for a specified total length.
      /// </summary>
      Expr<String^> PadRight(Expr<int> totalWidth, Expr<wchar_t> paddingChar)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_PadRight_Expr_int__Expr_wchar_t_, this, gcnew array<GenericExpression^>{totalWidth, paddingChar}));
      }

    private:
    	static MethodInfo^ __PadLeft_Expr_int_;
    	static property MethodInfo^ _PadLeft_Expr_int_ { 
        MethodInfo^ get() { if (__PadLeft_Expr_int_ == nullptr) 
          __PadLeft_Expr_int_ = (String::typeid)->GetMethod("PadLeft", gcnew array<Type^>{ Expr<int>::WrappedType }); return __PadLeft_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Right-aligns the characters in this instance, padding on the left with spaces or a specified Unicode character for a specified total length.
      /// </summary>
      Expr<String^> PadLeft(Expr<int> totalWidth)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_PadLeft_Expr_int_, this, gcnew array<GenericExpression^>{totalWidth}));
      }

    private:
    	static MethodInfo^ __PadLeft_Expr_int__Expr_wchar_t_;
    	static property MethodInfo^ _PadLeft_Expr_int__Expr_wchar_t_ { 
        MethodInfo^ get() { if (__PadLeft_Expr_int__Expr_wchar_t_ == nullptr) 
          __PadLeft_Expr_int__Expr_wchar_t_ = (String::typeid)->GetMethod("PadLeft", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<wchar_t>::WrappedType }); return __PadLeft_Expr_int__Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Right-aligns the characters in this instance, padding on the left with spaces or a specified Unicode character for a specified total length.
      /// </summary>
      Expr<String^> PadLeft(Expr<int> totalWidth, Expr<wchar_t> paddingChar)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_PadLeft_Expr_int__Expr_wchar_t_, this, gcnew array<GenericExpression^>{totalWidth, paddingChar}));
      }

    private:
    	static MethodInfo^ __Equals_Expr_String__;
    	static property MethodInfo^ _Equals_Expr_String__ { 
        MethodInfo^ get() { if (__Equals_Expr_String__ == nullptr) 
          __Equals_Expr_String__ = (String::typeid)->GetMethod("Equals", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __Equals_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Determines whether two String objects have the same value.
      /// </summary>
      Expr<bool> Equals(Expr<String^> str)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_Equals_Expr_String__, this, gcnew array<GenericExpression^>{str}));
      }

    private:
    	static MethodInfo^ __CompareTo_Expr_String__;
    	static property MethodInfo^ _CompareTo_Expr_String__ { 
        MethodInfo^ get() { if (__CompareTo_Expr_String__ == nullptr) 
          __CompareTo_Expr_String__ = (String::typeid)->GetMethod("CompareTo", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __CompareTo_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Compares this instance with a specified object or String and returns an indication of their relative values.
      /// </summary>
      Expr<int> CompareTo(Expr<String^> str)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_CompareTo_Expr_String__, this, gcnew array<GenericExpression^>{str}));
      }

    private:
    	static MethodInfo^ __Compare_Expr_String___Expr_String__;
    	static property MethodInfo^ _Compare_Expr_String___Expr_String__ { 
        MethodInfo^ get() { if (__Compare_Expr_String___Expr_String__ == nullptr) 
          __Compare_Expr_String___Expr_String__ = (String::typeid)->GetMethod("Compare", gcnew array<Type^>{ Expr<String^>::WrappedType, Expr<String^>::WrappedType }); return __Compare_Expr_String___Expr_String__; 
        } }
    public:
      /// <summary>
      /// Compares two specified String objects.
      /// </summary>
      static Expr<int> Compare(Expr<String^> strA, Expr<String^> strB)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Compare_Expr_String___Expr_String__, nullptr, gcnew array<GenericExpression^>{strA, strB}));
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
      static Expr<String^> Concat(... cli::array<Expression<String^>^>^ strs)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_Concat_cli__array_Expression_String_____, nullptr, gcnew array<GenericExpression^>{ gcnew ParamsExpression<String^>(strs) }));
      }

    };
    

    /// <summary>
    /// Template specialization for the 'DateTime' expresion.
    /// </summary>
    template<> public ref class Expr<DateTime> : ExpressionWrapper<DateTime>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return DateTime::typeid; } }
    
		public:
			Expr<DateTime>() { }
      Expr<DateTime>(DateTime val) { _value = gcnew Literal<DateTime>(val); }
      Expr<DateTime>(Expression<DateTime>^ value) { _value = value; }
			Expr<DateTime>(Expr<DateTime>% b)	{ _value = b._value; }
			operator Expression<DateTime>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<DateTime>(Expression<DateTime>^ value)  { return Expr<DateTime>(value); }
			static operator Expr<DateTime>(DateTime b) { return Expr<DateTime>(b); }
      
      

    public:
    static Expr<DateTime> Typed(GenericExpression^ value) 
      { 
        return Expr<DateTime>(gcnew TypedExpression<DateTime>(value));
      }

      static Expr<DateTime> Convert(GenericExpression^ value) 
      { 
        return Expr<DateTime>(gcnew ConvertExpression<DateTime>(value));
      }

    public:
      
  
    public:
      
    };
    

    /// <summary>
    /// Template specialization for the 'Nullable<DateTime>' expresion.
    /// </summary>
    template<> public ref class Expr<Nullable<DateTime>> : ExpressionWrapper<Nullable<DateTime>>
    {
    public:
      static property Type^ WrappedType { Type^ get() { return Nullable<DateTime>::typeid; } }
    
		public:
			Expr<Nullable<DateTime>>() { }
      Expr<Nullable<DateTime>>(Nullable<DateTime> val) { _value = gcnew Literal<Nullable<DateTime>>(val); }
      Expr<Nullable<DateTime>>(Expression<Nullable<DateTime>>^ value) { _value = value; }
			Expr<Nullable<DateTime>>(Expr<Nullable<DateTime>>% b)	{ _value = b._value; }
			operator Expression<Nullable<DateTime>>^() { return _value; }
      operator GenericExpression^() { return _value; }
			static operator Expr<Nullable<DateTime>>(Expression<Nullable<DateTime>>^ value)  { return Expr<Nullable<DateTime>>(value); }
			static operator Expr<Nullable<DateTime>>(Nullable<DateTime> b) { return Expr<Nullable<DateTime>>(b); }
      
      

    public:
    static Expr<Nullable<DateTime>> Typed(GenericExpression^ value) 
      { 
        return Expr<Nullable<DateTime>>(gcnew TypedExpression<Nullable<DateTime>>(value));
      }

      static Expr<Nullable<DateTime>> Convert(GenericExpression^ value) 
      { 
        return Expr<Nullable<DateTime>>(gcnew ConvertExpression<Nullable<DateTime>>(value));
      }

    public:
      
  
    public:
      
    };
    

    /// <summary>
    /// Converts a base data type to another base data type.
    /// </summary>
    template<> public ref class Expr<System::Convert^>
    {
    private:
      Expr<System::Convert^>() { }
      
    public:
      
  
    public:
      
    private:
    	static MethodInfo^ __ToBool_Expr_bool_;
    	static property MethodInfo^ _ToBool_Expr_bool_ { 
        MethodInfo^ get() { if (__ToBool_Expr_bool_ == nullptr) 
          __ToBool_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToBool_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<bool> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_unsigned_char_;
    	static property MethodInfo^ _ToBool_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToBool_Expr_unsigned_char_ == nullptr) 
          __ToBool_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToBool_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<unsigned char> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_wchar_t_;
    	static property MethodInfo^ _ToBool_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToBool_Expr_wchar_t_ == nullptr) 
          __ToBool_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToBool_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<wchar_t> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_DateTime_;
    	static property MethodInfo^ _ToBool_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToBool_Expr_DateTime_ == nullptr) 
          __ToBool_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToBool_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<DateTime> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_Decimal_;
    	static property MethodInfo^ _ToBool_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToBool_Expr_Decimal_ == nullptr) 
          __ToBool_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToBool_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<Decimal> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_Double_;
    	static property MethodInfo^ _ToBool_Expr_Double_ { 
        MethodInfo^ get() { if (__ToBool_Expr_Double_ == nullptr) 
          __ToBool_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToBool_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<Double> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_float_;
    	static property MethodInfo^ _ToBool_Expr_float_ { 
        MethodInfo^ get() { if (__ToBool_Expr_float_ == nullptr) 
          __ToBool_Expr_float_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToBool_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<float> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_short_;
    	static property MethodInfo^ _ToBool_Expr_short_ { 
        MethodInfo^ get() { if (__ToBool_Expr_short_ == nullptr) 
          __ToBool_Expr_short_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToBool_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<short> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_int_;
    	static property MethodInfo^ _ToBool_Expr_int_ { 
        MethodInfo^ get() { if (__ToBool_Expr_int_ == nullptr) 
          __ToBool_Expr_int_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToBool_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<int> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_long_long_int_;
    	static property MethodInfo^ _ToBool_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToBool_Expr_long_long_int_ == nullptr) 
          __ToBool_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToBool_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<long long int> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToBool_Expr_String__;
    	static property MethodInfo^ _ToBool_Expr_String__ { 
        MethodInfo^ get() { if (__ToBool_Expr_String__ == nullptr) 
          __ToBool_Expr_String__ = (System::Convert::typeid)->GetMethod("ToBool", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToBool_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'bool'.
      /// </summary>
      static Expr<bool> ToBool(Expr<String^> value)
  		{
	  		return Expr<bool>(gcnew MethodInvokeExpression<bool>
          (_ToBool_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_bool_;
    	static property MethodInfo^ _ToByte_Expr_bool_ { 
        MethodInfo^ get() { if (__ToByte_Expr_bool_ == nullptr) 
          __ToByte_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToByte_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<bool> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_unsigned_char_;
    	static property MethodInfo^ _ToByte_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToByte_Expr_unsigned_char_ == nullptr) 
          __ToByte_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToByte_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<unsigned char> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_wchar_t_;
    	static property MethodInfo^ _ToByte_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToByte_Expr_wchar_t_ == nullptr) 
          __ToByte_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToByte_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<wchar_t> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_DateTime_;
    	static property MethodInfo^ _ToByte_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToByte_Expr_DateTime_ == nullptr) 
          __ToByte_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToByte_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<DateTime> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_Decimal_;
    	static property MethodInfo^ _ToByte_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToByte_Expr_Decimal_ == nullptr) 
          __ToByte_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToByte_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<Decimal> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_Double_;
    	static property MethodInfo^ _ToByte_Expr_Double_ { 
        MethodInfo^ get() { if (__ToByte_Expr_Double_ == nullptr) 
          __ToByte_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToByte_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<Double> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_float_;
    	static property MethodInfo^ _ToByte_Expr_float_ { 
        MethodInfo^ get() { if (__ToByte_Expr_float_ == nullptr) 
          __ToByte_Expr_float_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToByte_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<float> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_short_;
    	static property MethodInfo^ _ToByte_Expr_short_ { 
        MethodInfo^ get() { if (__ToByte_Expr_short_ == nullptr) 
          __ToByte_Expr_short_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToByte_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<short> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_int_;
    	static property MethodInfo^ _ToByte_Expr_int_ { 
        MethodInfo^ get() { if (__ToByte_Expr_int_ == nullptr) 
          __ToByte_Expr_int_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToByte_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<int> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_long_long_int_;
    	static property MethodInfo^ _ToByte_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToByte_Expr_long_long_int_ == nullptr) 
          __ToByte_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToByte_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<long long int> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToByte_Expr_String__;
    	static property MethodInfo^ _ToByte_Expr_String__ { 
        MethodInfo^ get() { if (__ToByte_Expr_String__ == nullptr) 
          __ToByte_Expr_String__ = (System::Convert::typeid)->GetMethod("ToByte", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToByte_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'unsigned char'.
      /// </summary>
      static Expr<unsigned char> ToByte(Expr<String^> value)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_ToByte_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_bool_;
    	static property MethodInfo^ _ToChar_Expr_bool_ { 
        MethodInfo^ get() { if (__ToChar_Expr_bool_ == nullptr) 
          __ToChar_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToChar_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<bool> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_unsigned_char_;
    	static property MethodInfo^ _ToChar_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToChar_Expr_unsigned_char_ == nullptr) 
          __ToChar_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToChar_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<unsigned char> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_wchar_t_;
    	static property MethodInfo^ _ToChar_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToChar_Expr_wchar_t_ == nullptr) 
          __ToChar_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToChar_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<wchar_t> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_DateTime_;
    	static property MethodInfo^ _ToChar_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToChar_Expr_DateTime_ == nullptr) 
          __ToChar_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToChar_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<DateTime> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_Decimal_;
    	static property MethodInfo^ _ToChar_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToChar_Expr_Decimal_ == nullptr) 
          __ToChar_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToChar_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<Decimal> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_Double_;
    	static property MethodInfo^ _ToChar_Expr_Double_ { 
        MethodInfo^ get() { if (__ToChar_Expr_Double_ == nullptr) 
          __ToChar_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToChar_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<Double> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_float_;
    	static property MethodInfo^ _ToChar_Expr_float_ { 
        MethodInfo^ get() { if (__ToChar_Expr_float_ == nullptr) 
          __ToChar_Expr_float_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToChar_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<float> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_short_;
    	static property MethodInfo^ _ToChar_Expr_short_ { 
        MethodInfo^ get() { if (__ToChar_Expr_short_ == nullptr) 
          __ToChar_Expr_short_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToChar_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<short> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_int_;
    	static property MethodInfo^ _ToChar_Expr_int_ { 
        MethodInfo^ get() { if (__ToChar_Expr_int_ == nullptr) 
          __ToChar_Expr_int_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToChar_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<int> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_long_long_int_;
    	static property MethodInfo^ _ToChar_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToChar_Expr_long_long_int_ == nullptr) 
          __ToChar_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToChar_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<long long int> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToChar_Expr_String__;
    	static property MethodInfo^ _ToChar_Expr_String__ { 
        MethodInfo^ get() { if (__ToChar_Expr_String__ == nullptr) 
          __ToChar_Expr_String__ = (System::Convert::typeid)->GetMethod("ToChar", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToChar_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'wchar_t'.
      /// </summary>
      static Expr<wchar_t> ToChar(Expr<String^> value)
  		{
	  		return Expr<wchar_t>(gcnew MethodInvokeExpression<wchar_t>
          (_ToChar_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_bool_;
    	static property MethodInfo^ _ToDateTime_Expr_bool_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_bool_ == nullptr) 
          __ToDateTime_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToDateTime_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<bool> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_unsigned_char_;
    	static property MethodInfo^ _ToDateTime_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_unsigned_char_ == nullptr) 
          __ToDateTime_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToDateTime_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<unsigned char> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_wchar_t_;
    	static property MethodInfo^ _ToDateTime_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_wchar_t_ == nullptr) 
          __ToDateTime_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToDateTime_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<wchar_t> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_DateTime_;
    	static property MethodInfo^ _ToDateTime_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_DateTime_ == nullptr) 
          __ToDateTime_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToDateTime_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<DateTime> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_Decimal_;
    	static property MethodInfo^ _ToDateTime_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_Decimal_ == nullptr) 
          __ToDateTime_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToDateTime_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<Decimal> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_Double_;
    	static property MethodInfo^ _ToDateTime_Expr_Double_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_Double_ == nullptr) 
          __ToDateTime_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToDateTime_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<Double> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_float_;
    	static property MethodInfo^ _ToDateTime_Expr_float_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_float_ == nullptr) 
          __ToDateTime_Expr_float_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToDateTime_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<float> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_short_;
    	static property MethodInfo^ _ToDateTime_Expr_short_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_short_ == nullptr) 
          __ToDateTime_Expr_short_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToDateTime_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<short> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_int_;
    	static property MethodInfo^ _ToDateTime_Expr_int_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_int_ == nullptr) 
          __ToDateTime_Expr_int_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToDateTime_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<int> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_long_long_int_;
    	static property MethodInfo^ _ToDateTime_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_long_long_int_ == nullptr) 
          __ToDateTime_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToDateTime_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<long long int> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDateTime_Expr_String__;
    	static property MethodInfo^ _ToDateTime_Expr_String__ { 
        MethodInfo^ get() { if (__ToDateTime_Expr_String__ == nullptr) 
          __ToDateTime_Expr_String__ = (System::Convert::typeid)->GetMethod("ToDateTime", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToDateTime_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'DateTime'.
      /// </summary>
      static Expr<DateTime> ToDateTime(Expr<String^> value)
  		{
	  		return Expr<DateTime>(gcnew MethodInvokeExpression<DateTime>
          (_ToDateTime_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_bool_;
    	static property MethodInfo^ _ToDecimal_Expr_bool_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_bool_ == nullptr) 
          __ToDecimal_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToDecimal_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<bool> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_unsigned_char_;
    	static property MethodInfo^ _ToDecimal_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_unsigned_char_ == nullptr) 
          __ToDecimal_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToDecimal_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<unsigned char> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_wchar_t_;
    	static property MethodInfo^ _ToDecimal_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_wchar_t_ == nullptr) 
          __ToDecimal_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToDecimal_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<wchar_t> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_DateTime_;
    	static property MethodInfo^ _ToDecimal_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_DateTime_ == nullptr) 
          __ToDecimal_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToDecimal_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<DateTime> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_Decimal_;
    	static property MethodInfo^ _ToDecimal_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_Decimal_ == nullptr) 
          __ToDecimal_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToDecimal_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<Decimal> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_Double_;
    	static property MethodInfo^ _ToDecimal_Expr_Double_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_Double_ == nullptr) 
          __ToDecimal_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToDecimal_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<Double> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_float_;
    	static property MethodInfo^ _ToDecimal_Expr_float_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_float_ == nullptr) 
          __ToDecimal_Expr_float_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToDecimal_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<float> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_short_;
    	static property MethodInfo^ _ToDecimal_Expr_short_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_short_ == nullptr) 
          __ToDecimal_Expr_short_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToDecimal_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<short> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_int_;
    	static property MethodInfo^ _ToDecimal_Expr_int_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_int_ == nullptr) 
          __ToDecimal_Expr_int_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToDecimal_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<int> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_long_long_int_;
    	static property MethodInfo^ _ToDecimal_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_long_long_int_ == nullptr) 
          __ToDecimal_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToDecimal_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<long long int> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDecimal_Expr_String__;
    	static property MethodInfo^ _ToDecimal_Expr_String__ { 
        MethodInfo^ get() { if (__ToDecimal_Expr_String__ == nullptr) 
          __ToDecimal_Expr_String__ = (System::Convert::typeid)->GetMethod("ToDecimal", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToDecimal_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'Decimal'.
      /// </summary>
      static Expr<Decimal> ToDecimal(Expr<String^> value)
  		{
	  		return Expr<Decimal>(gcnew MethodInvokeExpression<Decimal>
          (_ToDecimal_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_bool_;
    	static property MethodInfo^ _ToDouble_Expr_bool_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_bool_ == nullptr) 
          __ToDouble_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToDouble_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<bool> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_unsigned_char_;
    	static property MethodInfo^ _ToDouble_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_unsigned_char_ == nullptr) 
          __ToDouble_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToDouble_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<unsigned char> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_wchar_t_;
    	static property MethodInfo^ _ToDouble_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_wchar_t_ == nullptr) 
          __ToDouble_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToDouble_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<wchar_t> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_DateTime_;
    	static property MethodInfo^ _ToDouble_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_DateTime_ == nullptr) 
          __ToDouble_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToDouble_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<DateTime> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_Decimal_;
    	static property MethodInfo^ _ToDouble_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_Decimal_ == nullptr) 
          __ToDouble_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToDouble_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<Decimal> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_Double_;
    	static property MethodInfo^ _ToDouble_Expr_Double_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_Double_ == nullptr) 
          __ToDouble_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToDouble_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<Double> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_float_;
    	static property MethodInfo^ _ToDouble_Expr_float_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_float_ == nullptr) 
          __ToDouble_Expr_float_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToDouble_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<float> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_short_;
    	static property MethodInfo^ _ToDouble_Expr_short_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_short_ == nullptr) 
          __ToDouble_Expr_short_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToDouble_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<short> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_int_;
    	static property MethodInfo^ _ToDouble_Expr_int_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_int_ == nullptr) 
          __ToDouble_Expr_int_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToDouble_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<int> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_long_long_int_;
    	static property MethodInfo^ _ToDouble_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToDouble_Expr_long_long_int_ == nullptr) 
          __ToDouble_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToDouble_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<long long int> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToDouble_Expr_String__;
    	static property MethodInfo^ _ToDouble_Expr_String__ { 
        MethodInfo^ get() { if (__ToDouble_Expr_String__ == nullptr) 
          __ToDouble_Expr_String__ = (System::Convert::typeid)->GetMethod("ToDouble", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToDouble_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'double'.
      /// </summary>
      static Expr<double> ToDouble(Expr<String^> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_ToDouble_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_bool_;
    	static property MethodInfo^ _ToSingle_Expr_bool_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_bool_ == nullptr) 
          __ToSingle_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToSingle_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<bool> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_unsigned_char_;
    	static property MethodInfo^ _ToSingle_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_unsigned_char_ == nullptr) 
          __ToSingle_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToSingle_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<unsigned char> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_wchar_t_;
    	static property MethodInfo^ _ToSingle_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_wchar_t_ == nullptr) 
          __ToSingle_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToSingle_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<wchar_t> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_DateTime_;
    	static property MethodInfo^ _ToSingle_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_DateTime_ == nullptr) 
          __ToSingle_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToSingle_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<DateTime> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_Decimal_;
    	static property MethodInfo^ _ToSingle_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_Decimal_ == nullptr) 
          __ToSingle_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToSingle_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<Decimal> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_Double_;
    	static property MethodInfo^ _ToSingle_Expr_Double_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_Double_ == nullptr) 
          __ToSingle_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToSingle_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<Double> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_float_;
    	static property MethodInfo^ _ToSingle_Expr_float_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_float_ == nullptr) 
          __ToSingle_Expr_float_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToSingle_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<float> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_short_;
    	static property MethodInfo^ _ToSingle_Expr_short_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_short_ == nullptr) 
          __ToSingle_Expr_short_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToSingle_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<short> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_int_;
    	static property MethodInfo^ _ToSingle_Expr_int_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_int_ == nullptr) 
          __ToSingle_Expr_int_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToSingle_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<int> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_long_long_int_;
    	static property MethodInfo^ _ToSingle_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToSingle_Expr_long_long_int_ == nullptr) 
          __ToSingle_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToSingle_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<long long int> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToSingle_Expr_String__;
    	static property MethodInfo^ _ToSingle_Expr_String__ { 
        MethodInfo^ get() { if (__ToSingle_Expr_String__ == nullptr) 
          __ToSingle_Expr_String__ = (System::Convert::typeid)->GetMethod("ToSingle", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToSingle_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'float'.
      /// </summary>
      static Expr<float> ToSingle(Expr<String^> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_ToSingle_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_bool_;
    	static property MethodInfo^ _ToInt16_Expr_bool_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_bool_ == nullptr) 
          __ToInt16_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToInt16_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<bool> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_unsigned_char_;
    	static property MethodInfo^ _ToInt16_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_unsigned_char_ == nullptr) 
          __ToInt16_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToInt16_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<unsigned char> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_wchar_t_;
    	static property MethodInfo^ _ToInt16_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_wchar_t_ == nullptr) 
          __ToInt16_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToInt16_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<wchar_t> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_DateTime_;
    	static property MethodInfo^ _ToInt16_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_DateTime_ == nullptr) 
          __ToInt16_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToInt16_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<DateTime> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_Decimal_;
    	static property MethodInfo^ _ToInt16_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_Decimal_ == nullptr) 
          __ToInt16_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToInt16_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<Decimal> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_Double_;
    	static property MethodInfo^ _ToInt16_Expr_Double_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_Double_ == nullptr) 
          __ToInt16_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToInt16_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<Double> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_float_;
    	static property MethodInfo^ _ToInt16_Expr_float_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_float_ == nullptr) 
          __ToInt16_Expr_float_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToInt16_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<float> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_short_;
    	static property MethodInfo^ _ToInt16_Expr_short_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_short_ == nullptr) 
          __ToInt16_Expr_short_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToInt16_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<short> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_int_;
    	static property MethodInfo^ _ToInt16_Expr_int_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_int_ == nullptr) 
          __ToInt16_Expr_int_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToInt16_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<int> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_long_long_int_;
    	static property MethodInfo^ _ToInt16_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToInt16_Expr_long_long_int_ == nullptr) 
          __ToInt16_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToInt16_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<long long int> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt16_Expr_String__;
    	static property MethodInfo^ _ToInt16_Expr_String__ { 
        MethodInfo^ get() { if (__ToInt16_Expr_String__ == nullptr) 
          __ToInt16_Expr_String__ = (System::Convert::typeid)->GetMethod("ToInt16", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToInt16_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'short'.
      /// </summary>
      static Expr<short> ToInt16(Expr<String^> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_ToInt16_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_bool_;
    	static property MethodInfo^ _ToInt32_Expr_bool_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_bool_ == nullptr) 
          __ToInt32_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToInt32_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<bool> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_unsigned_char_;
    	static property MethodInfo^ _ToInt32_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_unsigned_char_ == nullptr) 
          __ToInt32_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToInt32_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<unsigned char> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_wchar_t_;
    	static property MethodInfo^ _ToInt32_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_wchar_t_ == nullptr) 
          __ToInt32_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToInt32_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<wchar_t> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_DateTime_;
    	static property MethodInfo^ _ToInt32_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_DateTime_ == nullptr) 
          __ToInt32_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToInt32_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<DateTime> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_Decimal_;
    	static property MethodInfo^ _ToInt32_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_Decimal_ == nullptr) 
          __ToInt32_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToInt32_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<Decimal> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_Double_;
    	static property MethodInfo^ _ToInt32_Expr_Double_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_Double_ == nullptr) 
          __ToInt32_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToInt32_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<Double> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_float_;
    	static property MethodInfo^ _ToInt32_Expr_float_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_float_ == nullptr) 
          __ToInt32_Expr_float_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToInt32_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<float> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_short_;
    	static property MethodInfo^ _ToInt32_Expr_short_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_short_ == nullptr) 
          __ToInt32_Expr_short_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToInt32_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<short> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_int_;
    	static property MethodInfo^ _ToInt32_Expr_int_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_int_ == nullptr) 
          __ToInt32_Expr_int_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToInt32_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<int> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_long_long_int_;
    	static property MethodInfo^ _ToInt32_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToInt32_Expr_long_long_int_ == nullptr) 
          __ToInt32_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToInt32_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<long long int> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt32_Expr_String__;
    	static property MethodInfo^ _ToInt32_Expr_String__ { 
        MethodInfo^ get() { if (__ToInt32_Expr_String__ == nullptr) 
          __ToInt32_Expr_String__ = (System::Convert::typeid)->GetMethod("ToInt32", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToInt32_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'int'.
      /// </summary>
      static Expr<int> ToInt32(Expr<String^> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_ToInt32_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_bool_;
    	static property MethodInfo^ _ToInt64_Expr_bool_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_bool_ == nullptr) 
          __ToInt64_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToInt64_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<bool> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_unsigned_char_;
    	static property MethodInfo^ _ToInt64_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_unsigned_char_ == nullptr) 
          __ToInt64_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToInt64_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<unsigned char> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_wchar_t_;
    	static property MethodInfo^ _ToInt64_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_wchar_t_ == nullptr) 
          __ToInt64_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToInt64_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<wchar_t> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_DateTime_;
    	static property MethodInfo^ _ToInt64_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_DateTime_ == nullptr) 
          __ToInt64_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToInt64_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<DateTime> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_Decimal_;
    	static property MethodInfo^ _ToInt64_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_Decimal_ == nullptr) 
          __ToInt64_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToInt64_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<Decimal> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_Double_;
    	static property MethodInfo^ _ToInt64_Expr_Double_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_Double_ == nullptr) 
          __ToInt64_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToInt64_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<Double> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_float_;
    	static property MethodInfo^ _ToInt64_Expr_float_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_float_ == nullptr) 
          __ToInt64_Expr_float_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToInt64_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<float> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_short_;
    	static property MethodInfo^ _ToInt64_Expr_short_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_short_ == nullptr) 
          __ToInt64_Expr_short_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToInt64_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<short> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_int_;
    	static property MethodInfo^ _ToInt64_Expr_int_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_int_ == nullptr) 
          __ToInt64_Expr_int_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToInt64_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<int> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_long_long_int_;
    	static property MethodInfo^ _ToInt64_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToInt64_Expr_long_long_int_ == nullptr) 
          __ToInt64_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToInt64_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<long long int> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToInt64_Expr_String__;
    	static property MethodInfo^ _ToInt64_Expr_String__ { 
        MethodInfo^ get() { if (__ToInt64_Expr_String__ == nullptr) 
          __ToInt64_Expr_String__ = (System::Convert::typeid)->GetMethod("ToInt64", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToInt64_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'long long int'.
      /// </summary>
      static Expr<long long int> ToInt64(Expr<String^> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_ToInt64_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_bool_;
    	static property MethodInfo^ _ToString_Expr_bool_ { 
        MethodInfo^ get() { if (__ToString_Expr_bool_ == nullptr) 
          __ToString_Expr_bool_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<bool>::WrappedType }); return __ToString_Expr_bool_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<bool> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_bool_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_unsigned_char_;
    	static property MethodInfo^ _ToString_Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__ToString_Expr_unsigned_char_ == nullptr) 
          __ToString_Expr_unsigned_char_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<unsigned char>::WrappedType }); return __ToString_Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<unsigned char> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_wchar_t_;
    	static property MethodInfo^ _ToString_Expr_wchar_t_ { 
        MethodInfo^ get() { if (__ToString_Expr_wchar_t_ == nullptr) 
          __ToString_Expr_wchar_t_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<wchar_t>::WrappedType }); return __ToString_Expr_wchar_t_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<wchar_t> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_wchar_t_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_DateTime_;
    	static property MethodInfo^ _ToString_Expr_DateTime_ { 
        MethodInfo^ get() { if (__ToString_Expr_DateTime_ == nullptr) 
          __ToString_Expr_DateTime_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<DateTime>::WrappedType }); return __ToString_Expr_DateTime_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<DateTime> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_DateTime_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_Decimal_;
    	static property MethodInfo^ _ToString_Expr_Decimal_ { 
        MethodInfo^ get() { if (__ToString_Expr_Decimal_ == nullptr) 
          __ToString_Expr_Decimal_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<Decimal>::WrappedType }); return __ToString_Expr_Decimal_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<Decimal> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_Double_;
    	static property MethodInfo^ _ToString_Expr_Double_ { 
        MethodInfo^ get() { if (__ToString_Expr_Double_ == nullptr) 
          __ToString_Expr_Double_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<Double>::WrappedType }); return __ToString_Expr_Double_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<Double> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_Double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_float_;
    	static property MethodInfo^ _ToString_Expr_float_ { 
        MethodInfo^ get() { if (__ToString_Expr_float_ == nullptr) 
          __ToString_Expr_float_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<float>::WrappedType }); return __ToString_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<float> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_short_;
    	static property MethodInfo^ _ToString_Expr_short_ { 
        MethodInfo^ get() { if (__ToString_Expr_short_ == nullptr) 
          __ToString_Expr_short_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<short>::WrappedType }); return __ToString_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<short> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_int_;
    	static property MethodInfo^ _ToString_Expr_int_ { 
        MethodInfo^ get() { if (__ToString_Expr_int_ == nullptr) 
          __ToString_Expr_int_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<int>::WrappedType }); return __ToString_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<int> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_long_long_int_;
    	static property MethodInfo^ _ToString_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__ToString_Expr_long_long_int_ == nullptr) 
          __ToString_Expr_long_long_int_ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __ToString_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<long long int> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __ToString_Expr_String__;
    	static property MethodInfo^ _ToString_Expr_String__ { 
        MethodInfo^ get() { if (__ToString_Expr_String__ == nullptr) 
          __ToString_Expr_String__ = (System::Convert::typeid)->GetMethod("ToString", gcnew array<Type^>{ Expr<String^>::WrappedType }); return __ToString_Expr_String__; 
        } }
    public:
      /// <summary>
      /// Overloaded. Converts a specified value to 'String^'.
      /// </summary>
      static Expr<String^> ToString(Expr<String^> value)
  		{
	  		return Expr<String^>(gcnew MethodInvokeExpression<String^>
          (_ToString_Expr_String__, nullptr, gcnew array<GenericExpression^>{value}));
      }

    };
    

    /// <summary>
    /// Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
    /// </summary>
    template<> public ref class Expr<System::Math^>
    {
    private:
      Expr<System::Math^>() { }
      
    public:
      
  
    public:
      
    private:
    	static MethodInfo^ __Abs_Expr_System__Decimal_;
    	static property MethodInfo^ _Abs_Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Abs_Expr_System__Decimal_ == nullptr) 
          __Abs_Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType }); return __Abs_Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static Expr<System::Decimal> Abs(Expr<System::Decimal> value)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Abs_Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_Expr_double_;
    	static property MethodInfo^ _Abs_Expr_double_ { 
        MethodInfo^ get() { if (__Abs_Expr_double_ == nullptr) 
          __Abs_Expr_double_ = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Abs_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static Expr<double> Abs(Expr<double> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Abs_Expr_double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_Expr_float_;
    	static property MethodInfo^ _Abs_Expr_float_ { 
        MethodInfo^ get() { if (__Abs_Expr_float_ == nullptr) 
          __Abs_Expr_float_ = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ Expr<float>::WrappedType }); return __Abs_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static Expr<float> Abs(Expr<float> value)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_Abs_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_Expr_int_;
    	static property MethodInfo^ _Abs_Expr_int_ { 
        MethodInfo^ get() { if (__Abs_Expr_int_ == nullptr) 
          __Abs_Expr_int_ = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ Expr<int>::WrappedType }); return __Abs_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static Expr<int> Abs(Expr<int> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Abs_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_Expr_long_long_int_;
    	static property MethodInfo^ _Abs_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__Abs_Expr_long_long_int_ == nullptr) 
          __Abs_Expr_long_long_int_ = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __Abs_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static Expr<long long int> Abs(Expr<long long int> value)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_Abs_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_Expr_signed_char_;
    	static property MethodInfo^ _Abs_Expr_signed_char_ { 
        MethodInfo^ get() { if (__Abs_Expr_signed_char_ == nullptr) 
          __Abs_Expr_signed_char_ = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ Expr<signed char>::WrappedType }); return __Abs_Expr_signed_char_; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static Expr<signed char> Abs(Expr<signed char> value)
  		{
	  		return Expr<signed char>(gcnew MethodInvokeExpression<signed char>
          (_Abs_Expr_signed_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Abs_Expr_short_;
    	static property MethodInfo^ _Abs_Expr_short_ { 
        MethodInfo^ get() { if (__Abs_Expr_short_ == nullptr) 
          __Abs_Expr_short_ = (System::Math::typeid)->GetMethod("Abs", gcnew array<Type^>{ Expr<short>::WrappedType }); return __Abs_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Returns the absolute value of a specified number.
      /// </summary>
      static Expr<short> Abs(Expr<short> value)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_Abs_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Acos_Expr_double_;
    	static property MethodInfo^ _Acos_Expr_double_ { 
        MethodInfo^ get() { if (__Acos_Expr_double_ == nullptr) 
          __Acos_Expr_double_ = (System::Math::typeid)->GetMethod("Acos", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Acos_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose cosine is the specified number.
      /// </summary>
      static Expr<double> Acos(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Acos_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Asin_Expr_double_;
    	static property MethodInfo^ _Asin_Expr_double_ { 
        MethodInfo^ get() { if (__Asin_Expr_double_ == nullptr) 
          __Asin_Expr_double_ = (System::Math::typeid)->GetMethod("Asin", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Asin_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose sine is the specified number.
      /// </summary>
      static Expr<double> Asin(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Asin_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Atan_Expr_double_;
    	static property MethodInfo^ _Atan_Expr_double_ { 
        MethodInfo^ get() { if (__Atan_Expr_double_ == nullptr) 
          __Atan_Expr_double_ = (System::Math::typeid)->GetMethod("Atan", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Atan_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose tangent is the specified number.
      /// </summary>
      static Expr<double> Atan(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Atan_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Atan2_Expr_double__Expr_double_;
    	static property MethodInfo^ _Atan2_Expr_double__Expr_double_ { 
        MethodInfo^ get() { if (__Atan2_Expr_double__Expr_double_ == nullptr) 
          __Atan2_Expr_double__Expr_double_ = (System::Math::typeid)->GetMethod("Atan2", gcnew array<Type^>{ Expr<double>::WrappedType, Expr<double>::WrappedType }); return __Atan2_Expr_double__Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the angle whose tangent is the quotient of two specified numbers.
      /// </summary>
      static Expr<double> Atan2(Expr<double> y, Expr<double> x)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Atan2_Expr_double__Expr_double_, nullptr, gcnew array<GenericExpression^>{y, x}));
      }

    private:
    	static MethodInfo^ __BigMul_Expr_int__Expr_int_;
    	static property MethodInfo^ _BigMul_Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__BigMul_Expr_int__Expr_int_ == nullptr) 
          __BigMul_Expr_int__Expr_int_ = (System::Math::typeid)->GetMethod("BigMul", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<int>::WrappedType }); return __BigMul_Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Produces the full product of two 32-bit numbers.
      /// </summary>
      static Expr<long long int> BigMul(Expr<int> a, Expr<int> b)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_BigMul_Expr_int__Expr_int_, nullptr, gcnew array<GenericExpression^>{a, b}));
      }

    private:
    	static MethodInfo^ __Ceiling_Expr_System__Decimal_;
    	static property MethodInfo^ _Ceiling_Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Ceiling_Expr_System__Decimal_ == nullptr) 
          __Ceiling_Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Ceiling", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType }); return __Ceiling_Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Returns the smallest number greater than or equal to the specified number.
      /// </summary>
      static Expr<System::Decimal> Ceiling(Expr<System::Decimal> d)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Ceiling_Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Ceiling_Expr_double_;
    	static property MethodInfo^ _Ceiling_Expr_double_ { 
        MethodInfo^ get() { if (__Ceiling_Expr_double_ == nullptr) 
          __Ceiling_Expr_double_ = (System::Math::typeid)->GetMethod("Ceiling", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Ceiling_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the smallest number greater than or equal to the specified number.
      /// </summary>
      static Expr<double> Ceiling(Expr<double> a)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Ceiling_Expr_double_, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Cos_Expr_double_;
    	static property MethodInfo^ _Cos_Expr_double_ { 
        MethodInfo^ get() { if (__Cos_Expr_double_ == nullptr) 
          __Cos_Expr_double_ = (System::Math::typeid)->GetMethod("Cos", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Cos_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the cosine of the specified angle.
      /// </summary>
      static Expr<double> Cos(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Cos_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Cosh_Expr_double_;
    	static property MethodInfo^ _Cosh_Expr_double_ { 
        MethodInfo^ get() { if (__Cosh_Expr_double_ == nullptr) 
          __Cosh_Expr_double_ = (System::Math::typeid)->GetMethod("Cosh", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Cosh_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the hyperbolic cosine of the specified angle.
      /// </summary>
      static Expr<double> Cosh(Expr<double> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Cosh_Expr_double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Exp_Expr_double_;
    	static property MethodInfo^ _Exp_Expr_double_ { 
        MethodInfo^ get() { if (__Exp_Expr_double_ == nullptr) 
          __Exp_Expr_double_ = (System::Math::typeid)->GetMethod("Exp", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Exp_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns e raised to the specified power.
      /// </summary>
      static Expr<double> Exp(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Exp_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Floor_Expr_System__Decimal_;
    	static property MethodInfo^ _Floor_Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Floor_Expr_System__Decimal_ == nullptr) 
          __Floor_Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Floor", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType }); return __Floor_Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Returns the largest number less than or equal to the specified number.
      /// </summary>
      static Expr<System::Decimal> Floor(Expr<System::Decimal> d)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Floor_Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Floor_Expr_double_;
    	static property MethodInfo^ _Floor_Expr_double_ { 
        MethodInfo^ get() { if (__Floor_Expr_double_ == nullptr) 
          __Floor_Expr_double_ = (System::Math::typeid)->GetMethod("Floor", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Floor_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the largest number less than or equal to the specified number.
      /// </summary>
      static Expr<double> Floor(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Floor_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Log_Expr_double_;
    	static property MethodInfo^ _Log_Expr_double_ { 
        MethodInfo^ get() { if (__Log_Expr_double_ == nullptr) 
          __Log_Expr_double_ = (System::Math::typeid)->GetMethod("Log", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Log_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the logarithm of a specified number.
      /// </summary>
      static Expr<double> Log(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Log_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Log_Expr_double__Expr_double_;
    	static property MethodInfo^ _Log_Expr_double__Expr_double_ { 
        MethodInfo^ get() { if (__Log_Expr_double__Expr_double_ == nullptr) 
          __Log_Expr_double__Expr_double_ = (System::Math::typeid)->GetMethod("Log", gcnew array<Type^>{ Expr<double>::WrappedType, Expr<double>::WrappedType }); return __Log_Expr_double__Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the logarithm of a specified number.
      /// </summary>
      static Expr<double> Log(Expr<double> a, Expr<double> newBase)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Log_Expr_double__Expr_double_, nullptr, gcnew array<GenericExpression^>{a, newBase}));
      }

    private:
    	static MethodInfo^ __Log10_Expr_double_;
    	static property MethodInfo^ _Log10_Expr_double_ { 
        MethodInfo^ get() { if (__Log10_Expr_double_ == nullptr) 
          __Log10_Expr_double_ = (System::Math::typeid)->GetMethod("Log10", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Log10_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Log10  Returns the base 10 logarithm of a specified number.
      /// </summary>
      static Expr<double> Log10(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Log10_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Max_Expr_unsigned_char__Expr_unsigned_char_;
    	static property MethodInfo^ _Max_Expr_unsigned_char__Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__Max_Expr_unsigned_char__Expr_unsigned_char_ == nullptr) 
          __Max_Expr_unsigned_char__Expr_unsigned_char_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<unsigned char>::WrappedType, Expr<unsigned char>::WrappedType }); return __Max_Expr_unsigned_char__Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<unsigned char> Max(Expr<unsigned char> val1, Expr<unsigned char> val2)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_Max_Expr_unsigned_char__Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_System__Decimal__Expr_System__Decimal_;
    	static property MethodInfo^ _Max_Expr_System__Decimal__Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Max_Expr_System__Decimal__Expr_System__Decimal_ == nullptr) 
          __Max_Expr_System__Decimal__Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType, Expr<System::Decimal>::WrappedType }); return __Max_Expr_System__Decimal__Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<System::Decimal> Max(Expr<System::Decimal> val1, Expr<System::Decimal> val2)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Max_Expr_System__Decimal__Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_double__Expr_double_;
    	static property MethodInfo^ _Max_Expr_double__Expr_double_ { 
        MethodInfo^ get() { if (__Max_Expr_double__Expr_double_ == nullptr) 
          __Max_Expr_double__Expr_double_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<double>::WrappedType, Expr<double>::WrappedType }); return __Max_Expr_double__Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<double> Max(Expr<double> val1, Expr<double> val2)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Max_Expr_double__Expr_double_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_float__Expr_float_;
    	static property MethodInfo^ _Max_Expr_float__Expr_float_ { 
        MethodInfo^ get() { if (__Max_Expr_float__Expr_float_ == nullptr) 
          __Max_Expr_float__Expr_float_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<float>::WrappedType, Expr<float>::WrappedType }); return __Max_Expr_float__Expr_float_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<float> Max(Expr<float> val1, Expr<float> val2)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_Max_Expr_float__Expr_float_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_int__Expr_int_;
    	static property MethodInfo^ _Max_Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__Max_Expr_int__Expr_int_ == nullptr) 
          __Max_Expr_int__Expr_int_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<int>::WrappedType }); return __Max_Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<int> Max(Expr<int> val1, Expr<int> val2)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Max_Expr_int__Expr_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_long_long_int__Expr_long_long_int_;
    	static property MethodInfo^ _Max_Expr_long_long_int__Expr_long_long_int_ { 
        MethodInfo^ get() { if (__Max_Expr_long_long_int__Expr_long_long_int_ == nullptr) 
          __Max_Expr_long_long_int__Expr_long_long_int_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<long long int>::WrappedType, Expr<long long int>::WrappedType }); return __Max_Expr_long_long_int__Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<long long int> Max(Expr<long long int> val1, Expr<long long int> val2)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_Max_Expr_long_long_int__Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_signed_char__Expr_signed_char_;
    	static property MethodInfo^ _Max_Expr_signed_char__Expr_signed_char_ { 
        MethodInfo^ get() { if (__Max_Expr_signed_char__Expr_signed_char_ == nullptr) 
          __Max_Expr_signed_char__Expr_signed_char_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<signed char>::WrappedType, Expr<signed char>::WrappedType }); return __Max_Expr_signed_char__Expr_signed_char_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<signed char> Max(Expr<signed char> val1, Expr<signed char> val2)
  		{
	  		return Expr<signed char>(gcnew MethodInvokeExpression<signed char>
          (_Max_Expr_signed_char__Expr_signed_char_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_short__Expr_short_;
    	static property MethodInfo^ _Max_Expr_short__Expr_short_ { 
        MethodInfo^ get() { if (__Max_Expr_short__Expr_short_ == nullptr) 
          __Max_Expr_short__Expr_short_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<short>::WrappedType, Expr<short>::WrappedType }); return __Max_Expr_short__Expr_short_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<short> Max(Expr<short> val1, Expr<short> val2)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_Max_Expr_short__Expr_short_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_unsigned_int__Expr_unsigned_int_;
    	static property MethodInfo^ _Max_Expr_unsigned_int__Expr_unsigned_int_ { 
        MethodInfo^ get() { if (__Max_Expr_unsigned_int__Expr_unsigned_int_ == nullptr) 
          __Max_Expr_unsigned_int__Expr_unsigned_int_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<unsigned int>::WrappedType, Expr<unsigned int>::WrappedType }); return __Max_Expr_unsigned_int__Expr_unsigned_int_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<unsigned int> Max(Expr<unsigned int> val1, Expr<unsigned int> val2)
  		{
	  		return Expr<unsigned int>(gcnew MethodInvokeExpression<unsigned int>
          (_Max_Expr_unsigned_int__Expr_unsigned_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_;
    	static property MethodInfo^ _Max_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_ { 
        MethodInfo^ get() { if (__Max_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_ == nullptr) 
          __Max_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<unsigned long long int>::WrappedType, Expr<unsigned long long int>::WrappedType }); return __Max_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<unsigned long long int> Max(Expr<unsigned long long int> val1, Expr<unsigned long long int> val2)
  		{
	  		return Expr<unsigned long long int>(gcnew MethodInvokeExpression<unsigned long long int>
          (_Max_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Max_Expr_unsigned_short__Expr_unsigned_short_;
    	static property MethodInfo^ _Max_Expr_unsigned_short__Expr_unsigned_short_ { 
        MethodInfo^ get() { if (__Max_Expr_unsigned_short__Expr_unsigned_short_ == nullptr) 
          __Max_Expr_unsigned_short__Expr_unsigned_short_ = (System::Math::typeid)->GetMethod("Max", gcnew array<Type^>{ Expr<unsigned short>::WrappedType, Expr<unsigned short>::WrappedType }); return __Max_Expr_unsigned_short__Expr_unsigned_short_; 
        } }
    public:
      /// <summary>
      /// Returns the larger of two specified numbers.
      /// </summary>
      static Expr<unsigned short> Max(Expr<unsigned short> val1, Expr<unsigned short> val2)
  		{
	  		return Expr<unsigned short>(gcnew MethodInvokeExpression<unsigned short>
          (_Max_Expr_unsigned_short__Expr_unsigned_short_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_unsigned_char__Expr_unsigned_char_;
    	static property MethodInfo^ _Min_Expr_unsigned_char__Expr_unsigned_char_ { 
        MethodInfo^ get() { if (__Min_Expr_unsigned_char__Expr_unsigned_char_ == nullptr) 
          __Min_Expr_unsigned_char__Expr_unsigned_char_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<unsigned char>::WrappedType, Expr<unsigned char>::WrappedType }); return __Min_Expr_unsigned_char__Expr_unsigned_char_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<unsigned char> Min(Expr<unsigned char> val1, Expr<unsigned char> val2)
  		{
	  		return Expr<unsigned char>(gcnew MethodInvokeExpression<unsigned char>
          (_Min_Expr_unsigned_char__Expr_unsigned_char_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_System__Decimal__Expr_System__Decimal_;
    	static property MethodInfo^ _Min_Expr_System__Decimal__Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Min_Expr_System__Decimal__Expr_System__Decimal_ == nullptr) 
          __Min_Expr_System__Decimal__Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType, Expr<System::Decimal>::WrappedType }); return __Min_Expr_System__Decimal__Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<System::Decimal> Min(Expr<System::Decimal> val1, Expr<System::Decimal> val2)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Min_Expr_System__Decimal__Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_double__Expr_double_;
    	static property MethodInfo^ _Min_Expr_double__Expr_double_ { 
        MethodInfo^ get() { if (__Min_Expr_double__Expr_double_ == nullptr) 
          __Min_Expr_double__Expr_double_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<double>::WrappedType, Expr<double>::WrappedType }); return __Min_Expr_double__Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<double> Min(Expr<double> val1, Expr<double> val2)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Min_Expr_double__Expr_double_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_float__Expr_float_;
    	static property MethodInfo^ _Min_Expr_float__Expr_float_ { 
        MethodInfo^ get() { if (__Min_Expr_float__Expr_float_ == nullptr) 
          __Min_Expr_float__Expr_float_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<float>::WrappedType, Expr<float>::WrappedType }); return __Min_Expr_float__Expr_float_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<float> Min(Expr<float> val1, Expr<float> val2)
  		{
	  		return Expr<float>(gcnew MethodInvokeExpression<float>
          (_Min_Expr_float__Expr_float_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_int__Expr_int_;
    	static property MethodInfo^ _Min_Expr_int__Expr_int_ { 
        MethodInfo^ get() { if (__Min_Expr_int__Expr_int_ == nullptr) 
          __Min_Expr_int__Expr_int_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<int>::WrappedType, Expr<int>::WrappedType }); return __Min_Expr_int__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<int> Min(Expr<int> val1, Expr<int> val2)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Min_Expr_int__Expr_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_long_long_int__Expr_long_long_int_;
    	static property MethodInfo^ _Min_Expr_long_long_int__Expr_long_long_int_ { 
        MethodInfo^ get() { if (__Min_Expr_long_long_int__Expr_long_long_int_ == nullptr) 
          __Min_Expr_long_long_int__Expr_long_long_int_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<long long int>::WrappedType, Expr<long long int>::WrappedType }); return __Min_Expr_long_long_int__Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<long long int> Min(Expr<long long int> val1, Expr<long long int> val2)
  		{
	  		return Expr<long long int>(gcnew MethodInvokeExpression<long long int>
          (_Min_Expr_long_long_int__Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_signed_char__Expr_signed_char_;
    	static property MethodInfo^ _Min_Expr_signed_char__Expr_signed_char_ { 
        MethodInfo^ get() { if (__Min_Expr_signed_char__Expr_signed_char_ == nullptr) 
          __Min_Expr_signed_char__Expr_signed_char_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<signed char>::WrappedType, Expr<signed char>::WrappedType }); return __Min_Expr_signed_char__Expr_signed_char_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<signed char> Min(Expr<signed char> val1, Expr<signed char> val2)
  		{
	  		return Expr<signed char>(gcnew MethodInvokeExpression<signed char>
          (_Min_Expr_signed_char__Expr_signed_char_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_short__Expr_short_;
    	static property MethodInfo^ _Min_Expr_short__Expr_short_ { 
        MethodInfo^ get() { if (__Min_Expr_short__Expr_short_ == nullptr) 
          __Min_Expr_short__Expr_short_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<short>::WrappedType, Expr<short>::WrappedType }); return __Min_Expr_short__Expr_short_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<short> Min(Expr<short> val1, Expr<short> val2)
  		{
	  		return Expr<short>(gcnew MethodInvokeExpression<short>
          (_Min_Expr_short__Expr_short_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_unsigned_int__Expr_unsigned_int_;
    	static property MethodInfo^ _Min_Expr_unsigned_int__Expr_unsigned_int_ { 
        MethodInfo^ get() { if (__Min_Expr_unsigned_int__Expr_unsigned_int_ == nullptr) 
          __Min_Expr_unsigned_int__Expr_unsigned_int_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<unsigned int>::WrappedType, Expr<unsigned int>::WrappedType }); return __Min_Expr_unsigned_int__Expr_unsigned_int_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<unsigned int> Min(Expr<unsigned int> val1, Expr<unsigned int> val2)
  		{
	  		return Expr<unsigned int>(gcnew MethodInvokeExpression<unsigned int>
          (_Min_Expr_unsigned_int__Expr_unsigned_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_;
    	static property MethodInfo^ _Min_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_ { 
        MethodInfo^ get() { if (__Min_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_ == nullptr) 
          __Min_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<unsigned long long int>::WrappedType, Expr<unsigned long long int>::WrappedType }); return __Min_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<unsigned long long int> Min(Expr<unsigned long long int> val1, Expr<unsigned long long int> val2)
  		{
	  		return Expr<unsigned long long int>(gcnew MethodInvokeExpression<unsigned long long int>
          (_Min_Expr_unsigned_long_long_int__Expr_unsigned_long_long_int_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Min_Expr_unsigned_short__Expr_unsigned_short_;
    	static property MethodInfo^ _Min_Expr_unsigned_short__Expr_unsigned_short_ { 
        MethodInfo^ get() { if (__Min_Expr_unsigned_short__Expr_unsigned_short_ == nullptr) 
          __Min_Expr_unsigned_short__Expr_unsigned_short_ = (System::Math::typeid)->GetMethod("Min", gcnew array<Type^>{ Expr<unsigned short>::WrappedType, Expr<unsigned short>::WrappedType }); return __Min_Expr_unsigned_short__Expr_unsigned_short_; 
        } }
    public:
      /// <summary>
      /// Returns the smaller of two numbers.
      /// </summary>
      static Expr<unsigned short> Min(Expr<unsigned short> val1, Expr<unsigned short> val2)
  		{
	  		return Expr<unsigned short>(gcnew MethodInvokeExpression<unsigned short>
          (_Min_Expr_unsigned_short__Expr_unsigned_short_, nullptr, gcnew array<GenericExpression^>{val1, val2}));
      }

    private:
    	static MethodInfo^ __Pow_Expr_double__Expr_double_;
    	static property MethodInfo^ _Pow_Expr_double__Expr_double_ { 
        MethodInfo^ get() { if (__Pow_Expr_double__Expr_double_ == nullptr) 
          __Pow_Expr_double__Expr_double_ = (System::Math::typeid)->GetMethod("Pow", gcnew array<Type^>{ Expr<double>::WrappedType, Expr<double>::WrappedType }); return __Pow_Expr_double__Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns a specified number raised to the specified power.
      /// </summary>
      static Expr<double> Pow(Expr<double> x, Expr<double> y)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Pow_Expr_double__Expr_double_, nullptr, gcnew array<GenericExpression^>{x, y}));
      }

    private:
    	static MethodInfo^ __Round_Expr_System__Decimal_;
    	static property MethodInfo^ _Round_Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Round_Expr_System__Decimal_ == nullptr) 
          __Round_Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType }); return __Round_Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of Expr<System::Decimal> places.
      /// </summary>
      static Expr<System::Decimal> Round(Expr<System::Decimal> d)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Round_Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Round_Expr_double_;
    	static property MethodInfo^ _Round_Expr_double_ { 
        MethodInfo^ get() { if (__Round_Expr_double_ == nullptr) 
          __Round_Expr_double_ = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Round_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of Expr<System::Decimal> places.
      /// </summary>
      static Expr<double> Round(Expr<double> a)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Round_Expr_double_, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Round_Expr_System__Decimal__Expr_int_;
    	static property MethodInfo^ _Round_Expr_System__Decimal__Expr_int_ { 
        MethodInfo^ get() { if (__Round_Expr_System__Decimal__Expr_int_ == nullptr) 
          __Round_Expr_System__Decimal__Expr_int_ = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType, Expr<int>::WrappedType }); return __Round_Expr_System__Decimal__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of Expr<System::Decimal> places.
      /// </summary>
      static Expr<System::Decimal> Round(Expr<System::Decimal> d, Expr<int> decimals)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Round_Expr_System__Decimal__Expr_int_, nullptr, gcnew array<GenericExpression^>{d, decimals}));
      }

    private:
    	static MethodInfo^ __Round_Expr_double__Expr_int_;
    	static property MethodInfo^ _Round_Expr_double__Expr_int_ { 
        MethodInfo^ get() { if (__Round_Expr_double__Expr_int_ == nullptr) 
          __Round_Expr_double__Expr_int_ = (System::Math::typeid)->GetMethod("Round", gcnew array<Type^>{ Expr<double>::WrappedType, Expr<int>::WrappedType }); return __Round_Expr_double__Expr_int_; 
        } }
    public:
      /// <summary>
      /// Rounds a value to the nearest number or specified number of Expr<System::Decimal> places.
      /// </summary>
      static Expr<double> Round(Expr<double> value, Expr<int> digits)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Round_Expr_double__Expr_int_, nullptr, gcnew array<GenericExpression^>{value, digits}));
      }

    private:
    	static MethodInfo^ __Sign_Expr_System__Decimal_;
    	static property MethodInfo^ _Sign_Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Sign_Expr_System__Decimal_ == nullptr) 
          __Sign_Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType }); return __Sign_Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static Expr<int> Sign(Expr<System::Decimal> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Sign_Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_Expr_double_;
    	static property MethodInfo^ _Sign_Expr_double_ { 
        MethodInfo^ get() { if (__Sign_Expr_double_ == nullptr) 
          __Sign_Expr_double_ = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Sign_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static Expr<int> Sign(Expr<double> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Sign_Expr_double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_Expr_float_;
    	static property MethodInfo^ _Sign_Expr_float_ { 
        MethodInfo^ get() { if (__Sign_Expr_float_ == nullptr) 
          __Sign_Expr_float_ = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ Expr<float>::WrappedType }); return __Sign_Expr_float_; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static Expr<int> Sign(Expr<float> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Sign_Expr_float_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_Expr_int_;
    	static property MethodInfo^ _Sign_Expr_int_ { 
        MethodInfo^ get() { if (__Sign_Expr_int_ == nullptr) 
          __Sign_Expr_int_ = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ Expr<int>::WrappedType }); return __Sign_Expr_int_; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static Expr<int> Sign(Expr<int> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Sign_Expr_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_Expr_long_long_int_;
    	static property MethodInfo^ _Sign_Expr_long_long_int_ { 
        MethodInfo^ get() { if (__Sign_Expr_long_long_int_ == nullptr) 
          __Sign_Expr_long_long_int_ = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ Expr<long long int>::WrappedType }); return __Sign_Expr_long_long_int_; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static Expr<int> Sign(Expr<long long int> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Sign_Expr_long_long_int_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_Expr_signed_char_;
    	static property MethodInfo^ _Sign_Expr_signed_char_ { 
        MethodInfo^ get() { if (__Sign_Expr_signed_char_ == nullptr) 
          __Sign_Expr_signed_char_ = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ Expr<signed char>::WrappedType }); return __Sign_Expr_signed_char_; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static Expr<int> Sign(Expr<signed char> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Sign_Expr_signed_char_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sign_Expr_short_;
    	static property MethodInfo^ _Sign_Expr_short_ { 
        MethodInfo^ get() { if (__Sign_Expr_short_ == nullptr) 
          __Sign_Expr_short_ = (System::Math::typeid)->GetMethod("Sign", gcnew array<Type^>{ Expr<short>::WrappedType }); return __Sign_Expr_short_; 
        } }
    public:
      /// <summary>
      /// Returns a value indicating the sign of a number.
      /// </summary>
      static Expr<int> Sign(Expr<short> value)
  		{
	  		return Expr<int>(gcnew MethodInvokeExpression<int>
          (_Sign_Expr_short_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sin_Expr_double_;
    	static property MethodInfo^ _Sin_Expr_double_ { 
        MethodInfo^ get() { if (__Sin_Expr_double_ == nullptr) 
          __Sin_Expr_double_ = (System::Math::typeid)->GetMethod("Sin", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Sin_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the sine of the specified angle.
      /// </summary>
      static Expr<double> Sin(Expr<double> a)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Sin_Expr_double_, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Sinh_Expr_double_;
    	static property MethodInfo^ _Sinh_Expr_double_ { 
        MethodInfo^ get() { if (__Sinh_Expr_double_ == nullptr) 
          __Sinh_Expr_double_ = (System::Math::typeid)->GetMethod("Sinh", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Sinh_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the hyperbolic sine of the specified angle.
      /// </summary>
      static Expr<double> Sinh(Expr<double> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Sinh_Expr_double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Sqrt_Expr_double_;
    	static property MethodInfo^ _Sqrt_Expr_double_ { 
        MethodInfo^ get() { if (__Sqrt_Expr_double_ == nullptr) 
          __Sqrt_Expr_double_ = (System::Math::typeid)->GetMethod("Sqrt", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Sqrt_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the square root of a specified number.
      /// </summary>
      static Expr<double> Sqrt(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Sqrt_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Tan_Expr_double_;
    	static property MethodInfo^ _Tan_Expr_double_ { 
        MethodInfo^ get() { if (__Tan_Expr_double_ == nullptr) 
          __Tan_Expr_double_ = (System::Math::typeid)->GetMethod("Tan", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Tan_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the tangent of the specified angle.
      /// </summary>
      static Expr<double> Tan(Expr<double> a)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Tan_Expr_double_, nullptr, gcnew array<GenericExpression^>{a}));
      }

    private:
    	static MethodInfo^ __Tanh_Expr_double_;
    	static property MethodInfo^ _Tanh_Expr_double_ { 
        MethodInfo^ get() { if (__Tanh_Expr_double_ == nullptr) 
          __Tanh_Expr_double_ = (System::Math::typeid)->GetMethod("Tanh", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Tanh_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Returns the hyperbolic tangent of the specified angle.
      /// </summary>
      static Expr<double> Tanh(Expr<double> value)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Tanh_Expr_double_, nullptr, gcnew array<GenericExpression^>{value}));
      }

    private:
    	static MethodInfo^ __Truncate_Expr_System__Decimal_;
    	static property MethodInfo^ _Truncate_Expr_System__Decimal_ { 
        MethodInfo^ get() { if (__Truncate_Expr_System__Decimal_ == nullptr) 
          __Truncate_Expr_System__Decimal_ = (System::Math::typeid)->GetMethod("Truncate", gcnew array<Type^>{ Expr<System::Decimal>::WrappedType }); return __Truncate_Expr_System__Decimal_; 
        } }
    public:
      /// <summary>
      /// Calculates the integral part of a number.
      /// </summary>
      static Expr<System::Decimal> Truncate(Expr<System::Decimal> d)
  		{
	  		return Expr<System::Decimal>(gcnew MethodInvokeExpression<System::Decimal>
          (_Truncate_Expr_System__Decimal_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    private:
    	static MethodInfo^ __Truncate_Expr_double_;
    	static property MethodInfo^ _Truncate_Expr_double_ { 
        MethodInfo^ get() { if (__Truncate_Expr_double_ == nullptr) 
          __Truncate_Expr_double_ = (System::Math::typeid)->GetMethod("Truncate", gcnew array<Type^>{ Expr<double>::WrappedType }); return __Truncate_Expr_double_; 
        } }
    public:
      /// <summary>
      /// Calculates the integral part of a number.
      /// </summary>
      static Expr<double> Truncate(Expr<double> d)
  		{
	  		return Expr<double>(gcnew MethodInvokeExpression<double>
          (_Truncate_Expr_double_, nullptr, gcnew array<GenericExpression^>{d}));
      }

    };
    

    /// <summary>
    /// Class that represents variable of type unsigned char.
    /// </summary>
    template<> public ref class Var<unsigned char> : ExpressionWrapper<unsigned char>
    {
		public:
			Var<unsigned char>(String^ name)
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
    template<> public ref class Var<signed char> : ExpressionWrapper<signed char>
    {
		public:
			Var<signed char>(String^ name)
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
    template<> public ref class Var<float> : ExpressionWrapper<float>
    {
		public:
			Var<float>(String^ name)
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
    template<> public ref class Var<double> : ExpressionWrapper<double>
    {
		public:
			Var<double>(String^ name)
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
    template<> public ref class Var<System::Decimal> : ExpressionWrapper<System::Decimal>
    {
		public:
			Var<System::Decimal>(String^ name)
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
    template<> public ref class Var<long long int> : ExpressionWrapper<long long int>
    {
		public:
			Var<long long int>(String^ name)
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
    template<> public ref class Var<short> : ExpressionWrapper<short>
    {
		public:
			Var<short>(String^ name)
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
    template<> public ref class Var<int> : ExpressionWrapper<int>
    {
		public:
			Var<int>(String^ name)
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
    template<> public ref class Var<unsigned long long int> : ExpressionWrapper<unsigned long long int>
    {
		public:
			Var<unsigned long long int>(String^ name)
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
    template<> public ref class Var<unsigned short> : ExpressionWrapper<unsigned short>
    {
		public:
			Var<unsigned short>(String^ name)
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
    template<> public ref class Var<unsigned int> : ExpressionWrapper<unsigned int>
    {
		public:
			Var<unsigned int>(String^ name)
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
    template<> public ref class Var<bool> : ExpressionWrapper<bool>
    {
		public:
			Var<bool>(String^ name)
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
    template<> public ref class Var<wchar_t> : ExpressionWrapper<wchar_t>
    {
		public:
			Var<wchar_t>(String^ name)
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
    template<> public ref class Var<String^> : ExpressionWrapper<String^>
    {
		public:
			Var<String^>(String^ name)
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
