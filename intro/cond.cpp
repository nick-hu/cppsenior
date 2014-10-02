#include <iostream>

using namespace std;

int main() {

    bool b;
    b = true;

    if (b) cout << "b is true" << endl;

    if (2 == 1+1)
        cout << "1+1 = 2" << endl;

    if (3 == 1+1) {
        cout << "1+1 = 3" << endl;
    } else if (3 == 1-1) {
        cout << "1-1 = 3" << endl;
    } else {
        cout << "Hi" << endl;
    }

    return(0);
}
