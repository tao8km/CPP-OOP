template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::insert(const T& value)
{
    iterator current = find(value);
    if (*current.pos == nullptr) {
        *current.pos = new Node {value};
        ++count;
    }

    return current;
}

template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::remove(const T& value)
{
    iterator current = find(value);
    if (*current.pos != nullptr) {
        // TODO
    }

    return current;
}

template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::find(const T& value)
{
    iterator current = begin();

    while (*current.pos != nullptr) {
        if (value < current->value)
            current.pos = &current->left;
        else if (value > current->value)
            current.pos = &current->right;
        else
            break; // found value
    }

    return current;
}
