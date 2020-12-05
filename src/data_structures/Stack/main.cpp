#include <iostream>
#include "Stack.h"

int main()
{
    Stack<double> a;
    for (int i = 0; i < 10; i++)
        a.push(i);

    Stack<double> b;
    for (int i = -10; i < 5; i++)
        b.push(i);

    auto addition = a + b;
    std::cout << "a + b = ";
    while (!addition.empty())
        std::cout << ' ' << addition.pop();
    std::cout << std::endl;

    auto multiplication = a * b;
    std::cout << "a * b = ";
    while (!multiplication.empty())
        std::cout << ' ' << multiplication.pop();
    std::cout << std::endl;
}
