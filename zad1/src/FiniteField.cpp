#include <stdexcept>
#include <format>
#include "FiniteModField.hpp"

using namespace MyField;
using ull = unsigned long long;

FiniteModField FiniteModField::transformBase(const FiniteModField& number) {
    if (number.base == 0 || number.base == this->base) {return FiniteModField(number.value, this->base);}
    throw std::domain_error(std::format("Cannot convert mod {} number to mod {} number", number.base, this->base));
}

FiniteModField FiniteModField::operator +(const FiniteModField& number) {
    auto checkedNumber = this->transformBase(number);

    return FiniteModField((this->value + checkedNumber.value ) % this->base, this->base);  
}

FiniteModField FiniteModField::operator -(const FiniteModField& number) {
    auto checkedNumber = this->transformBase(number);
    checkedNumber = - checkedNumber;

    return checkedNumber + (*this);
}

FiniteModField FiniteModField::operator -() {
    return FiniteModField((this->base - this->value) % this->base, this->base);  
}

FiniteModField FiniteModField::operator *(const FiniteModField& number) {
    auto checkedNumber = this->transformBase(number);

    return FiniteModField((this->value + number.value ) % this->base, this->base);  
}

FiniteModField FiniteModField::operator+(const FiniteModField& number) {
    auto checkedNumber = this->transformBase(number);

    return FiniteModField((this->value + number.value ) % this->base, this->base);  
}