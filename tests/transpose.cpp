#include <iostream>
#include <vector>

using namespace std;

typedef vector < vector <int> > Matrix;

Matrix get();
Matrix trans(const Matrix &);
void disp(const Matrix &);

Matrix get()
{
    Matrix m;
    unsigned int row, col;
    cin >> row >> col;
    int i;

    for (unsigned int r = 0; r < row; ++r) {
        m.push_back({});
        for (unsigned int c = 0; c < col; ++c) {
            cin >> i;
            m[r].push_back(i);
        }
    }

    return m;
}

Matrix trans(const Matrix &m) 
{
    Matrix n;
    unsigned int row = m.size();
    unsigned int col = m.at(0).size();
    
    for (unsigned int r = 0; r < col; ++r) {
        n.push_back({});
        for (unsigned int c = 0; c < row; ++c) {
            n[r].push_back(m[c][r]); // Opposite of m[r][c]
        }
    }
    
    return n; 
}

void disp(const Matrix &m)
{
    for (const auto &r : m) {
        for (const auto &c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix a, b;

    a = get();
    disp(a);
    cout << endl << endl;
    b = trans(a);
    disp(b);

    return 0;
}
