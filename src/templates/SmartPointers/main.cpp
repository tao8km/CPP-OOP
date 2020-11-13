#include <iostream>
#include "SharedPtr.h"
#include "UniquePtr.h"
using namespace std;

int main()
{
    SharedPtr p(new int(123));

    cout << *p << endl;
    *p = 456;

    SharedPtr s = p;
    cout << *s << endl;

    *s = 744;
    cout << *p << endl;

    SharedPtr t(new int(789));
    t = s;
    cout << *t << endl;

    *t = 333;
    cout << *p << endl;

    SharedPtr a(new double(94.567));
    SharedPtr b = a;

    SharedPtr<double> pointers[] {
        SharedPtr(a), SharedPtr(a), SharedPtr(a), SharedPtr(a), SharedPtr(a), SharedPtr(a), SharedPtr(a)
    };

    UniquePtr u(new float(23.45));
    UniquePtr v = std::move(u);
    UniquePtr w (new float(44.56));
    w = std::move(v);
}
