#include <iostream>
#include <vector>

using namespace std;

void set_row(vector &, unsigned int, vector);
void set_column(vector &, unsigned int, vector);

int main()
{
    vector < vector <int> > v;

    vector <int> temp = {1, 2, 3, 4}; // C++ 11 only
    v.push_back(temp);
    temp = {5, 6, 7, 8};
    v.push_back(temp);

    for (unsigned int y = 0; y < v.size(); ++y) {
        for (unsigned int x = 0; x < v[y].size(); ++x) {
            cout << v[y][x] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

void set_row(vector &v, unsigned int n, vector v2)
{
    v[n] = v2;
}

void set_column(vector &v, unsigned int n, vector v2)
{
    
