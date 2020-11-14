#include <iostream>
#include "Stack.h"

int main()
{
    Stack<double> stack;
    for (int i = 0; i < 10; i++)
        stack.push(i);

    while (!stack.empty())
        std::cout << ' ' << stack.pop();
    std::cout << std::endl;
}
