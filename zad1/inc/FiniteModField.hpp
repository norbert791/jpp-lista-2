#ifndef MY_FIELD_MOD_FINITE_FIELD_HPP
#define MY_FIELD_MOD_FINITE_FIELD_HPP
#include <istream>
#include <ostream>
#include "Field.hpp"

namespace MyField {
    class FiniteModField final : MyField::Field{
        public:
            FiniteModField(unsigned long long value, unsigned long long base);
            FiniteModField() = delete;
            FiniteModField(unsigned long long);
            FiniteModField(long long);
            FiniteModField operator + (const FiniteModField& number);
            FiniteModField operator - (const FiniteModField& number);
            FiniteModField operator * (const FiniteModField& number);
            FiniteModField operator / (const FiniteModField& number);
            FiniteModField operator - ();
            FiniteModField& operator ++ () override final noexcept;
            FiniteModField& operator -- () override final noexcept;
            inline unsigned long long returnBase() {return base;} noexcept;
            friend std::ostream& operator << (std::ostream&, const FiniteModField&);
            friend std::istream& operator >> (std::ostream&, const FiniteModField&);
        private:
            const unsigned long long value = 0;
            const unsigned long long base = 0;
            FiniteModField transformBase(const FiniteModField& number);
    };
}

#endif /* MY_FIELD_MOD_FINITE_FIELD_HPP */