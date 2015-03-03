#include <iostream>
#include <stdio.h>  // Required for printf
#include <string.h> // Required for strncpy

using namespace std;

int main()
{
    int* n = new int;
    
    // Allocate memory for an int
    // int is on the HEAP (can only be referenced through n)
    // If n goes out of scope, int can no longer be referenced!

    *n = 5;
    cout << *n << endl;

    delete n;

    // Memory is freed for OS
    // If n is not deleted, allocated memory will not be freed -- 
    // this is a MEMORY LEAK!

    n = 0;

    // n is set to the NULL POINTER -- dereferencing n is now a segfault
    // We don't want this to work: 'cout << *n << endl;'

    /*
    char ca[32];                                    // Allocate memory for (32) char array
    const char* s = "abcdefghijklmnopqrstuvwxyz123456";
    cout << "sizeof(ca): " << sizeof(ca) << endl;   // Array is 32 bytes; each char is 1 byte
    strncpy(ca, s, sizeof(ca) - 1);                 // Copy s into ca; leave 1 byte for null char
    cout << ca << endl;

    char* cs = new char[32];                        // Allocate memory for char array (i.e. C string)
    cout << "sizeof(cs): " << sizeof(cs) << endl;
    strncpy(cs, "Goodbye world", sizeof(cs) - 1);   // String copy; subtract 1 from sizeof since 
    printf("%s\n", cs);                             // Print with formatting
    
    delete[] cs;
    */

    return 0;
}
