#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    vector <string> list;

    ifstream infile;
    infile.open("text.txt", ios::in);
    while (getline(infile, line)) {
        list.push_back(line); 
    }
    infile.close();

    sort(list.begin(), list.end());

    ofstream outfile;
    outfile.open("newtext.txt", ios::out);
    for (auto l : list) {
        outfile << l << endl;
    }
    outfile.close();

    return 0;
}
