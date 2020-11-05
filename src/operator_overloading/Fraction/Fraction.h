#pragma once

#include <algorithm> // std::copy
#include <iostream> // std::ostream


class Fraction
{
    int numerator; // числитель
    int denominator; // знаменатель

public:
    Fraction(int num, int denom)
        : numerator {num}, denominator {denom}
    {}

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // указателей, либо других ресурсов в классе нет - поэтому можно не создавать конструктор копирования,
    // деструктор, операцию присваивания, т.к. компилятор нам их создаст и они будут выполнять побитовое
    // копирование, что нас устраивает в данном случае.

    // дружественная для класса функция. Имеет доступ к закрытым секциям private и protected.
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

    // оператор вызова функции. Первые () - название оператора, во вторых () указываются параметры метода.
    // Тип возвращаемого значения и список параметров метода могут быть любыми. Можно перегружать, указывая разные наборы параметров.
    void operator()() {
        // делаем что угодно, например сокращаем дробь
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }


    // -- Перегруженные арифметические операторы --

    // метод. Адрес левой дроби будет передан через указатель this.
    Fraction operator+(const Fraction& right) const;

    // метод. Адрес левой дроби будет передан через указатель this.
    Fraction operator-(const Fraction& right) const;

    // друг
    friend Fraction operator*(const Fraction& left, const Fraction& right);


    // -- операции с присваиванием -- 

    Fraction& operator+=(const Fraction& right);

    Fraction& operator-=(const Fraction& right);

    Fraction& operator*=(const Fraction& right);

    Fraction& operator/=(const Fraction& right);

    // -- инкременты, декременты --

    // префиксный
    Fraction& operator++() {
        numerator++;
        return *this;
    }

    // постфиксный
    Fraction operator++(int) {
        Fraction oldValue(*this);
        numerator++;
        return oldValue;
    }

    // префиксный
    Fraction& operator--() {
        numerator--;
        return *this;
    }

    // постфиксный
    Fraction operator--(int) {
        Fraction oldValue(*this);
        numerator--;
        return oldValue;
    }

private:
    // нахождение НОД (наибольший общий делитель)
    static int gcd(int a, int b) {
        if (a < b) {
            std::swap(a, b);
        }

        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }

    // нахождение НОК (наименьшее общее кратное)
    static int lcm(int a, int b) {
        int result = (a * b) / gcd(a, b);

        return result;
    }
};


// не друг, не метод.
Fraction operator/(const Fraction& left, const Fraction& right);
