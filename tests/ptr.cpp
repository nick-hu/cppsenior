#include <iostream>

using namespace std;

bool palin(string* sptr)
{
    *sptr = "No";
    return false;
}

int main()
{
    string sent = "Yes";
    cout << palin(&sent) << endl;
    cout << sent << endl;

    return 0;
}
