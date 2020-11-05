#include "Fraction.h"

// здесь не нужно повторно указывать спецификатор friend. Данная функция по прежнему не является методом класса.
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    // т.к. мы объявили данную функцию дружественной для класса Fraction, то можем получить доступ
    // к закрытым полям numerator и denominator.
    os << fraction.numerator << '/' << fraction.denominator;
    return os;
}

// метод. Адрес левой дроби будет передан через указатель this.
// Т.к. это метод, то должен указать имя класса перед именем метода.
Fraction Fraction::operator+(const Fraction& right) const {
    int lcmValue = lcm(denominator, right.denominator);
    int leftMultiplier = lcmValue / denominator;
    int rightMultiplier = lcmValue / right.denominator;

    // создаем анонимный объект и возвращаем его из метода
    return Fraction (numerator * leftMultiplier + right.numerator * rightMultiplier, lcmValue);
}

// метод. Адрес левой дроби будет передан через указатель this.
// Т.к. это метод, то должен указать имя класса перед именем метода.
Fraction Fraction::operator-(const Fraction& right) const {
    int lcmValue = lcm(denominator, right.denominator);
    int leftMultiplier = lcmValue / denominator;
    int rightMultiplier = lcmValue / right.denominator;

    // создаем анонимный объект и возвращаем его из метода
    return Fraction(numerator * leftMultiplier - right.numerator * rightMultiplier, lcmValue);
}

// друг
Fraction operator*(const Fraction& left, const Fraction& right) {
    int numerator = left.numerator * right.numerator;
    int denominator = left.denominator * right.denominator;

    Fraction result(numerator, denominator);

    return result;
}

// не друг, не метод
Fraction operator/(const Fraction& left, const Fraction& right) {
    // перевернутая правая дробь
    Fraction reversedRight(right.getDenominator(), right.getNumerator());

    // заменил деление умножением на перевернутую правую дробь. Будет вызван перегруженный оператор умножения.
    return left * reversedRight;
}

Fraction& Fraction::operator+=(const Fraction& right) {
    *this = *this + right;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& right) {
    *this = *this - right;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& right) {
    *this = *this * right;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& right) {
    *this = *this / right;
    return *this;
}
