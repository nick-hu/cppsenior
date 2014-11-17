#include <iostream>
#include <vector>

using namespace std;

void display(const vector <int>);
void printvec(const vector <int>);

int main()
{
    vector <int> v; // declare v without size

    v.push_back(3);
    v.push_back(-4);

    cout << v.size() << endl;
    cout << endl;
    display(v);

    vector <int> w(3); // declare w with size 3 BUT we don't know what's in w
    w[1] = 5;
    w.at(2) = 10;
    display(w);

    vector <int> x(3, 1); // declare x with size 3 and fill x with 1s
    display(x);

    vector <int> y = {1, 2, 3}; // C++ 11 only
    display(y);
    printvec(y);

    return 0;
}

void display(const vector <int> v)
{
    unsigned int i;

    cout << "[";
    for (i = 0; i < v.size() - 1; ++i) {
        cout << v[i] << ", ";
    }
    cout << v[i];
    cout << "]" << endl;
}

void printvec(const vector <int> v)
{
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
}
