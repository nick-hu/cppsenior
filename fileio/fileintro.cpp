#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string word;
    ifstream file; // INPUT file stream
    
    file.open("text.txt", ios::in); // Open file for reading
    while (file >> word) { // Extract word from file
        cout << word << endl;
    }

    file.clear(); // File is in EOF state and must be reset to good
    file.seekg(0, ios::beg); // Seek beginning with offset of 0

    while (getline(file, word)) { // Getline from file
        cout << word << endl;
    }

    file.clear(); 
    file.seekg(0, ios::beg); 

    while (file.good()) { // While file is in good state 
        getline(file, word);
        cout << word << endl;
    }

    file.close();

    return 0;
}
