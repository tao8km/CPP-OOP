#include <iostream>
#include <cstring>
#include "Stack.h"

void checkSequence(const char* seq);

int main()
{
    const char* correctSequence = "({x-y-z}*[x+2y]-(z+4x))";
    const char* incorrectSequence = "([x-y-z}*[x+2y)-{z+4x)]";
    const char* incorrectOpened = "([x-y-z]*[x+2y]-{z+4x})[34";
    const char* incorrectClosed = "}([x-y-z]*[x+2y]-{z+4x})";

    checkSequence(correctSequence);
    checkSequence(incorrectSequence);
    checkSequence(incorrectOpened);
    checkSequence(incorrectClosed);
}

size_t isCorrectSequence(const char* begin)
{
    static const char* openBrackets = "({[";
    static const char* closeBrackets = ")}]";

    Stack<char> brackets;

    for (const char* cur = begin; *cur != '\0'; ++cur) {
        if (std::strchr(openBrackets, *cur)) {
            brackets.push(*cur);
        } else if (const char* it = std::strchr(closeBrackets, *cur)) {
            char openBracket = openBrackets[it - closeBrackets];
            if (brackets.empty() || openBracket != brackets.top()) {
                return cur - begin;
            }
            brackets.pop();
        }
    }

    if (!brackets.empty()) {
        const char* it = std::strrchr(begin, brackets.top());
        return it - begin;
    }

    return std::strlen(begin) + 1;
}

void printPosition(std::ostream& os, size_t pos)
{
    while (pos--) {
        os << '-';
    }
    os << '^' << '\n';
}

void checkSequence(const char* seq)
{
    std::cout << seq;
    if (size_t pos = isCorrectSequence(seq); pos == std::strlen(seq) + 1) {
        std::cout << "\t is correct\n";
    } else {
        std::cout << "\t is not correct\n";
        printPosition(std::cout, pos);
    }
}
