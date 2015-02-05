#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Letter {
    Letter(char);

    char let;
    unsigned long count = 0;
};

Letter::Letter(char c) {
    let = c;
}

bool operator> (const Letter &l1, const Letter &l2) {
    return l1.count > l2.count;
} 


int main(int argc, char* argv[])
{
    vector <Letter> lets;

    for (char c = 'A'; c <= 'Z'; ++c) {
        lets.push_back(Letter(c));
    }

    char c;

    ifstream infile;
    infile.open(argv[1], ios::in);
    while (infile >> c) {
        c = toupper(c);
        if (('A' <= c) && (c <= 'Z')) {
            lets[c - 65].count += 1; 
        }
    }
    infile.close();

    sort(lets.begin(), lets.end(), greater<Letter>());

    for (const auto &i : lets) {
        cout << i.let << " " << i.count << endl;
    }

    return 0;
}
