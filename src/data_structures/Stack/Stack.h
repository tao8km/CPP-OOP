#ifndef STACK_H_
#define STACK_H_

#include <stdexcept> // domain_error
#include <utility> // swap
#include "List.h"


template<typename T>
class Stack
{
    List<T> elems;

public:
    void push(T value) {
        elems.insert(elems.end(), value);
    }

    T pop() {
        if (elems.size() == 0) {
            throw std::domain_error("Stack is empty!");
        }

        auto top = elems.end();
        --top;
        T value = *top;
        elems.remove(top);

        return value;
    }

    int size() const { return elems.size(); }
    bool empty() const { return elems.empty(); }
};


#endif /* STACK_H_ */
