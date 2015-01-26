#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;
    
    ofstream file;
    file.open("output.txt", ios::out);

    while (getline(cin, line)) {
        file << line << endl;
    }

    file.close();

    return 0;
}
