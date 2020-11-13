#include <iostream>
#include "Array.h"
#include "Student.h"

int main()
{
    Array<int> a;

    for (int i = 0; i < 12; i++) {
        a.push_back(i);
    }

    Array<Student*> students(4);

}
