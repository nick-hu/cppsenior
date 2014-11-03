#include <iostream>
#include <string>

using namespace std;

string poop(string);

int main()
{
    cout << poop("Hi! How are you?") << endl;
    cout << poop("I swam in the crapl. I use shamcrap.") << endl;
    cout << poop("I crapped in the crapper after eating crêpes.") << endl;

    return 0;
}

string poop(string crap)
{
    unsigned int pos = 0;

    while (true) {
        pos = crap.find("crap", pos);

        if (pos < 0 || pos >= crap.size())
            break;

        crap.replace(pos, 4, "poo");
        ++pos;
    }

    return crap;
}
