#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept> // domain_error
#include <utility> // swap
#include "List.h"


template<typename T>
class Queue
{
    List<T> elems;

public:
    // поместить в очередь
    void enqueue(T value) {
        elems.insert(elems.end(), value);
    }

    // извлечь из очереди
    T dequeue() {
        if (elems.size() == 0) {
            throw std::domain_error("Queue is empty!");
        }

        auto head = elems.begin();
        T value = *head;
        elems.remove(head);

        return value;
    }

    int size() const { return elems.size(); }
    bool empty() const { return elems.empty(); }
};


#endif /* QUEUE_H_ */
