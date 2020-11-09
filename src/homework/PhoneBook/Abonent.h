#pragma once
#include <iostream> // std::ostream
#include <cstring> // std::strlen, std::strcpy, std::memset

const int cityNumberLength = 7;
const int cellNumberLength = 11;
const int additionalInfoLength  = 256;


/**
 * Информация об абоненте
 */
class Abonent
{
    char* name = nullptr;
    char homeNumber[cityNumberLength + 1];
    char workNumber[cityNumberLength + 1];
    char cellNumber[cellNumberLength + 1];
    char info[additionalInfoLength + 1];

public:
    // = {} это аргумент по умолчанию, для символьных массивов означает заполнение нулями, если не будет передан аргумент
    Abonent(const char *name, const char homeNumber[] = {}, const char workNumber[] = {}, const char cellNumber[] = {},
            const char info[] = {});

    Abonent(const Abonent& other);
    Abonent(Abonent&& other);

    ~Abonent() {
        delete[] name;
    }

    Abonent& operator= (const Abonent& other);
    Abonent& operator= (Abonent&& other);

    // важно геттеры объявить константными методами, чтобы их можно было вызывать для константного объекта
    const char* getName() const { return name; }
    const char* getHomeNumber() const { return homeNumber; }
    const char* getWorkNumber() const { return workNumber; }
    const char* getCellNumber() const { return cellNumber; }
    const char* getAdditionalInfo() const { return info; }
};

std::ostream& operator<< (std::ostream& os, const Abonent& abonent);
