#include <iostream>
#include "Vector.h"

int main()
{
    Vector<int> a;

    for (int i = 0; i < 12; i++) {
        a.push_back(i);
    }

    std::cout << a << std::endl;
}
