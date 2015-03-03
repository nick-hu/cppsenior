#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    char** v = new char* [64];  // New array of strings (64 strings long)

    ifstream infile;
    infile.open("fruit.txt", ios::in);

    unsigned short c = 0;
    while (infile.good()) {
        v[c] = new char [32];   // New string (32 chars long)
        infile >> v[c++];       // Extract line (string) from file
    }
    
    infile.close();

    for (unsigned short i = 0; i < c; ++i) {
        printf("%u %s\n", i, v[i]);
        delete[] v[i];          // Delete each string (char array)
        v[i] = 0;               // Set char* to NULL
    }
    delete[] v[c-1];            // Remember to delete EOF string!
    v[c-1] = 0;
    delete[] v;                 // Delete array of strings
    v = 0;

    return 0;
}
