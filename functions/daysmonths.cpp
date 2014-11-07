#include <iostream>

using namespace std;

int main()
{
    enum month {January=1, February, March, April, May, June,
                July, August, September, October, November, December};
    unsigned int n;

    cout << "Month number: ";
    cin >> n;

    switch (n) {
        case February: cout << 28 << endl; break;
        case April:
        case June:
        case September:
        case November: cout << 30 << endl; break;
        default: cout << 31 << endl; break;
    }

    return 0;
}
