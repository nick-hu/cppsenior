#include <iostream>

using namespace std;

int main()
{
    int* p;
    p = new int [5]; // Allocate memory for five ints

    p[0] = 1;
    *(p+1) = 2;

    cout << p[0] << " " << p[1] << endl;

    delete[] p; // Free memory reserved by p

    return 0;
}
