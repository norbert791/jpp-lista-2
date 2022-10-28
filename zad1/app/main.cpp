#include <iostream>
#include <FiniteModField.hpp>

int main() {

    MyField::FiniteModField num1(5, 7);
    MyField::FiniteModField num2(3, 7);
    MyField::FiniteModField num3 = num1 + num2;

    std::cout<<num3 + num2<<std::endl;
    std::cout<<num2 - num1<<std::endl;
    std::cout<<num2 * num1<<std::endl;
    std::cout<<num2 / num1<<std::endl;
    return 0;
}