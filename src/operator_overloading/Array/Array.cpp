#include "Array.h" // необходимо подключать заголовок класса, чтобы дать компилятору информацию о классе

Array::Array(Array&& other) {
    *this = other; // использую оператор перемещающего присваивания

    std::cout << "Array(Array&&)\n";
}

Array& Array::operator= (Array&& other) {
    if (this != &other) {
        count = other.count;
        capacity = other.capacity;
        elements = other.elements;

        other.count = other.capacity = 0;
        other.elements = nullptr;
    }

    std::cout << "operator= (Array&&)\n";

    return *this;
}

/**
 * Свободная функция (не метод класса Array), перегружающая оператор << для Array
 * Выводит элементы Array в поток os.
 */
std::ostream& operator<<(std::ostream& os, const Array& array) {
    os << '[';

    int i;
    for (i = 0; i < array.size() - 1; i++) {
        os << array[i] << ", ";
    }

    if (array.size() > 0)
        os << array[i];

    return os << ']';
}

