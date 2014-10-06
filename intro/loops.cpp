#include <iostream>

using namespace std;

int main() {

    /* "int y": DECLARATION of a
     * "y = 0": INITIALIZATION of a
     * "y < 20": test condition
     * x++: evaluate x, then increment x (POSTFIX increment)
     * ++x: increment x, then evaluate x (PREFIX increment) */

    for (int x = 0; x < 10; x++) {
        cout << x << endl;
    }

    int y;
    for (y = 10; y < 20; ++y) {
        if (y == 13) continue;
        if (y == 15) break;
        cout << y << endl;
    }
    cout << y << endl;

    int a, b, c;
    a = 1;
    b = ++a;
    c = b++;
    cout << a << "," << b << "," << c << endl;

    return(0);
}
