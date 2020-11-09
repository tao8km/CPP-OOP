#include "PhoneBook.h"

PhoneBook::PhoneBook(int size)
    : abonents {new Abonent* [size]}, // выделяется память под массив указателей на абонентов, объекты не создаются
     memoryCapacity {size}
{
}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < numberOfAbonents; i++)
        delete abonents[i]; // удаляю абонентов (объекты)
    delete[] abonents; // удаляю память из под массива указателей на абонентов
}

void PhoneBook::addAbonent(const Abonent& abonent) {
    if (numberOfAbonents == memoryCapacity) {
        resize(memoryCapacity * 2);
    }

    Abonent* newAbonent = new Abonent(abonent); // вызывается конструктор копирования Абонента
    abonents[numberOfAbonents] = newAbonent;
    numberOfAbonents++;
}

void PhoneBook::resize(int newSize) {
    Abonent** memory = new Abonent* [newSize];
    for (int i = 0; i < numberOfAbonents; i++)
        memory[i] = abonents[i]; // вызывается оператор присваивание Абонента
    memoryCapacity = newSize;
    delete[] abonents;
    abonents = memory;
}

std::ostream& operator<< (std::ostream& os, const PhoneBook& pb) {
    for (int i = 0; i < pb.numberOfAbonents; i++)
        os << *(pb.abonents[i]) << '\n'; // разыменовываю указатель на абонента
    return os;
}
