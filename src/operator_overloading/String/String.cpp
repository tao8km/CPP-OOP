#include "String.h"

// глобальная функция
// передаем left по значению, чтобы получить копию, модифицировать ее и вернуть; передаем right по ссылке, чтобы исключить лишнее копирование.
String operator+(String left, const String& right) {
    return left += right; // используем перегруженный оператор +=
}

// глобальная дружественная функция
std::ostream& operator<< (std::ostream& os, const String& str) {
    if (str.ptr != nullptr)
        os << str.ptr;
    return os; // возвращаем ссылку на поток для выполнения нескольких операций вывода в одном выражении cout << a << b << c << d; // выполняются слева-направо
}

bool operator== (const String& left, const String& right) {
    if (left.length() != right.length())
        return false;

    size_t size = left.length();
    for (size_t i = 0; i < size; i++) {
        if (left[i] != right[i])
            return false;
    }

    return true;
}

bool operator!= (const String& left, const String& right) {
    return !(left == right); // используем перегруженный оператор == и инвертируем его значение
}

bool operator< (const String& left, const String& right) {
    // strcmp принимает аргументы типа const char*, и у класса String как раз есть оператор преобразование в этот тип
    return std::strcmp(left, right) < 0; // strcmp вернет отрицательное число, если левая строка меньше правой
}
