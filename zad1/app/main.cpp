#include <iostream>
#include <FiniteModField.hpp>

int main() {

    constexpr unsigned long long base = 1234567891;
    constexpr unsigned long long val1 = 5;
    constexpr unsigned long long val2 = -3;

    MyField::FiniteModField num1(val1, base);
    MyField::FiniteModField num2(3, base);
    MyField::FiniteModField num3 = num1 + num2;

    std::cout<<num3 + num2<<std::endl;
    std::cout<<num2 - num1<<std::endl;
    std::cout<<num2 * num1<<std::endl;
    std::cout<<num2 / num1<<std::endl;

    num2 = MyField::FiniteModField(2, base);
    num2 += num1;
    std::cout<<num2<<std::endl;
    num2 -= num1;
    std::cout<<num2<<std::endl;
    num2 *= num1;
    std::cout<<num2<<std::endl;
    num2 /= num1;
    std::cout<<num2<<std::endl;

    num2 = MyField::FiniteModField(2, base);
    num2 += val1;
    std::cout<<num2<<std::endl;
    num2 -= val1;
    std::cout<<num2<<std::endl;
    num2 *= val1;
    std::cout<<num2<<std::endl;
    num2 /= val1;
    std::cout<<num2<<std::endl;

    num2 = MyField::FiniteModField(2, base);
    num2 += MyField::FiniteModField(static_cast<long long>(val2));
    std::cout<<num2<<std::endl;
    num2 -= MyField::FiniteModField(static_cast<long long>(val2));;
    std::cout<<num2<<std::endl;
    num2 *= MyField::FiniteModField(static_cast<long long>(val2));;
    std::cout<<num2<<std::endl;
    num2 /= MyField::FiniteModField(static_cast<long long>(val2));;
    std::cout<<num2<<std::endl;

    return 0;
}