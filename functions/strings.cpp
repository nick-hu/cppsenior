#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Nicholas", nums = "13", n = "2", n2 = "45678";

    cout << "Size of string: " << name.size() << endl;
    cout << name.at(2) << endl; // get character at position 2

    nums.insert(1, n); // insert n at position 1
    cout << nums << endl;
    nums.insert(3, n2, 1, 4); // insert "5678" of n2 at position 3
    cout << nums << endl;

    name.insert(8, " Hu"); // insert " Hu" at position 8
    cout << name << endl;
    name.insert(11, ".blablabla", 1); // insert "." at position 11
    cout << name << endl;

    nums.insert(3, 1, '4'); // insert char '4' at position 3
    cout << nums << endl;
    cout << nums[3] << endl;

    nums.erase(5, 3); // erase 3 chars starting at position 5
    cout << nums << endl;

    string sentence = "Can you find the find in this string?";
    unsigned int found_pos = sentence.find("find");

    cout << endl;
    cout << found_pos << endl; // found_pos == 8
    cout << sentence.find("find", found_pos + 1) << endl; // look after pos 9
    cout << sentence.rfind("find") << endl; // find last "find"
    cout << sentence.substr(4, 3) << endl; // substring of length 3 from pos 4

    string bla = "bla";
    cout << bla.erase(0, 1) << endl;
    cout << bla.erase() << endl;

    return 0;
}
