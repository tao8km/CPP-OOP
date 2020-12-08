#include <iostream>
#include <utility> // swap

template<typename T>
List<T>::List()
{
    head = tail = new Node {0, nullptr, nullptr};
}

template<typename T>
List<T>::List(std::initializer_list<T> values)
{
    Node** current = &head;

    for (const auto& v : values) {
        *current = new Node {v, tail, nullptr};
        if (tail != nullptr)
            tail->next = *current;

        tail = *current;
        current = &((*current)->next);

        ++count;
    }

    Node* last = new Node {0, tail, nullptr};
    if (tail != nullptr)
        tail->next = last;
    tail = last;
    if (head == nullptr)
        head = tail;
}

template<typename T>
List<T>::List(const List<T>& other)
{
    insert(other.begin(), other.end());

    Node* last = new Node {0, tail, nullptr};
    if (tail != nullptr)
        tail->next = last;
    tail = last;
}

template<typename T>
List<T>::List(List<T>&& other)
{
    head = other.head;
    tail = other.tail;
    count = other.count;

    other.head = other.tail = nullptr;
    other.count = 0;
}

template<typename T>
List<T>::~List()
{
    Node* current = head;
    while (head != nullptr && head != tail) {
        head = head->next;
        delete current;
        current = head;
    }

    delete tail;
    head = tail = nullptr;
    count = 0;
}

template<typename T>
List<T>& List<T>::operator= (List<T> other)
{
    if (this != &other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(count, other.count);
    }

    return *this;
}

template<typename T>
List<T>& List<T>::operator= (List<T>&& other)
{
    if (this != &other) {
        this->~List();

        head = other.head;
        tail = other.tail;
        count = other.count;

        other.head = other.tail = nullptr;
        other.count = 0;
    }

    return *this;
}

/**
 * Insert value before iterator position.
 */
template<typename T>
void List<T>::insert(const_iterator it, T value)
{
    Node* prev = it->prev;
    Node* current = it.current();
    Node* node = new Node {value, prev, current};
    if (prev != nullptr)
        prev->next = node;
    current->prev = node;
    ++count;

    if (current == head)
        head = node;
}

template<typename T>
void List<T>::insert(const_iterator begin, const_iterator end)
{
    Node* first = nullptr;
    Node** current = (head == nullptr ? &head : &first);
    Node* prev = nullptr;

    for (auto it = begin; it != end; ++it) {
        *current = new Node {*it, prev, nullptr};
        if (prev != nullptr)
            prev->next = *current;
        prev = *current;
        current = &((*current)->next);

        ++count;
    }

    if (first != nullptr) {
        prev->next = head;
        head->prev = prev;
        head = first;
    }

    if (tail == nullptr) {
        tail = prev;
    }
}

template<typename T>
void List<T>::remove(iterator& it)
{
    Node* current = it.current();
    if (current == tail)
        return;

    Node* prev = it->prev;
    Node* next = it->next;
    if (prev != nullptr)
        prev->next = next;
    if (next != nullptr)
        next->prev = prev;

    if (current == head)
        head = next;
    ++it; // move iterator to next node
    delete current;
    --count;
}

template<typename T>
auto List<T>::find(T value) const -> iterator
{
    auto it = begin();
    while (it != end()) {
        if (*it == value)
            return it;
        ++it;
    }

    return it;
}

template<typename T>
std::ostream& operator<< (std::ostream& os, const List<T>& list)
{
    for (const auto& elem : list) {
        os << elem << ' ';
    }
    return os;
}
