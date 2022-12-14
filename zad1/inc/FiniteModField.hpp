#ifndef MY_FIELD_MOD_FINITE_FIELD_HPP
#define MY_FIELD_MOD_FINITE_FIELD_HPP
#include <istream>
#include <ostream>
#include "Field.hpp"

namespace MyField {
  class FiniteModField;

  std::ostream& operator << (std::ostream& stream, const FiniteModField& number);
  std::istream& operator >> (std::istream& stream, FiniteModField& number);
  /**
   * GF(P) where P is a prime number
  */
  class FiniteModField final : MyField::Field{
    public:
      FiniteModField(unsigned long long value, unsigned long long base);
      FiniteModField() = delete;
      FiniteModField(unsigned long long number);
      explicit FiniteModField(signed long long number);
      FiniteModField operator + (const FiniteModField& number) const;
      FiniteModField operator - (const FiniteModField& number) const;
      FiniteModField operator * (const FiniteModField& number) const;
      FiniteModField operator / (const FiniteModField& number) const;
      FiniteModField operator - () const;
      FiniteModField& operator ++ () noexcept override final;
      FiniteModField& operator -- () noexcept override final;
      FiniteModField& operator += (const FiniteModField& number);
      FiniteModField& operator -= (const FiniteModField& number);
      FiniteModField& operator *= (const FiniteModField& number);
      FiniteModField& operator /= (const FiniteModField& number);
      bool operator == (const FiniteModField& number) const;
      inline unsigned long long returnBase() const noexcept {return base;}
      inline unsigned long long returnValue() const noexcept {return value;}
      friend std::ostream& operator << (std::ostream& stream, const FiniteModField& number);
      friend std::istream& operator >> (std::istream& stream, FiniteModField& number);
    private:
      /**
       * This number's value.
       * Note: This variable is considered to be immutable. We leave it mutable to simplyfy copy/move semantics
      */
      unsigned long long value = 0;
      /**
       * Base = 0 means that this number is "implicit natural"
       * Base = 1 means that this number is "implicity negative"
       * Note: This variable is considered to be immutable. We leave it mutable to simplyfy copy/move semantics
      */
      unsigned long long base = 0;
      /**
       * create new FiniteModField number with implicit base converted if necessary.
      */
      FiniteModField transformBase(const FiniteModField& number) const;
      bool isPrime(unsigned long long number);
  };
}

#endif /* MY_FIELD_MOD_FINITE_FIELD_HPP */