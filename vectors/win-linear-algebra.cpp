#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef vector <double> Vector;
typedef vector <Vector> Matrix;
typedef map <Matrix, double> MDMap;

double Determinant(const Matrix &, MDMap &);
Matrix Minor(const Matrix &, unsigned int, unsigned int);
Matrix Replace(Matrix, unsigned int, const Vector);
Vector Solve(const Matrix &, const Vector &, MDMap &);

void getMatrix(Matrix &);
void getVector(Vector &, unsigned int);
void print(const Matrix &);
void print(const Vector &);
void print(const MDMap &);

int main()
{
    MDMap DETMAP; // Matrix-Determinant map for memoization
    DETMAP[{{}}] = 0;
    // DETMAP is a special value to count determinant calculations saved.
    // Global variables are evil, so we pass DETMAP by reference
    // to Determinant and Solve.

    Matrix A;
    getMatrix(A);
    Vector B;
    getVector(B, A.size());

    Vector X = Solve(A, B, DETMAP);
    cout << endl;
    // Checking for infinite/no solutions:
    if (X.empty()) {
        bool dependent = true;
        for (unsigned int i = 0; i < A.size(); ++i) {
            if (Determinant(Replace(A, i, B), DETMAP)) {
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

    cout << endl << DETMAP.size() - 1 << " matrices memoized :)" << endl;
    cout << DETMAP[{{}}] << " determinant calculations saved :D" << endl;

    return 0;
}

double Determinant(const Matrix &m, MDMap &detmap) {
    double det = 0;

    MDMap::iterator it = detmap.find(m);
    // If matrix in MDMap return memoized determinant
    if (it != detmap.end()) {
        detmap[{{}}] += 1; // Tracks number of memoized matrices
        return it->second;
    }

    if (m.size() == 2) {
        det = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
    }
    else {
        short sign = 1;
        for (unsigned int c = 0; c < m.size(); ++c) {
            det += sign * m[0][c] * Determinant(Minor(m, 0, c), detmap);
            sign *= -1;
        }
    }
    detmap[m] = det;
    return det;
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

Vector Solve(const Matrix &A, const Vector &B, MDMap &detmap) {
    Vector x;
    const double detA = Determinant(A, detmap);

    if (not detA)
        return {};

    for (unsigned int i = 0; i < A.size(); ++i)
        x.push_back(Determinant(Replace(A, i, B), detmap)/detA);
    return x;
}

void getMatrix(Matrix &m)
{
    unsigned int size;
    cin >> size;
    double d;

    for (unsigned int r = 0; r < size; ++r) {
        m.push_back({});
        for (unsigned int c = 0; c < size; ++c) {
            cin >> d;
            m[r].push_back(d);
        }
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
    for (const auto &r : m) {
        cout << "[\t";
        for (const auto &c : r) {
            cout << c << "\t";
        }
        cout << "]" << endl;
    }
}

void print(const Vector &v)
{
    for (const auto &i : v)
        cout << "[\t" << i << "\t]" << endl;
}

void print(const MDMap &md)
{
    for (const auto &kv : md) {
        print(kv.first);
        cout << "=> " << kv.second << endl;
    }
}
