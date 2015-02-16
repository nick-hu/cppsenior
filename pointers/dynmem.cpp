#include <iostream>

using namespace std;

int main()
{
    int* n = new int; // Allocate memory for an int
    // int is on the HEAP (can only be referenced through n
    // If n goes out of scope, int can no longer be referenced!
    *n = 5;
    cout << *n << endl;
    delete n; // Frees memory for OS
    // If n is not deleted, allocated memory will not be freed --
    // this is a MEMORY LEAK!
    n = 0; // n is a NULL POINTER -- dereferencing n is now a segfault
    // We don't want this to work: cout << *n << endl;

    return 0;
}
