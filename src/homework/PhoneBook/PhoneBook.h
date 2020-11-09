#pragma once
#include <iostream> // std::ostream
#include "Abonent.h"

class PhoneBook
{
    Abonent** abonents = nullptr; // массив указателей на абонентов
    int memoryCapacity; // потенциальное количество указателей на абонентов в массиве abonents (количество выделенных элементов массива)
    int numberOfAbonents = 0; // фактическое количество указателей на абонентов, помещенных в массив abonents (количество используемых элементов массива)

public:
    PhoneBook(int size = 10);
    ~PhoneBook();

    void addAbonent(const Abonent& abonent);

    friend std::ostream& operator<< (std::ostream& os, const PhoneBook& pb);

private:
    void resize(int newSize);
};
