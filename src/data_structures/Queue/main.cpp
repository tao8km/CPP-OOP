#include <iostream>
#include "Queue.h"

int main()
{
    Queue<int> q;

    for (int i = 0; i < 10; i++)
        q.enqueue(i);

    while (!q.empty())
        std::cout << ' ' << q.dequeue();
    std::cout << std::endl;
}
