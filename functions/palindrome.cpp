#include <iostream>
#include <string>

using namespace std;

bool palindrome(string);

int main()
{
    cout << palindrome("anna") << endl;
    cout << palindrome("1234321") << endl;
    cout << palindrome("hello") << endl;
    cout << palindrome("11") << endl;
    cout << palindrome("0") << endl;
    cout << palindrome("") << endl;

    return 0;
}

bool palindrome(string s)
{
    unsigned int size = s.size();

    for (unsigned int i = 0; i < size / 2; ++i)
        if (s[i] != s[size - 1 - i])
            return false;
    return true;
}
