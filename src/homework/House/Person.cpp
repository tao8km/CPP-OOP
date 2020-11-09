#include "Person.h"
#include <cstring>

Person::Person(const char* name)
    : name {new char [std::strlen(name) + 1]}
{
    std::strcpy(this->name, name);
}

Person::Person(const Person& other)
    : Person(other.name)
{
}

Person::~Person() {
    delete[] name;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] name;
        name = new char [std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    return os << person.getName();
}
