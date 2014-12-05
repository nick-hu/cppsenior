#include <iostream>
#include <vector>

using namespace std;

void DeleteAllZeroes(vector <int> &A);

int main()
{
    vector <int> b(8, 0);
    b[0] = 3;
    b[1] = 5;
    b[3] = 7;
    b[6] = 12;
    DeleteAllZeroes(b);

    for (unsigned int x = 0; x < b.size(); x++)
        cout << b[x] << endl;

    return 0;
}

void DeleteAllZeroes(vector <int> &A)
{
    vector <int> n;

    for (unsigned int i = 0; i < A.size(); ++i) {
        if (A[i])
            n.push_back(A[i]);
    }

    A = n;
}
