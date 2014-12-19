#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <char, double> testmap;
    testmap['a'] = 1.2;
    cout << testmap['a'] << endl;

    map<char, double>::iterator it = testmap.find('a');
    if (it != testmap.end())
        cout << it->second << endl;
    return 0;
}
