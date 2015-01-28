#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

struct Vector {
    Vector();
    Vector(vector <double> v);
    Vector(string);

    vector <double> vect;
};

Vector::Vector() {}

Vector::Vector(vector <double> v) {
    vect = v;
}

Vector::Vector(string line) {
    stringstream ss;
    double d;

    ss << line;
    while (ss >> d) {
        vect.push_back(d);
    }
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

double operator~ (const Vector &v) {
    double d = 0;

    for (unsigned int i = 0; i < v.vect.size(); ++i) {
        d += pow(v.vect[i], 2);
    }

    return sqrt(d);
}

bool operator< (const Vector &a, const Vector &b) {
    return ~a < ~b;
}

/* Optional comparison operators

bool operator> (const Vector &a, const Vector &b) {
    return ~a > ~b;
}

bool operator== (const Vector &a, const Vector &b) {
    return a.vect == b.vect;
}

bool operator<= (const Vector &a, const Vector &b) {
    return (a < b) || (a == b);
}

bool operator>= (const Vector &a, const Vector &b) {
    return (a > b) || (a == b);
}

*/

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
    vector <Vector> vects;

    ifstream file;
    string line;

    file.open("vectext.txt", ios::in);
    while (getline(file, line)) {
        vects.push_back(Vector(line));
    }        

    sort(vects.begin(), vects.end());

    for (auto i : vects)
        cout << i << " " << ~i << endl;

    return 0;
}
