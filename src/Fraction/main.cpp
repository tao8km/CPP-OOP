#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction a(2, 3);
    Fraction b(4, 5);
    Fraction c(4, 3);

    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
    std::cout << std::endl;

    c += a;
    std::cout << "c += a: " << c << std::endl;

    c -= a;
    std::cout << "c -= a: " << c << std::endl;

    c *= a;
    std::cout << "c *= a: " << c << std::endl;

    c /= a;
    std::cout << "c /= a: " << c << std::endl;
    std::cout << std::endl;

    std::cout << "--b: " << --b << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "b++: " << b++ << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << std::endl;
    std::cout << "a = " << a << ", a(): " << a() << std::endl;
}
