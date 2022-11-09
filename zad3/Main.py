from MyField import FiniteModField

if __name__ == "__main__":
    base = 7
    val1 = 5
    num1 = FiniteModField(val1, base)
    num2 = FiniteModField(3, base)
    num3 = num1 + num2
    num2FromNeg = FiniteModField(-4, base)
    num1FromNeg = FiniteModField(-val1, base)
    num1FromNeg = -num1FromNeg

    print(num3 + num2)
    print(num2 - num1)
    print(num2 * num1)
    print(num2 / num1)
    print("-------------")
    print(num3 + num2FromNeg)
    print(num2 - num1FromNeg)
    print(num2 * num1FromNeg)
    print(num2 / num1FromNeg)