#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List list {1, 2, 3, 4, 5};
    cout << list << endl;

    List<int>::iterator it = list.begin();
    *it = 0;
    cout << list << endl;

    ++it; ++it;
    list.insert(it, -5555);
    cout << list << endl;

    list.remove(it);
    cout << list << endl;

    it = list.begin();
    list.remove(it);
    cout << list << endl;

    it = list.end();
    list.remove(it);
    cout << list << endl;

    List list2 = list;
    it = list2.begin();
    ++it;
    list2.insert(it, -123);
    cout << "list2: " << list2 << endl;
    cout << "list: " << list << endl;

    cout << "list2 size:";
    while (!list2.empty()) {
        cout << ' ' << list2.size();
        auto it = list2.begin();
        list2.remove(it);
    }
    cout << endl;

    list2 = list;
    it = list2.begin();
    list2.insert(it, -123);
    cout << "list2: " << list2 << endl;
    cout << "list: " << list << endl;

    List<double> list3 ({});
}
