#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 2;
    int* p1 = &a;
    int* p2 = p1;
    
    a = -1;
    cout << a << " " << *p1 << " " << *p2 << endl;
    cout << p1 << " " << p2 << endl;

    int** pp1 = &p1;
    p1 = &b;
    cout << endl << **pp1 << endl << endl;

    cout << ++*p1 << endl; // ++(*p1)
    cout << (*p1)++ << endl;
    cout << *p1 << endl;

    const int* cp = &a; // Const pointer
    cout << endl << *cp << endl;
    cp = p2;
    cout << *cp << endl;
    // ILLEGAL: *cp = 0;

    int* const pc = &b; // Pointer const
    *pc = 5;
    cout << *pc << endl;
    // ILLEGAL: pc = &a;

    return 0;
}
