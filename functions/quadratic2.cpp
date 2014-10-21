#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

void quadratic(double, double, double, complex<double> &, complex<double> &);
void complexprint(complex<double>);

int main()
{
    double a, b, c;
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
        quadratic(a, b, c, x1, x2);

        if (x1 != x2) {
            cout << "x = ";
            complexprint(x1);
            cout << ", ";
            complexprint(x2);
        }
        else {
            cout << "x = ";
            complexprint(x1);
        }
        cout << endl;
    }

    return 0;
}

void quadratic(double a, double b, double c,
               complex<double> &x1, complex<double> &x2)
{
    complex<double> d = pow(b, 2) - 4*a*c;

    x1 = (-b + sqrt(d))/(2*a);
    x2 = (-b - sqrt(d))/(2*a);
}

void complexprint(complex<double> c)
{
    double a = real(c), b = imag(c);

    if (a != 0 || (a == 0 && b == 0)) {
        cout << a;
    }

    if (b != 0) {
        if (b > 0 && a != 0) {
            cout << "+";
        }
        if (b < 0) {
            cout << "-";
        }
        if (abs(b) == 1) {
            cout << "i";
        }
        else {
            cout << abs(b) << "i";
        }
    }
}
