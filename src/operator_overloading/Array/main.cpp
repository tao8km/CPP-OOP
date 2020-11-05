#include <iostream>
#include "Array.h"

int main()
{
    Array a;

    for (int i = 0; i < 12; i++) {
        a.push_back(i);
    }

    std::cout << "a: " << a << std::endl;

    a[0] = -123;
    a[10] = 456;

    std::cout << "a: " << a << std::endl;

    Array b(15);
    for (int i = -8; i < 0; i++) {
        b.push_back(i);
    }
    std::cout << "b: " << b << std::endl;

    Array c(12);
    for (int i = 30; i < 45; i++) {
        c.push_back(i);
    }
    std::cout << "c: " << c << std::endl;


    a = b = c;

    std::cout << "\nПосле присваивания объектов\n";
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
}
