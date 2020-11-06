#pragma once

#include <iostream>
#include "Array.h"
#include "String.h"

class Student
{
    String name;
    Array marks;

public:
    // для marks предусмотрено значение по умолчанию - вызов конструктора без аргументов
    Student(String name, Array marks = {}) : name {name}, marks {marks}
    {
    }

    // т.к. в классе нет ресурсов, то и нет необходимости объявлять конструктор копирования, деструктор,
    // оператор присваивания, перемещающий конструктор, оператор перемещающего присваивания - их все создаст компилятор
    // и по умолчанию они будут выполнять побитовое копирование/перемещение всех полей объекта. Если у полей объекта
    // есть свои конструктор копирования/перемещения, оператор присваивания, перемещающего присваивания, то
    // они будут вызваны при копировании/перемещении объекта Student. В данном случае у Array и String есть такие операции.

    int getMark(int index) const { // метод константный, чтобы можно было его вызывать для константного объекта Student
        // можно выполнить проверку значения index на попадание в диапазон [0, marks.size())
        return marks[index];
    }

    void changeMark(int index, int mark) {
        marks[index] = mark;
    }

    void addMark(int mark) {
        marks.push_back(mark);
    }

    // заголовок метода
    double operator() () const;
    bool operator< (const Student& other) const;

    friend std::ostream& operator<< (std::ostream& os, const Student& student);
};
