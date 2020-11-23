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

    auto it = ints.find(n);
    if (it != ints.end()) {
        int replace;
        cout << "Enter replacement: ";
        cin >> replace;
        it->value = replace;
        ints.printInOrder(cout);
    } else {
        cout << n << " not found in tree.\n";
    }

    cout << "Enter number to remove from tree: ";
    cin >> n;
    it = ints.remove(n);
    if (it != ints.end())
        ints.printInOrder(cout);
    else
        cout << n << " not found in tree.\n";
}
