#include <iostream>
#include <cmath>

using namespace std;

double integrate(double, double, double=1E-5);
double simpson(double, double, unsigned long);
double f(double);

int main()
{
    cout << integrate(0, 1) << endl;

    return 0;
}

double integrate(double a, double b, double tol)
{
    a += 1E-10;
    b -= 1E-10;

    double ans, curr = 0;
    unsigned long next_n = 1E3;

    do {
        ans = curr;
        curr = simpson(a, b, next_n);
        next_n *= 10;
    } while (abs(curr - ans) > tol);

    return curr;
}

double simpson(double a, double b, unsigned long n)
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
    return log(x);
}

