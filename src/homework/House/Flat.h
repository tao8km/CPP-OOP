#pragma once
#include <iostream>
#include "Person.h"

class Flat
{
    int capacity = 3;
    int count = 0;
    Person** residents = nullptr;

    double area;
    int roomsNumber;

public:
    Flat(double area = 50.0, int roomsNumber = 1);
    Flat(const Flat& other);
    ~Flat();

    Flat& operator= (const Flat& other);

    void addResident(const Person& resident);
    const Person& getResident(int index) const { return *residents[index]; }

    int getResidentsCount() const { return count; }
    double getArea() const { return area; }
    int getRoomsNumber() const { return roomsNumber; }

private:
    void resize(int newSize);
};

std::ostream& operator<<(std::ostream& os, const Flat& flat);
