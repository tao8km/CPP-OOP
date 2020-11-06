#include "Array.h" // необходимо подключать заголовок класса, чтобы дать компилятору информацию о классе

/**
 * Свободная функция (не метод класса Array), перегружающая оператор << для массива.
 * Выводит элементы массива в поток os.
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

