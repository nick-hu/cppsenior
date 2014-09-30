#include <iostream>

using namespace std;

const double G = 6.674E-11;

int main()
{
    /* >> is the EXTRACTION OPERATOR
     * cin is SPACE-DELIMITED (only one word can be inputted at a time)
     * use "getline(cin, var)" rather than "cin >> var" */

    double m1, m2, r;

    cout << "m1 (kg) = ";
    cin >> m1;
    cout << "m2 (kg) = ";
    cin >> m2;
    cout << "r (m) = ";
    cin >> r;

    cout << "Force of gravity = " << (G*m1*m2)/(r*r) << " N" << endl;

    return(0);
}

