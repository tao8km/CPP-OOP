#ifndef STACK_H_
#define STACK_H_

#include "List.h"


template<typename T>
class Stack
{
    List<T> elems;
    typename List<T>::iterator top;
    int count = 0;

public:
    Stack() : top {elems.end()}
    {
    }

    void push(T value) {
        elems.insert(top, value);
        ++count;
    }

    T pop() {
        // TODO check count
        --top;
        T value = *top;
        elems.remove(top);
        --count;

        return value;
    }

    int size() const { return elems.size(); }
    bool empty() const { return elems.empty(); }
};


#endif /* STACK_H_ */
