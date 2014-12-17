#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef vector <double> Vector;
typedef vector <Vector> Matrix;

double Determinant(const Matrix &, map &);
Matrix Minor(const Matrix &, unsigned int, unsigned int);
Matrix Replace(Matrix, unsigned int, const Vector);
Vector Solve(const Matrix &, const Vector &);

void getMatrix(Matrix &);
void getVector(Vector &, unsigned int);
void print(const Matrix &);
void print(const Vector &);

int main()
{
    map <Matrix, double> DETMAP;

    Matrix A;
    getMatrix(A);
    Vector B;
    getVector(B, A.size());
    
    Vector X = Solve(A, B);
    cout << endl;
    if (X.empty()) {
        bool dependent = true;
        for (unsigned int i = 0; i < A.size(); ++i) {
            if (Determinant(Replace(A, i, B)), DETMAP) {
                dependent = false;
                break;
            }
        }
        if (dependent)
            cout << "Infinite solutions: dependent system!" << endl;
        else
            cout << "No solutions: inconsistent system!" << endl;
    }
    else {
        print(X);
    }

    return 0;
}

double Determinant(const Matrix &m, map &detmap) {
    if (m.size() == 2) {
        return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
    }
    else {
        map<Matrix, double>::iterator it = detmap.find(m);
        if (it != m.end()) {
            return *it;
        } 
        else {
            double det = 0;
            short sign = 1;

            for (unsigned int c = 0; c < m.size(); ++c) {
                det += sign * m[0][c] * Determinant(Minor(m, 0, c), DETMAP);
                sign *= -1;
            }

            detmap[m] = det;
            return det;
        }
    }
}

Matrix Minor(const Matrix &m, unsigned int row, unsigned int column) {
    Matrix minm = {};
    
    for (unsigned int r = 0; r < m.size(); ++r) {
        if (r != row) {
            minm.push_back({});
            for (unsigned int c = 0; c < m[r].size(); ++c) {
                if (c != column)
                    minm.back().push_back(m[r][c]);
            }
        }
    }
    return minm;
}

Matrix Replace(Matrix m, unsigned int column, const Vector v) {
    for (unsigned int r = 0; r < m.size(); ++r)
        m[r][column] = v[r];
    return m;
}

Vector Solve(const Matrix &A, const Vector &B) {
    Vector x;
    const double detA = Determinant(A, DETMAP);

    if (not detA)
        return {};

    for (unsigned int i = 0; i < A.size(); ++i)
        x.push_back(Determinant(Replace(A, i, B), DETMAP)/detA);
    return x;
}

void getMatrix(Matrix &m)
{
    string row;
    string::size_type s;

    while (true) {
        getline(cin, row);
        if (row.empty())
            break;

        m.push_back({});
        do {
            m.back().push_back(stof(row, &s));
            row = row.substr(s);
        } while (not row.empty());
    } 
}

void getVector(Vector &v, unsigned int n)
{
    double d;
    for (unsigned int _ = 0; _ < n; ++_) {
        cin >> d;
        v.push_back(d);
    }
}

void print(const Matrix &m)
{
    for (auto r : m) {
        cout << "[\t";
        for (auto c : r) {
            cout << c << "\t";
        }
        cout << "]" << endl;
    }
}

void print(const Vector &v)
{
    for (auto i : v)
        cout << "[\t" << i << "\t]" << endl;
}
