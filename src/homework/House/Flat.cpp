#include "Flat.h"


Flat::Flat(double area, int roomsNumber)
    : residents {new Person* [capacity] {}}, // внутренние {} означают инициализацию элементов массива по умолчанию
    // (для указателей - нули)
    area {area}, roomsNumber {roomsNumber}
{
}

Flat::Flat(const Flat& other)
{
    capacity = other.capacity;
    count = other.count;
    residents = new Person* [capacity];
    for (int i = 0; i < count; i++)
        residents[i] = new Person(*other.residents[i]);

    area = other.area;
    roomsNumber = other.roomsNumber;
}

Flat::~Flat() {
    for (int i = 0; i < count; i++)
        delete residents[i];
    delete[] residents;
}

Flat& Flat::operator= (const Flat& other) {
    if (this != &other) {
        this->~Flat();
        capacity = other.capacity;
        count = other.count;
        residents = new Person* [capacity];
        for (int i = 0; i < count; i++)
            residents[i] = new Person(*other.residents[i]);
        area = other.area;
        roomsNumber = other.roomsNumber;
    }

    return *this;
}

void Flat::addResident(const Person& resident) {
    if (count == capacity) {
        resize(capacity * 2);
    }

    Person* newPerson = new Person(resident);
    residents[count++] = newPerson;
}

void Flat::resize(int newSize) {
    Person** memory = new Person* [newSize];
    capacity = newSize;
    for (int i = 0; i < count; i++)
        memory[i] = residents[i];
    delete[] residents;
    residents = memory;
}

std::ostream& operator<<(std::ostream& os, const Flat& flat) {
    for (int i = 0; i < flat.getResidentsCount(); i++)
        os << flat.getResident(i) << ' ';
    return os << '\n';
}
