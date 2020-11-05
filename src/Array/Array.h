#pragma once
#include <iostream>


class Array
{
    int count = 0; // количество элементов (сколько элементов уже помещено)
    int capacity = 0; // объем выделенной памяти (сколько можно поместить элементов)
    int *elements = nullptr; // указатель на массив элементов

public:

    Array(int capacity = 10)
        : capacity {capacity}
    {
        elements = new int[capacity];
    }

    // копирующий конструктор
    Array(const Array& other)
        : count {other.count}, capacity {other.capacity}
    {
        elements = new int[capacity];
        for (int i = 0; i < count; i++) {
            elements[i] = other.elements[i];
        }
    }

    ~Array() {
        delete[] elements;
    }

    // оператор присваивания
    Array& operator=(const Array& other) {
        if (this != &other) { // проверяем, что не происходит присваивания объекта самому себе
            if (capacity < other.capacity) { // если нужно, то выделяем больше памяти
                increaseMemory(other.capacity);
            }

            count = other.count;
            for (int i = 0; i < count; i++) {
                elements[i] = other.elements[i];
            }
        }

        return *this; // необходимо вернуть ссылку на объект, для которого выполнялось присваивание
    }

    // оператор индексирования
    int& operator[] (int index) {
        return elements[index];
    }

    // константный оператор индексирования
    const int& operator[] (int index) const {
        return elements[index];
    }

    // добавить элемент в конец массива
    void push_back(int elem) {
        if (count == capacity) {
            increaseMemory(capacity * 2);
        }

        elements[count] = elem;
        ++count;
    }

    int size() const { return count; }

private:

    /**
     * Выделяет новую память под массив и копирует в нее элементы. Старая память освобождается.
     */
    void increaseMemory(int newCapacity) {
        // выделяю новую память
        int* memory = new int[newCapacity];

        // копирую элементы массива в новую память
        for (int i = 0; i < count; i++) {
            memory[i] = elements[i];
        }

        // освобождаю старую память
        delete[] elements;
        // устанавливаю указатель на новую память
        elements = memory;
        // обновляю значение поля 'объем'
        capacity = newCapacity;
    }
}; // <-- class declaration ends here


// необходимо оставить заголовок функции, чтобы при подключении этого заголовочного файла компилятор
// знал о существовании данной функции. Тело функции в файле с реализацией класса, чтобы при подключении
// файла в нескольких местах программы не было одинаковых функций.
std::ostream& operator<<(std::ostream& os, const Array& array);
