#include <iostream>

using namespace std;

int main()
{
    unsigned long a, b, lcm;

    cout << "Enter an integer: ";
    cin >> a;
    cout << "Enter an integer: ";
    cin >> b;

    if (a == 0 && b == 0) {
        cout << "The GCD is 0" << endl;
    }
    else {
        lcm = 0;

        do {
            lcm += a;
        } while (lcm % b != 0);

        cout << lcm << endl;
        cout << "The GCD is " << (a*b)/lcm << endl;
    }

    return 0;
}
