#include <iostream>

using namespace std;

unsigned long factorial(unsigned long);

int main()
{
    unsigned long n;

    cin >> n;
    cout << n << "! = " << factorial(n) << endl;

    return 0;
}

unsigned long factorial(unsigned long x)
{
    if (x == 0) return 1;
    return x * factorial(x-1);
}
