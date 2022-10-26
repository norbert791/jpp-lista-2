#ifndef MY_FIELD_MOD_FINITE_FIELD_HPP
#define MY_FIELD_MOD_FINITE_FIELD_HPP
#include <istream>
#include <ostream>
#include "Field.hpp"

namespace MyField {
    class FiniteModField final : MyField::Field{
        public:
            FiniteModField(unsigned long long number);
            FiniteModField() = default;
            FiniteModField operator + (const FiniteModField& number);
            FiniteModField operator - (const FiniteModField& number);
            FiniteModField operator * (const FiniteModField& number);
            FiniteModField operator / (const FiniteModField& number);
            FiniteModField& operator ++ () override final;
            FiniteModField& operator -- () override final;
            unsigned long long returnBase();
            friend std::ostream& operator << (std::ostream&, const FiniteModField&);
            friend std::istream& operator >> (std::ostream&, const FiniteModField&);
        private:
            const unsigned long long value;
    };
}

#endif /* MY_FIELD_MOD_FINITE_FIELD_HPP */