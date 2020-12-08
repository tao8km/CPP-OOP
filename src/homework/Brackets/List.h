#ifndef LIST_H_
#define LIST_H_

#include <initializer_list>


template<typename T>
class List
{
    struct Node; // forward declaration
    class Iterator; // forward declaration

    Node* head = nullptr; // points to first element in list
    Node* tail = nullptr; // points to last element in list
    size_t count = 0; // number of elements in list

public:
    using iterator = Iterator;
    using const_iterator = const Iterator;
    using value_type = T;

    List();
    List(std::initializer_list<T> values);
    List(const List& other);
    List(List&& other);

    ~List();

    List& operator= (List other);
    List& operator= (List&& other);

    void insert(const_iterator it, T value);
    void insert(const_iterator begin, const_iterator end);
    void remove(iterator& it);
    iterator find(T value) const;

    iterator begin() { return iterator(this, head); }
    iterator end() { return iterator(this, tail); }
    const_iterator begin() const { return const_iterator(this, head); }
    const_iterator end() const { return const_iterator(this, tail); }

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

private:
    struct Node
    {
        T value;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    class Iterator
    {
        const List<T>* list = nullptr;
        Node* pos = nullptr;

        Node* current() const { return pos; }

        Node* operator-> () { return pos; }
        const Node* operator-> () const { return pos; }

    public:
        Iterator(const List<T>* list, Node* pos) : list {list}, pos {pos}
        {}

        T& operator* () { return pos->value; }
        const T& operator* () const { return pos->value; }

        Iterator& operator++ () { // prefix increment
            pos = pos->next;
            return *this;
        }

        Iterator operator++ (int) { // postfix increment
            Iterator prev = *this;
            ++(*this);
            return prev;
        }

        Iterator& operator-- () { // prefix decrement
            pos = pos->prev;
            return *this;
        }

        Iterator operator-- (int) { // postfix decrement
            Iterator prev = *this;
            --(*this);
            return prev;
        }

        friend bool operator== (iterator lhs, iterator rhs) {
            return lhs.list == rhs.list && lhs.pos == rhs.pos;
        }

        friend bool operator!= (iterator lhs, iterator rhs) {
            return !(lhs == rhs);
        }

        friend List<T>; // friend class
    }; // class Iterator
}; // class List<T>


#include "List_impl.h" // include implementation of template functions and methods


#endif /* LIST_H_ */
