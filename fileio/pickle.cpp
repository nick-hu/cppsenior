#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool dump(vector <string> &, string);
vector <string> load(string);

bool dump(vector <string> &v, string fname)
{
    ofstream file;
    file.open(fname.c_str(), ios::out);

    for (auto i : v)
        file << i << endl;

    file.close();
    return true;
}

vector <string> load(string fname)
{
    vector <string> strvect;
    string line;
    ifstream file;
    file.open(fname.c_str(), ios::in);

    while (getline(file, line))
        strvect.push_back(line);

    file.close();
    return strvect;
}

int main()
{
    vector <string> old(3, "Hello world!");
    if (dump(old, "savefile.txt"))
        cout << "File successfully saved!" << endl;
    else
        cout << "Error saving file!" << endl;
    old.clear();

    vector <string> items = load("savefile.txt");
    for (auto i : items)
        cout << i << endl;

    return 0;
}
