#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long a, b, c;

    cout << "Enter an integer: ";
    cin >> a;
    cout << "Enter an integer: ";
    cin >> b;

    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }

    cout << "The GCD is " << abs(a) << endl;
}
