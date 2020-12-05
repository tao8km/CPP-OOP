#ifndef STACK_H_
#define STACK_H_

#include <stdexcept> // underflow_error
#include "List.h"


template<typename E>
class Stack
{
    List<E> elems;

public:
    Stack<E> operator+= (const Stack<E>& other);

    void push(E value) {
        elems.insert(elems.end(), value);
    }

    E pop() {
        if (elems.size() == 0) {
            throw std::underflow_error("Stack is empty!");
        }

        auto top = elems.end();
        --top;
        E value = *top;
        elems.remove(top);

        return value;
    }

    int size() const { return elems.size(); }
    bool empty() const { return elems.empty(); }

    template<typename T>
    friend Stack<T> operator* (const Stack<T>& lhs, const Stack<T>& rhs);
};

#include "Stack_impl.h"


#endif /* STACK_H_ */
