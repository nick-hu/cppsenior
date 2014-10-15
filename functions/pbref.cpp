#include <iostream>

using namespace std;

int foo(int &);

int main()
{
    int z = 1;

    cout << foo(z) << endl;
    cout << z;

    return 0;
}

int foo(int &x) {
    x += 1;
    return x;
}
