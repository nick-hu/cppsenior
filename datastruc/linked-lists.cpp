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
    if (!node) {
        return; 
    }
    cout << node->let << " "; // node->let == (*node).let
    traverse(node->next);
}

void Append(Node* &node, char c) {
    if (!node) {
        node = new Node(c);
        return;
    }
    Append(node->next, c);
}

void Prepend(Node* &node, char c) {
    node = new Node(c, node);
}

void Eject(Node* &node) {
    if (!node) {
        return; // Empty list
    }
    if (!(node->next)) {
        node = (delete node, 0);
        return;
    }
    Eject(node->next);
}

void Pop(Node* &node) {
    if (!node) {
        return; // Empty list
    }
    Node* node_after = node->next;
    delete node;
    node = node_after;
}

int main()
{
    Node* root = 0;

    Append(root, 'c');
    Append(root, 'd');
    Eject(root);
    Eject(root);
    Prepend(root, 'b');
    Prepend(root, 'a');

    traverse(root);
    cout << endl;

    Pop(root);
    Pop(root);

    traverse(root);
    cout << endl;

    return 0;
}

