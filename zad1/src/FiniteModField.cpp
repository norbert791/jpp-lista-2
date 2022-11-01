#include <stdexcept>
#include <cmath>
#include <string>
#include <iostream>
#include <FiniteModField.hpp>

using namespace MyField;
using ull = unsigned long long;

FiniteModField FiniteModField::transformBase(const FiniteModField& number) const{
  ull maxBase = std::max(number.base, this->base);
  ull minBase = std::min(number.base, this->base);
  if (maxBase < 2) {throw std::domain_error("Operations on two implicit mod numbers are impossible");}
  if (minBase > 1 && minBase != maxBase) {
    throw std::domain_error("Cannot convert mod " + std::to_string(number.base) +
                " number to mod " + std::to_string(this->base) + " number");
  }
  FiniteModField result(number.value, maxBase);
  if (number.base == 1) {result = - result;}
  return result;
}

FiniteModField FiniteModField::operator +(const FiniteModField& number) const{
  auto checkedNumber = this->transformBase(number);
  //Note: transformBase converts only number's base, not *this* base due to immutability.
  //Therefore we must create copy of this number with converted base. 
  auto checkedNumber2 = number.transformBase(*this);
  return FiniteModField((checkedNumber2.value + checkedNumber.value) % checkedNumber.base, checkedNumber.base);  
}

FiniteModField FiniteModField::operator -(const FiniteModField& number) const{
  auto checkedNumber = this->transformBase(number);
  checkedNumber = -checkedNumber;
  return checkedNumber + (*this);
}

FiniteModField FiniteModField::operator -() const {
  if (this->base < 2) {throw std::domain_error("Inverse number can't be found for implicit base");}
  return FiniteModField((this->base - this->value), this->base);  
}

FiniteModField FiniteModField::operator *(const FiniteModField& number) const{
  auto checkedNumber = this->transformBase(number);
  //Note: transformBase converts only number's base, not *this* base due to immutability.
  //Therefore we must create copy of this number with converted base.
  auto checkedNumber2 = number.transformBase(*this);

  return FiniteModField((checkedNumber2.value * checkedNumber.value) % checkedNumber.base, checkedNumber.base);  
}

FiniteModField FiniteModField::operator /(const FiniteModField& number) const{
  auto checkedNumber = this->transformBase(number);
  if (checkedNumber == 0) {
    throw std::domain_error("Zero division attempt");
  }
  else if (this->value == 0) {return FiniteModField(0, this->base);}

  //https://cdn.intechopen.com/pdfs/29704/InTech-Division_and_inversion_over_finite_fields.pdf
  
  ull y1 = 0;
  ull y2 = 1;
  ull a = checkedNumber.value;
  ull P = checkedNumber.base;

  while (a != 1) {
    ull q = P / a;
    ull newA = P - ((q * a) % P); //FiniteModField(q, P) * FiniteModField(a, P)
    ull newP = a;
    ull newY2 = y1;
    
    y1 = y2 % P > q ? (y2 % P) - q : P - (q - (y2 % P)); //(FiniteModField(y2, P) - (FiniteModField(q, P) * FiniteModField(y1, P))).value;
    P = newP;
    y2 = newY2;
    a = newA;
  }
  return FiniteModField(y1, checkedNumber.base) * (*this);
}

bool FiniteModField::operator ==(const FiniteModField& number) const{
  return this->base == number.base && this->value == number.value;
}

FiniteModField& FiniteModField::operator += (const FiniteModField& number) {*this = *this + number; return *this;}
FiniteModField& FiniteModField::operator -= (const FiniteModField& number) {*this = *this - number; return *this;}
FiniteModField& FiniteModField::operator *= (const FiniteModField& number) {*this = *this * number; return *this;}
FiniteModField& FiniteModField::operator /= (const FiniteModField& number) {*this = *this / number; return *this;}

std::ostream& MyField::operator << (std::ostream& stream, const FiniteModField& number) {
  return (stream << (std::to_string(number.value) + " mod " + std::to_string(number.base)));
}

std::istream& MyField::operator >> (std::istream& stream, FiniteModField& number) {
  ull value;
  ull base;
  stream >> value;
  stream >> base;
  number = FiniteModField(value, base);
  return stream;
}

bool FiniteModField::isPrime(const ull number) {
  if (number < 2) {return false;}
  
  for (ull i = 2; i * i <= number; i++) {
    if (number % i == 0) {return false;}
  }

  return true;
}

FiniteModField::FiniteModField(ull value, ull base) : value{value}, base{base} {
  if (!isPrime(base)) {throw std::domain_error("Base is not a prime number");}
  ull temp = base * base;
  if (temp / base != base) {throw std::domain_error("Base must not exceed sqrt (MAX_ULL)");}
  this->value %= base;
}

FiniteModField::FiniteModField(unsigned long long val) : value{val}, base{0} {}

FiniteModField::FiniteModField(signed long long val) : value{static_cast<ull>(std::abs(val))}, base{1} {}

FiniteModField& FiniteModField::operator ++ () noexcept {
  this->value = (this->value + 1) % this->base;
  return *this;
}

FiniteModField& FiniteModField::operator -- () noexcept {
  if (this->value > 0) {this->value--;}
  else {this->value = this->base - 1;}
  return *this;
}