#include <algorithm> // std::sort
#include <iostream>
#include <cstdlib> // std::rand
#include <ctime> // std::time
#include "Student.h"

int main()
{
    std::srand(std::time(NULL));
    const int upperMark = 5;
    const int lowerMark = 2;

    Student vasya("Vasiliy Petrov");
    std::cout << vasya << std::endl;

    for (int i = 0; i < 15; i++) {
        int mark = rand() % (upperMark - lowerMark + 1) + lowerMark; // чтобы оценка была в диапазоне [2, 5]
        vasya.addMark(mark);
    }
    std::cout << vasya << std::endl;

    Student students[] = {
        vasya,
        Student("Ivan Ivanov", {3, 4, 5, 3, 4}), // для создания объектов Array неявно вызывается конструктор Array(initializer_list)
        Student("Petya Petrov", {5, 4, 4, 5, 3}),
        Student("Sidor Sidorov", {4, 4, 5, 5, 3}),
        Student("Alex Medvedev", {4, 3, 3, 5, 4}),
        Student("Yakov Yakovlev", {3, 4, 5, 5, 5}),
        Student("Alex Alexandrov", {4, 4, 5, 3, 4})
    };
    size_t studentsCount = sizeof(students) / sizeof(students[0]);

    std::sort(students, students + studentsCount);

    std::cout << "\nName\t\tMarks\t\tAvg mark\n\n";
    for (const auto& stud : students) {
        std::cout << stud << ' ' << stud() << std::endl;
    }
}
