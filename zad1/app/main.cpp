#include <iostream>
#include <FiniteModField.hpp>

int main() {

  constexpr unsigned long long base = 7;//1234567891;
  constexpr unsigned long long val1 = 5;
  constexpr signed long long val2 = -2;
  constexpr unsigned long long val3 = 2;

  MyField::FiniteModField num1(val1, base);
  MyField::FiniteModField num2(3, base);
  MyField::FiniteModField num3 = num1 + num2;

  std::cout<<num3 + num2<<std::endl;
  std::cout<<num2 - num1<<std::endl;
  std::cout<<num2 * num1<<std::endl;
  std::cout<<num2 / num1<<std::endl;
  std::cout<<("------------------\n#= operators"
             "\n------------------")<<std::endl;
  num2 = MyField::FiniteModField(val3, base);
  num2 += num1;
  std::cout<<num2<<std::endl;
  num2 -= num1;
  std::cout<<num2<<std::endl;
  num2 *= num1;
  std::cout<<num2<<std::endl;
  num2 /= num1;
  std::cout<<num2<<std::endl;
  std::cout<<("----------------------------\nFrom unsigned long long"
             "\n------------------")<<std::endl;
  num2 = MyField::FiniteModField(val3, base);
  num2 += val1;
  std::cout<<num2<<std::endl;
  num2 -= val1;
  std::cout<<num2<<std::endl;
  num2 *= val1;
  std::cout<<num2<<std::endl;
  num2 /= val1;
  std::cout<<num2<<std::endl;
  std::cout<<("------------------\nFrom long long"
             "\n------------------")<<std::endl;
  num2 = MyField::FiniteModField(val3, base);
  num2 = num2 + MyField::FiniteModField(val2);
  std::cout<<num2<<std::endl;
  num2 -= MyField::FiniteModField(val2);
  std::cout<<num2<<std::endl;
  num2 *= MyField::FiniteModField(val2);
  std::cout<<num2<<std::endl;
  num2 /= MyField::FiniteModField(val2);
  std::cout<<num2<<std::endl;

  return 0;
}