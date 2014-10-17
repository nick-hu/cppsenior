#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

double quadratic(double, double, double, complex<double> &, complex<double> &);

int main()
{
    double a, b, c, d;
    complex<double> x1, x2;

    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Infinite solutions" << endl;
            }
            else {
                cout << "No solutions" << endl;
            }
        }
        else {
            cout << "x = " << -c/b << endl;
        }
    }

    else {
        d = quadratic(a, b, c, x1, x2);

        if (d > 0) {
            cout << "x = " << real(x1) << ", " << real(x2) << endl;
        }
        else if (d == 0) {
            cout << "x = " << real(x1) << endl;
        }
        else {
            cout << "x = " << real(x1) << " + " << imag(x1) << "i, ";
            cout << real(x2) << " + " << imag(x2) << "i" << endl;
        }
    }

    return 0;
}

double quadratic(double a, double b, double c, complex<double> &x1, complex<double> &x2)
{
    complex<double> d = pow(b, 2) - 4*a*c;

    x1 = (-b + sqrt(d))/(2*a);
    x2 = (-b - sqrt(d))/(2*a);

    return real(d);
}
