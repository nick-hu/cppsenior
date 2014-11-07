#include <iostream>
#include <cmath>

using namespace std;

double simpson(double, double, unsigned int=50);

int main()
{
    simpson(0, 1, 100);

    return 0;
}

double simpson(double a, double b, unsigned int n)
{
    n = (n / 2) * 2;
    double dx = (b - a) / n;

    for (int i = 1; i <= n - 1; ++i) {
        cout << i << endl;
    }

    cout << dx << endl;

    return 0;
}
