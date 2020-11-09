#include <iostream>
#include "Person.h"
#include "Flat.h"
#include "House.h"

int main() {
    House house(100); // дом на 100 квартир. Будет создано 100 пустых квартир
    house.addResident(1, Person("Vasya Vasin"));
    house.addResident(1, Person("Anya Vasina"));
    house.addResident(1, Person("Petya Vasin"));

    house.addResident(2, Person("Ivan Ivanov"));
    house.addResident(2, Person("Sveta Ivanova"));

    std::cout << house;
}
