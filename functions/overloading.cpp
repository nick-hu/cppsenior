#include <iostream>
#include <string>

using namespace std;

int foo(int, int);
int foo(string); // OVERLOADING
string foo(string, string);
// string foo(int, int); will NOT compile!

int main()
{
    cout << foo(4, 5) << endl;
    cout << foo("How are you?") << endl;
    cout << foo("Hello", "!") << endl;

    return 0;
}

int foo(int x, int y)
{
    return x + y;
}

int foo(string s)
{
    return s.length();
}

string foo(string a, string b)
{
    return a + b;
}
