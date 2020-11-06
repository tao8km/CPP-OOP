#include "Student.h"

/*
 * Вычисляет среднюю оценку.
 */
double Student::operator() () const { // добавил имя класса Student, т.к. это метод
    int count = marks.size();
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }

    return (double) sum / count;
}

bool Student::operator< (const Student& other) const {
    return name < other.name; // используем оператор < для String
}

// дружественная функция
std::ostream& operator<< (std::ostream& os, const Student& student) {
    // сначала выполняются операции вывода в поток os, затем возвращается ссылка на поток
    return os << student.name << '\t' << student.marks;
}
