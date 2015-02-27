#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>

using namespace std;

int main()
{
    char* h = "abcdefg";
    cout << sizeof(h) << endl;
    cout << typeid(h).name() << endl;
    cout << typeid(*h).name() << endl;
    cout << *h << endl;
    cout << *(h+1) << endl;
    printf("%s", h);

/*
    string line;
    vector <string> list;

    ifstream infile;
    infile.open("fruit.txt", ios::in);
    while (getline(infile, line)) {
        list.push_back(line); 
    }
    infile.close();

    for (auto l : list) {
        cout << l << endl;
    }
    */

    return 0;
}
