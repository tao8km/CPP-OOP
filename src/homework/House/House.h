#pragma once
#include <iostream>
#include "Person.h"
#include "Flat.h"

class House
{
    int numberOfFlats;
    Flat* flats = nullptr; // будем хранить в массиве сами объекты-квартиры

public:
    House(int numberOfFlats);
    House(const House& other);
    ~House();

    House& operator= (const House& other);

    void addResident(int flatNumber, const Person& resident);

    int getNumberOfFlats() const { return numberOfFlats; }

    friend std::ostream& operator<<(std::ostream& os, const House& house);
};

