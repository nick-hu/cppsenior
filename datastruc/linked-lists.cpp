#include <iostream>

using namespace std;

struct Node {
    Node(unsigned int, char, Node*);

    unsigned int num;
    char let;
    Node* next; // LEGAL to declare pointer (Node x is illegal)
};

void transverse(Node* node) {
    cout << node->let << " "; // "node->let" is equivalent to "(*node).let"
    if (node->next != 0) {
        transverse(node->next);
    }
}

int main()
{
    return 0;
}
