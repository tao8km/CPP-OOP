#include <iostream>
#include "PhoneBook.h"
#include "Abonent.h"

int main()
{
    PhoneBook book;

    book.addAbonent(Abonent("Vasiliy Petrov", "1111111", "2222222", "81234567890", "My friend"));
    book.addAbonent(Abonent("Petr Vasilyev", "1234567", "7654321", "83434567890", "Boss"));

    std::cout << book;
}
