#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    Node();
    Node(const char*, Node*, Node*, Node*);

    char str[];
    Node* next;
    Node* left;
    Node* right;
};

Node::Node() {}

Node::Node(const char* s, Node* n=0, Node* l=0, Node* r=0) {
    strcpy(str, s);
    n = next;
    l = left;
    r = right;
}

int main()
{
    Node* root = new Node("hi");

    return 0;
}

