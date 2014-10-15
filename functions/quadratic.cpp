#include <iostream>
#include <cmath>

using namespace std;

void quadratic(double, double, double, double &, double &, double &);

int main()
{
    double a, b, c;
    double x1, x2, d;

    cin >> a;
    cin >> b;
    cin >> c;
    quadratic(a, b, c, x1, x2, d);

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

void quadratic(double a, double b, double c, double &x1, double &x2, double &d)
{
    d = pow(b, 2) - 4*a*c;

    if (d >= 0) {
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
    }
}
