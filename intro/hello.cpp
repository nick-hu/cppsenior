#include <iostream> // no .h (OLD) required

using namespace std;

int main() // function main returns int
{
	/* use std::cout if not using namespace std
	 * :: is the SCOPE RESOLUTION OPERATOR
	 * cout is an OUTPUT STREAM (Console OUTput)
	 * << is the INSERTION OPERATOR
	 * use double quotes for str
	 * 0 is a success code; 1 is an error code
	 * endl flushes the cout buffer (use endl rather than \n) */

    cout << "Hello, world!" << endl;
    return 0;
}
