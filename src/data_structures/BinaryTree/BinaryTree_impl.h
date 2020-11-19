template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::insert(const T& value)
{
    iterator pos = find(value);
    if (*pos == nullptr) {
        *pos = new Node {value};
        ++count;
    }

    return pos;
}

template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::find(const T& value)
{
    iterator current = &root;

    while (*current != nullptr) {
        if (value < (*current)->value)
            current = &(*current)->left;
        else if (value > (*current)->value)
            current = &(*current)->right;
        else
            break; // found value
    }

    return current;
}
