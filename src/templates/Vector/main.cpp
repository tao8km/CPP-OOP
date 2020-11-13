#include <iostream>
#include "Vector.h"

int main()
{
    Vector<int> a;

    for (int i = 0; i < 12; i++) {
        a.push_back(i);
    }

    std::cout << a << std::endl;

    Vector<int> b = a;
    Vector<int> c = std::move(b);
    b = std::move(c);

    Vector<int*> d {new int(1), new int(2), new int(3)};
    for (const auto& elem : d)
        delete elem;
}
