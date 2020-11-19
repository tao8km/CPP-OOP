#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>

template<typename T>
class BinaryTree
{
    struct Node;

    Node* root = nullptr;
    int count = 0;

public:
    using iterator = Node**;
    // void insert(const_iterator pos, T value);

    ~BinaryTree() {
        clean(root);
    }

    void clean(Node* node) {
        if (node != nullptr) {
            clean(node->left);
            Node* right = node->right;
            delete node;
            clean(right);
        }
    }

    iterator insert(const T& value);
    iterator find(const T& value);

    void printInOrder(std::ostream& os, const typename BinaryTree<T>::Node* node) {
        if (node != nullptr) {
            printInOrder(os, node->left);
            os << node->value << ' ';
            printInOrder(os, node->right);
        }
    }

    void printInOrder(std::ostream& os) {
        printInOrder(os, root);
        os << '\n';
    }

private:
    struct Node
    {
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
    };
};

#include "BinaryTree_impl.h"

#endif /* BINARYTREE_H_ */
