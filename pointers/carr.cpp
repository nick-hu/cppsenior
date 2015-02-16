#include <iostream>

using namespace std;

int main()
{
    int num[5]; // C array
    num[0] = 14;
    num[1] = 13;
    num[2] = 12;
    
    cout << *num << " " << num[0] << endl;
    cout << *(num + 2) << endl; // num[2]
    // Size of the data type is taken into account
    cout << num << " " << num + 2 << endl;
    cout << *num + 2 << endl; // num[0] + 2

    // Since num is also a pointer, the following is valid:
    int* p = num;
    *(num + 3) = 11;
    p = &num[4];
    *p = 10;
    cout << endl;

    for (auto i : num)
        cout << i << " ";
}
