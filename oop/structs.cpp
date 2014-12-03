#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

string int_to_str(int);

struct Student {
    Student();
    Student(string);

    string name;
    unsigned int age;
    vector <double> marks;
};

Student::Student() {}

Student::Student(string n) {
    name = n;
}

int main()
{
    vector <Student> students;

    for (unsigned int i = 0; i < 10; ++i) {
        Student p;
        p.name = "Student " + int_to_str(i);
        p.age = 10 + int((10.0 * rand())/(RAND_MAX + 1.0));
        p.marks.push_back(int((100.0 * rand())/(RAND_MAX + 1.0)));

        printf("%s, age %u, mark %.2f%%\n", p.name.c_str(), p.age, p.marks[0]);

        students.push_back(p);
    }

    return 0;
}

string int_to_str(int n)
{
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    return s;
}
