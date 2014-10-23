#include <iostream>

using namespace std;

void DaysToHrsMins(unsigned int, unsigned int &, unsigned int &);

int main()
{
    unsigned int d, h, m;

    for (d = 1; d <= 10; ++d) {
        DaysToHrsMins(d, h, m);
        cout << d << " day(s) is " << h << " hours or ";
        cout << m << " minutes" << endl;
    }

    return 0;
}

void DaysToHrsMins(unsigned d, unsigned &h, unsigned &m)
{
    h = d * 24;
    m = h * 60;
}
