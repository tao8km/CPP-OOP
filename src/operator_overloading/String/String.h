#pragma once

#include <iostream>
#include <cstring> // std::strlen, std::strncpy, std::strncat, std::strcmp

class String
{
    size_t size = 0; // тип size_t - беззнаковое целое, аналог unsigned int
    char* ptr = nullptr;

public:
    String(const char* str) : size {std::strlen(str) + 1}, ptr {new char[size]} // блок инициализации, выполняется до тела
    {
        // копируем символы из str в ptr, в количестве не более size
        std::strncpy(ptr, str, size);
    }

    // копирующий конструктор (copy)
    String(const String& other) : String(other.ptr) // делегируем работу по инициализации другому конструктору
    {
    }

    // перемещающий конструктор (move)
    String(String&& other) { // String&& - ссылка на временное значение (rvalue reference)
        // забираем ресурсы у другого объекта (обычно временного)
        ptr = other.ptr;
        size = other.size;

        // зануляем поля другого объекта, чтобы он при уничтожении не освободил уже наши ресурсы (память)
        other.ptr = nullptr;
        other.size = 0;

        std::cout << "String(String&&)\n";
    }

    ~String() {
        delete[] ptr;
    }

    size_t length() const { return size; }

    // -- перегруженные операторы --

    // оператор копирующего присваивания
    // возвращаемое значение - ссылка на текущий объект. Это необходимо для a = b = c = d (выполняются справа-налево)
    String& operator= (const String& other) {
        if (this != &other) { // проверка на самоприсваивание
            resize(other.size);
            std::strncpy(ptr, other.ptr, size);
        }

        return *this; // разыменовываем указатель на текущий объект, чтобы вернуть на него ссылку
    }

    // оператор перемещающего присваивания. Вызывается при присваивании временного объекта.
    // забираем ресурсы другого объекта (обычно временного)
    String& operator= (String&& other) { // other - временный объект
        if (this != &other) { // проверка на самоприсваивание
            delete[] ptr;
            // скопировали себе
            ptr = other.ptr;
            size = other.size;

            // ему занулили
            other.ptr = nullptr;
            other.size = 0;
        }

        std::cout << "operator=(String&&)\n";

        return *this; // разыменовываем указатель на текущий объект, чтобы вернуть на него ссылку
    }

    String& operator+= (const String& other) {
        if (this != &other) { // проверка на самоприсваивание
            resize(size + other.size - 1); // -1, т.к. в size учитывается '\0' в обеих строках, но нам нужен только один в выходной строке
            // конкатенируем строки (объединяем)
            std::strncat(ptr, other.ptr, other.size);
        }

        return *this;
    }

    // дружественные функции
    friend std::ostream& operator<< (std::ostream& os, const String& str);

    // оператор преобразования из String к типу const char *
    operator const char* () const {
        return ptr;
    }

    char& operator[] (int index) {
        return ptr[index];
    }

    const char& operator[] (int index) const { // перегрузка на основании константности метода. Будет вызван для константного объекта.
        return ptr[index];
    }

private:
    /**
     * При необходимости выделяет память нового размера, копирует в нее содержимое строки, освобождает старую память.
     */
    void resize(size_t newSize) {
        if (size != newSize) {
            char* memory = new char[newSize];
            std::strncpy(memory, ptr, newSize);

            delete[] ptr;
            ptr = memory;
            size = newSize;
        }
    }
};


// глобальные функции
String operator+(String left, const String& right);
bool operator== (const String& left, const String& right);
bool operator!= (const String& left, const String& right);
bool operator< (const String& left, const String& right);

