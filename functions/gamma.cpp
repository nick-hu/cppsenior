#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double n;

    cin >> n;
    cout << n << "! = " << tgamma(n+1) << endl;

    return 0;
}
