#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <initializer_list>


template<typename T>
class Array
{
    int count = 0; // количество элементов (сколько элементов уже помещено)
    int capacity = 0; // объем выделенной памяти (сколько можно поместить элементов)
    T *elements = nullptr; // указатель на массив элементов

public:

    Array(int capacity = 10)
        : capacity {capacity}
    {
        elements = new T[capacity];
    }

    Array(const T* elements, int count) : count {count}, capacity {count}, elements {new T[capacity]}
    {
        for (int i = 0; i < count; i++) {
            this->elements[i] = elements[i];
        }
    }

    // initializer_list (библиотечный класс) - список инициализаторов. Например - Array a({1, 2, 3, 4, 5});
    Array(std::initializer_list<T> list) : capacity {list.size()}, elements {new T[capacity]}
    {
        for (const auto& elem : list) {
            elements[size++] = elem;
        }
    }

    // копирующий конструктор
    Array(const Array& other)
        : count {other.count}, capacity {other.capacity}
    {
        elements = new T[capacity];
        for (int i = 0; i < count; i++) {
            elements[i] = other.elements[i];
        }
    }

    // заголовок перемещающего конструктора
    Array(Array&& other);

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

    // заголовок оператора перемещающего присваивания
    Array& operator= (Array&& other);

    // оператор индексирования
    T& operator[] (int index) {
        return elements[index];
    }

    // константный оператор индексирования
    const T& operator[] (int index) const {
        return elements[index];
    }

    // добавить элемент в конец массива
    void push_back(T elem) {
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
        T* memory = new T[newCapacity];

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


template<typename T>
Array<T>::Array(Array<T>&& other) {
    *this = other; // использую оператор перемещающего присваивания

    std::cout << "Array(Array&&)\n";
}

template<typename T>
Array<T>& Array<T>::operator= (Array<T>&& other) {
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
template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
    os << '[';

    int i;
    for (i = 0; i < array.size() - 1; i++) {
        os << array[i] << ", ";
    }

    if (array.size() > 0)
        os << array[i];

    return os << ']';
}

#endif // ARRAY_H_
