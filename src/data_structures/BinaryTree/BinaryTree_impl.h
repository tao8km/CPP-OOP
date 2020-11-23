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
        Node* node = *current.pos;
        if (node->left == nullptr) {
            *current.pos = node->right == nullptr ? nullptr : node->right;
        } else if (node->right == nullptr) {
            *current.pos = node->left == nullptr ? nullptr : node->left;
        } else { // node has 2 children
            *current.pos = getMin(node->right);
        }

        delete node;
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

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::getMin(Node* root)
{
    Node* min = nullptr;
    while (root != nullptr) {
        min = root;
        root = root->left;
    }
    return min;
}
