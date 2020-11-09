#include "Abonent.h"
#include <utility> // std::move

// здесь не указываю аргументы по умолчанию - они указаны в заголовке класса и в определении не указываются
Abonent::Abonent(const char *name, const char homeNumber[], const char workNumber[], const char cellNumber[],
        const char info[])
    : name {new char[strlen(name) + 1]}
{
    std::strcpy(this->name, name);
    std::strncpy(this->homeNumber, homeNumber, cityNumberLength);
    std::strncpy(this->workNumber, workNumber, cityNumberLength);
    std::strncpy(this->cellNumber, cellNumber, cellNumberLength);
    std::strncpy(this->info, info, additionalInfoLength);

    this->homeNumber[cityNumberLength] = this->workNumber[cityNumberLength] = this->cellNumber[cellNumberLength] =
            this->info[additionalInfoLength] = '\0'; // гарантирую наличие нулевого терминала в конце строк
}

Abonent::Abonent(const Abonent& other)
    : Abonent(other.name, other.homeNumber, other.workNumber, other.cellNumber, other.info)
{
}

Abonent::Abonent(Abonent&& other)
    : Abonent(other) // вызвал конструктор копирования
{
    // обнуляем поля другого объекта, т.к. уже скопировали их себе
    other.name = nullptr;

    // заполняем массивы нулевыми терминалами
    std::memset(other.homeNumber, '\0', cityNumberLength);
    std::memset(other.workNumber, '\0', cityNumberLength);
    std::memset(other.cellNumber, '\0', cellNumberLength);
    std::memset(other.info, '\0', additionalInfoLength);
}

Abonent& Abonent::operator= (const Abonent& other) {
    if (this != &other) {
        Abonent tempObject = other; // создал временную копию другого объекта с помощью конструктора копирования
        *this = std::move(tempObject); // вызвал оператор перемещающего присваивания и забрал себе ресурсы копии
    }

    return *this;
}

Abonent& Abonent::operator= (Abonent&& other) {
    if (this != &other) {
        name = other.name;

        std::strncpy(homeNumber, other.homeNumber, cityNumberLength);
        std::strncpy(workNumber, other.workNumber, cityNumberLength);
        std::strncpy(cellNumber, other.cellNumber, cellNumberLength);
        std::strncpy(info, other.info, additionalInfoLength);

        other.name = nullptr;
        // заполняем массивы нулевыми терминалами
        std::memset(other.homeNumber, '\0', cityNumberLength);
        std::memset(other.workNumber, '\0', cityNumberLength);
        std::memset(other.cellNumber, '\0', cellNumberLength);
        std::memset(other.info, '\0', additionalInfoLength);
    }

    return *this;
}

std::ostream& operator<< (std::ostream& os, const Abonent& abonent) {
    os << "Name:       " << abonent.getName() << '\n';
    os << "Home phone: " << abonent.getHomeNumber() << '\n';
    os << "Work phone: " << abonent.getWorkNumber() << '\n';
    os << "Cell phone: " << abonent.getCellNumber() << '\n';
    os << "Info:       " << abonent.getAdditionalInfo() << '\n';
    return os;
}
