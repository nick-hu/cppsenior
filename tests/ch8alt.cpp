#include <iostream>
#include <vector>
#include <algorithm>

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
    A.erase(remove(A.begin(), A.end(), 0), A.end());
}
