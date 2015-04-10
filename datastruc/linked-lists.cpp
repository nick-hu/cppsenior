#include <iostream>

using namespace std;

struct Node {
    Node();
    Node(char, Node*);

    char let;
    Node* next; // LEGAL to declare pointer (Node x is illegal)
};

Node::Node() {}

Node::Node(char c, Node* np=0) : let(c), next(np) {}

void traverse(Node* node) {
    if (!node) {
        cout << endl;
        return; 
    }
    cout << node->let << " "; // node->let == (*node).let
    traverse(node->next);
}

unsigned int length(Node* node) {
    if (!node) {
        return 0;
    }
    return length(node->next) + 1;
}

void ndelete(Node* &node) {
    if (node) {
        ndelete(node->next);
        delete node; // As recursive calls return, the next node is deleted
        node = 0; // Especially necessary for the case of a single node
    }
}

void Append(Node* &node, char c) {
    // Pass node by reference in case root node is changed
    if (!node) {
        node = new Node(c);
        return;
    }
    Append(node->next, c); // Seek the end of the list
}

void Prepend(Node* &node, char c) {
    node = new Node(c, node);
}

void Eject(Node* &node) {
    if (node && !(node->next)) {
        delete node;
        node = 0;
        return;
    }
    Eject(node->next);
}

void Pop(Node* &node) {
    if (node) {
        Node* node_after = node->next;
        delete node;
        node = node_after;
    }
}

void Emplace(Node* &node, char c) {
    if (!node || (c <= node->let)) { 
        // Short-circuit evaluation of OR prevents nullptr dereferencing
        Prepend(node, c);
        return;
    }
    Emplace(node->next, c);
}

int main()
{
    Node* root = 0;

    Append(root, 'd');
    Append(root, 'e');
    Eject(root);
    Prepend(root, 'b');
    Prepend(root, 'a');

    traverse(root);

    Pop(root);
    cout << length(root) << endl;
    traverse(root);

    Node* root2 = 0;
    Emplace(root2, 'y');
    Emplace(root2, 'x');
    Emplace(root2, 'z');
    traverse(root2);

    ndelete(root);
    ndelete(root2);

    return 0;
}

