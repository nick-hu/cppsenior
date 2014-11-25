#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printvec(const vector <int>);

int main()
{
    vector <int> v (3, 0);
    printvec(v); // [ 0 0 0 ]
    cout << v.size() << endl; // 3

    v.resize(5, 1);
    printvec(v); // [ 0 0 0 1 1 ]
    v.resize(2);
    printvec(v); // [ 0 0 ]

    v.push_back(1);
    v.push_back(2);
    printvec(v); // [ 0 0 1 2 ]

    v.pop_back();
    printvec(v); // [ 0 0 1 ]

    vector <int>::iterator beg = v.begin(), end = v.end();

    v.insert(beg, 2);
    printvec(v); // [ 2 0 0 1 ]
    v.insert(beg + 1, 3);
    printvec(v); // [ 2 3 0 0 1 ]
    v.insert(end, 4);
    printvec(v); // [ 2 3 0 4 0 1 ] -- end was initialized when v's size was 3

    v.erase(beg);
    printvec(v); // [ 3 0 4 0 1 ]
    v.erase(beg, end);
    printvec(v); // [ 0 1 ]

    for (vector <int>::const_iterator i = v.cbegin(); i != v.cend(); ++i) {
        cout << *i << endl;
    }

    for (vector <int>::iterator i = v.begin(); i != v.end(); ++i) {
        *i = 5;
    }
    printvec(v); // [ 5 5 ]

    vector <int>::iterator erase_it;
    erase_it = find(v.begin(), v.end(), 5); // find requires <algorithm>
    // find returns end when not found
    v.erase(erase_it);
    printvec(v); // [ 5 ]

    vector <vector<int>> v2;
    v2.push_back(v);
    cout << v2[0][0] << endl; // 5

    return 0;
}

void printvec(const vector <int> v)
{
    cout << "[ ";
    for (auto i: v) {
        cout << i << " ";
    }
    cout << "]" << endl;
}
