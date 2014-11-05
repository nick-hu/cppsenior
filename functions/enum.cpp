#include <iostream>

using namespace std;

int main()
{
    enum suit {hearts, spades, clubs, diamonds};

    suit x = spades;
    int y = diamonds;

    cout << suit(1.9) << endl;
    cout << x << endl;
    cout << y << endl;

    switch (x) {
        case hearts: cout << "hearts" << endl; break;
        case spades: cout << "spades" << endl; break;
        case clubs: cout << "clubs" << endl; break;
        case diamonds: cout << "diamonds" << endl; break;
    }

    return 0;
}
