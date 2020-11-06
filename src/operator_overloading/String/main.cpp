#include <iostream>
#include "String.h"

void func(String str) {
    std::cout << "func(str): " << str << std::endl;
}

int main()
{
    String hello("Hello, world!");
    const char* str = hello; // используем перегруженный оператор приведения к типу const char*

    std::cout << str << std::endl;

    std::cout << String("C++") + String(" rules") << std::endl; // создается 2 анонимных объекта (без имени), для которых вызывается оператор +

    hello += " Good day!"; // неявный вызов конструктора String(const char*) для строки " Good day!";
    std::cout << hello << std::endl;

    String s = hello;
    std::cout << s << std::endl;
    s = "12345";
    std::cout << s << std::endl;

    func(std::move(String("Hello, I am temporary object!"))); // временный объект, существует только в данной строке. Можно забрать у него ресурсы вместо создания копии. Для передачи временного объекта в функцию будет вызван перемещающий конструктор. Функция std::move вернет правостороннюю ссылку на объект (String&&).

    String temp("Temp object");
    func(std::move(temp)); // после этого вызова объект temp лишится своей строки.

    s = String("Another temp object"); // будет вызван оператор перемещающего присваивания
}
