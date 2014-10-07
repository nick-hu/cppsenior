#include <iostream>

using namespace std;

int main()
{
    double x, t, n;
    t = 0; n = -1;

    do {
        cout << "Enter a number: ";
        cin >> x;
        t += x; n += 1;
    } while (x != 0);

    if (n != 0)
        cout << "Average: " << t/n << endl;
    else
        cout << "No numbers entered" << endl;

    return 0;
}
