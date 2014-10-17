#include <iostream>
#include <cmath>

using namespace std;

double quadratic(double, double, double, double &, double &);

int main()
{
    double a, b, c;
    double x1, x2, d;

    cin >> a >> b >> c;
    d = quadratic(a, b, c, x1, x2);

    if (d > 0) {
        cout << "x = " << x1 << ", " << x2 << endl;
    }
    else if (d == 0) {
        cout << "x = " << x1 << endl;
    }
    else {
        cout << "No real roots! :(" << endl;
    }

    return 0;
}

double quadratic(double a, double b, double c, double &x1, double &x2)
{
    double d = pow(b, 2) - 4*a*c;

    if (d >= 0) {
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
    }

    return d;
}
