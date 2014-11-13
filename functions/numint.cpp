#include <iostream>
#include <cmath>

using namespace std;

double simpson(double, double, unsigned int=50);
double f(double);

int main()
{
    cout << simpson(1E-8, 1, 1E8) << endl;

    return 0;
}

double simpson(double a, double b, unsigned int n)
{
    if (n < 2)
        return 0;

    n = (n / 2) * 2;
    double dx = (b - a)/n, tot = 0;

    for (unsigned int i = 1; i < n/2; ++i) {
        tot += 2 * f(a + (2*i)*dx) + 4 * f(a + (2*i+1)*dx);
    }

    return (dx/3) * (f(a) + 4*f(a + dx) + tot + f(b));
}

double f(double x)
{
    return 1/(sqrt(x));
}
