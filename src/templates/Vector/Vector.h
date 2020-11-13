#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <initializer_list>


template<typename T>
class Vector
{
    int count = 0; // количество элементов (сколько элементов уже помещено)
    int capacity = 0; // объем выделенной памяти (сколько можно поместить элементов)
    T *elements = nullptr; // указатель на массив элементов

public:

    Vector(int capacity = 10)
        : capacity {capacity}
    {
        elements = new T[capacity];
    }

    Vector(const T* elements, int count) : count {count}, capacity {count}, elements {new T[capacity]}
    {
        for (int i = 0; i < count; i++) {
            this->elements[i] = elements[i];
        }
    }

    // initializer_list (библиотечный класс) - список инициализаторов. Например - Vector a({1, 2, 3, 4, 5});
    Vector(std::initializer_list<T> list) : capacity {list.size()}, elements {new T[capacity]}
    {
        for (const auto& elem : list) {
            elements[size++] = elem;
        }
    }

    // копирующий конструктор
    Vector(const Vector& other)
        : count {other.count}, capacity {other.capacity}
    {
        elements = new T[capacity];
        for (int i = 0; i < count; i++) {
            elements[i] = other.elements[i];
        }
    }

    // заголовок перемещающего конструктора
    Vector(Vector&& other);

    ~Vector() {
        delete[] elements;
    }

    // оператор присваивания
    Vector& operator=(const Vector& other) {
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
    Vector& operator= (Vector&& other);

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
Vector<T>::Vector(Vector<T>&& other) {
    *this = std::move(other); // использую оператор перемещающего присваивания

    std::cout << "Vector(Vector&&)\n";
}

template<typename T>
Vector<T>& Vector<T>::operator= (Vector<T>&& other) {
    if (this != &other) {
        count = other.count;
        capacity = other.capacity;
        elements = other.elements;

        other.count = other.capacity = 0;
        other.elements = nullptr;
    }

    std::cout << "operator= (Vector&&)\n";

    return *this;
}

/**
 * Свободная функция (не метод класса Vector), перегружающая оператор << для Vector
 * Выводит элементы Vector в поток os.
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    os << '[';

    int i;
    for (i = 0; i < vector.size() - 1; i++) {
        os << vector[i] << ", ";
    }

    if (vector.size() > 0)
        os << vector[i];

    return os << ']';
}

#endif // VECTOR_H_
