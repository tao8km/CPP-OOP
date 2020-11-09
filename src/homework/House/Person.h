#pragma once
#include <iostream>

class Person
{
    char* name;
public:
    Person(const char* name);
    Person(const Person& other);
    ~Person();
    Person& operator=(const Person& other);

    const char* getName() const { return name; }
};

std::ostream& operator<<(std::ostream& os, const Person& person);
