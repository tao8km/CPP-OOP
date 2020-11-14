#include "House.h"

House::House(int numberOfFlats)
    : numberOfFlats {numberOfFlats}, flats {new Flat [numberOfFlats]} // массив будет заполнен квартирами, созданными конструктором по умолчанию (без аргументов)
{
}

House::House(const House& other)
    : House(other.numberOfFlats)
{
    for (int i = 0; i < numberOfFlats; i++)
        flats[i] = other.flats[i]; // работает оператор присваивания
}

House::~House() {
    // т.к. в массиве у нас сами объекты, а не указатели, то не нужно удалять каждый объект отдельно, они все удалятся
    // с помощью оператора delete[]
    delete[] flats;
}

House& House::operator= (const House& other) {
    if (this != &other) {
        numberOfFlats = other.numberOfFlats;
        for (int i = 0; i < numberOfFlats; i++)
            flats[i] = other.flats[i];
    }

    return *this;
}

void House::addResident(int flatNumber, const Person& resident) {
    --flatNumber; // в массиве индексы идут с нуля
    if (flatNumber < 0 || flatNumber >= numberOfFlats)
        return;
    flats[flatNumber].addResident(resident);
}

std::ostream& operator<<(std::ostream& os, const House& house) {
    for (int i = 0; i < house.numberOfFlats; i++) {
        const Flat& flat = house.flats[i];
        int residentsNumber = flat.getResidentsCount();
        if (residentsNumber > 0) {
            os << "Flat № " << i + 1 << '\n';
            os << "Area: " << flat.getArea() << '\n';
            os << "Number of rooms: " << flat.getRoomsNumber() << '\n';
            os << "Residents: " << flat;
        }
    }
    return os << '\n';
}
