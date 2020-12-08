#include <iostream>
#include <cstring>
#include "Stack.h"

void checkSequence(const char* seq);
void printPosition(std::ostream& os, size_t pos);

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

char getPairBracket(char bracket)
{
    char pair = '\0';
    switch (bracket) {
    case '(':
        pair = ')';
        break;
    case '{':
        pair = '}';
        break;
    case '[':
        pair = ']';
        break;
    case ')':
        pair = '(';
        break;
    case '}':
        pair = '{';
        break;
    case ']':
        pair = '[';
        break;
    }

    return pair;
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
            if (brackets.empty() || getPairBracket(*it) != brackets.top()) {
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
    if (size_t pos = isCorrectSequence(seq); pos == std::strlen(seq) + 1) {
        std::cout << seq << " is correct\n";
    } else {
        std::cout << seq << " is not correct\n";
        printPosition(std::cout, pos);
    }
}
