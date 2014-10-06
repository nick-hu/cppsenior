#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));
    int randint = rand();

    cout << randint << endl;

    randint = 20 + int((10.0 * rand())/(RAND_MAX+1.0));
    cout << randint << endl;

    return(0);
}
