#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long a, b, lcm;

    cout << "Enter an integer: ";
    cin >> a;
    cout << "Enter an integer: ";
    cin >> b;

    a = abs(a); b = abs(b);
    if (a == 0 || b == 0) {
        cout << "The GCD is " << (a > b ? a : b) << endl;
    }
    else {
        lcm = 0;

        do {
            lcm += a;
        } while (lcm % b != 0);

        cout << "The GCD is " << (a*b)/lcm << endl;
    }

    return 0;
}
