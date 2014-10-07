#include <iostream>

using namespace std;

int main()
{
    /* >> is the EXTRACTION OPERATOR
     * cin is SPACE-DELIMITED (only one word can be inputted at a time)
     * use "getline(cin, var)" rather than "cin >> var" */

    string name, mood;

    cout << "What is your name? ";
    getline(cin, name);
    cout << "How are you? ";
    getline(cin, mood);
    cout << "Hello, " << name << ". You are feeling " << mood << "." << endl;

    return 0;
}
