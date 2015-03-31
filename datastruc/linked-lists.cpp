#include <iostream>

using namespace std;

struct Node {
    Node();
    Node(char, Node*);

    char let;
    Node* next; // LEGAL to declare pointer (Node x is illegal)
};

Node::Node() {}

Node::Node(char c, Node* np=0) {
    let = c;
    next = np;
}

void traverse(Node* node) {
    cout << node->let << " "; // "node->let" is equivalent to "(*node).let"
    if (node->next != 0) {
        traverse(node->next);
    }
}

void PushNode(Node* &node, char c) {
    if (node == 0) {
        node = new Node(c);
        return;
    }
    PushNode(node->next, c);
}

void PopNode(Node* &node) {
}

int main()
{
    Node* root = 0;
    PushNode(root, 'b');
    PushNode(root, 'c');
    traverse(root);

    return 0;
}
