#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector < vector <int> > v;

    vector <int> temp = {1, 2, 3, 4}; // C++ 11 only
    v.push_back(temp);
    temp = {5, 6, 7, 8};
    v.push_back(temp);

    vector <int> new_v = {9, 10, 11};
    set_row(v, 2, new_v);

    for (unsigned int y = 0; y < v.size(); ++y) {
        for (unsigned int x = 0; x < v[y].size(); ++x) {
            cout << v[y][x] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
