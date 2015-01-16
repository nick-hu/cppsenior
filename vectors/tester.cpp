#include <iostream>

using namespace std;

int main()
{
    srand(time(0));
    short size = rand() % 15 + 1;

    for (unsigned short _ = 0; _ < size; ++_) {
        for (unsigned short i = 0; i < size; ++i) {
            cout << rand() % 9 + 1;
            if (i != size - 1)
                cout << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (unsigned short i = 0; i < size; ++i) {
        cout << rand() % 9 + 1;
        if (i != size - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
