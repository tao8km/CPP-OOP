#ifndef UNIQUEPTR_H_
#define UNIQUEPTR_H_


template<typename T>
class UniquePtr
{
    T* ptr;

public:
    UniquePtr(T* ptr) : ptr {ptr}
    {} // empty constructor body

    UniquePtr(const UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other) : ptr {other.ptr}
    {
        other.ptr = nullptr;
    }

    ~UniquePtr() {
        delete ptr;
    }

    UniquePtr& operator= (const UniquePtr& other) = delete;

    UniquePtr& operator= (UniquePtr&& other)
    {
        if (this != &other) {
            this->~UniquePtr();
            ptr = other.ptr;
            other.ptr = nullptr;
        }

        return *this;
    }
};


#endif /* UNIQUEPTR_H_ */
