#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"
using namespace std;

int main()
{
    srand(time(NULL));

    BinaryTree<int> ints;

    for (int i = 0; i < 10; i++) {
        int n = rand() % 100;
        ints.insert(n);
    }

    ints.printInOrder(cout);

    int n;
    cout << "Enter number to search in tree: ";
    cin >> n;
    int replace;
    cout << "Enter replacement: ";
    cin >> replace;

    auto it = ints.find(n);
    (*it)->value = replace;
    ints.printInOrder(cout);
}
