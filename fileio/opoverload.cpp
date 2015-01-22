#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Vector {
    Vector();
    // Vector(string);
    Vector(vector <double> v);

    vector <double> vect;
};

Vector::Vector() {}

Vector::Vector(vector <double> v) {
    vect = v;
}

Vector operator+ (const Vector &a, const Vector &b) {
    Vector c;

    if (a.vect.size() == b.vect.size()) {
        for (unsigned int i = 0; i < a.vect.size(); ++i) {
            c.vect.push_back(a.vect.at(i) + b.vect.at(i));
        }
    }

    return c;
}

Vector operator* (const double &k, const Vector &v) {
    Vector c;

    for (unsigned int i = 0; i < v.vect.size(); ++i) {
        c.vect.push_back(k * v.vect.at(i));
    }

    return c;
}

Vector operator* (const Vector &v, const double &k) {
    Vector c;

    for (unsigned int i = 0; i < v.vect.size(); ++i) {
        c.vect.push_back(k * v.vect.at(i));
    }

    return c;
}

Vector operator- (const Vector &v) {
    return -1 * v;
}

Vector operator- (const Vector &a, const Vector &b) {
    return a + -1 * b;
}

Vector operator[] (const unsigned long i, const Vector &v) {
    return v.vect[i];
}

ostream& operator<< (ostream &out, const Vector &v) {
    out << "[ ";
    for (auto i : v.vect) {
        out << i << " ";
    }
    out << "]";
    return out;
}


int main()
{
    Vector a ({5, 2});
    Vector b ({2, -4});
    Vector c = a - b;

    cout << c << endl;

    return 0;
}
