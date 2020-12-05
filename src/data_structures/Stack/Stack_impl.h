template<typename E>
Stack<E> Stack<E>::operator+= (const Stack<E>& other)
{
    if (this != &other) {
        for (const auto& e : other.elems) {
            push(e);
        }
    }

    return *this;
}

template<typename E>
Stack<E> operator+ (const Stack<E>& lhs, const Stack<E>& rhs)
{
    return Stack<E>(lhs) += rhs;
}

template<typename E>
Stack<E> operator* (const Stack<E>& lhs, const Stack<E>& rhs)
{
    Stack<E> result;

    for (const auto& lhsElem : lhs.elems) {
        for (const auto& rhsElem : rhs.elems) {
            if (lhsElem == rhsElem) {
                result.push(lhsElem);
            }
        }
    }

    return result;
}
