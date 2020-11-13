#ifndef SHAREDPTR_H_
#define SHAREDPTR_H_

class RefCounter
{
    int count = 0;

public:
    void increment() { count++; }
    void decrement() { count--; }
    int getCount() const { return count; }
};

template<typename T>
class SharedPtr
{
    T* ptr;
    RefCounter* counter = nullptr;

public:
    SharedPtr(T* ptr) : ptr {ptr}, counter {new RefCounter()}
    {
    }

    SharedPtr(const SharedPtr& other)
        : ptr {other.ptr}, counter {other.counter}
    {
        counter->increment();
    }

    SharedPtr(SharedPtr&& other)
        : ptr {other.ptr}, counter {other.counter}
    {
        other.ptr = other.counter = nullptr;
    }

    ~SharedPtr()
    {
        if (counter->getCount() == 0) {
            delete ptr;
            delete counter;
        } else {
            counter->decrement();
        }
    }

    SharedPtr& operator= (const SharedPtr& other) {
        if (this != &other && ptr != other.ptr) {
            this->~SharedPtr(); // call destructor
            ptr = other.ptr;
            counter = other.counter;
            counter->increment();
        }

        return *this;
    }

    SharedPtr& operator= (SharedPtr&& other) {
        if (this != &other && ptr != other.ptr) {
            this->~SharedPtr();
            ptr = other.ptr;
            counter = other.counter;
            other.ptr = other.counter = nullptr;
        }

        return *this;
    }

    operator T* () {
        return ptr;
    }

    operator const T* () const {
        return ptr;
    }

    T& operator* () {
        return *ptr;
    }

    const T& operator* () const {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    const T* operator->() const {
        return ptr;
    }
};


#endif /* SHAREDPTR_H_ */
