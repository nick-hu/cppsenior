#include <iostream>
#include <string>

using namespace std;

string say(string="Hello");

int main()
{
    cout << say() << endl;
    cout << say("Hi") << endl;

    return 0;
}

string say(string s)
{
    return s;
}
