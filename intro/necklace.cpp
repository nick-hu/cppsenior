#include <iostream>

using namespace std;

int main()
{
    short n1, n2, n3, o1, o2, step = 0;

    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;

    o1 = n1;
    o2 = n2;
    cout << n1 << " " << n2 << " ";

    do {
        n3 = (n1 + n2) % 10;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;

        ++step;
    } while ((n1 != o1) || (n2 != o2));

    cout << endl << "Your numbers required " << step << " steps.";

    return 0;
}
