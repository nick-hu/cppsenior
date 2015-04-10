#include <iostream>

using namespace std;

struct Node {
    Node();
    Node(short, Node*, Node*);

    short num;
    Node* left;
    Node* right;
};

Node::Node() {}

Node::Node(short n, Node* l=0, Node* r=0) : num(n), left(l), right(r) {}

void pre_traverse (Node* node) {
    if (node) {
        cout << node->num << " ";
        pre_traverse(node->left);
        pre_traverse(node->right);
    }
}

void post_traverse(Node* node) {
    if (node) {
        post_traverse(node->left);
        post_traverse(node->right);
        cout << node->num << " ";
    }
}

void in_traverse(Node* node) {
    if (node) {
        in_traverse(node->left);
        cout << node->num << " ";
        in_traverse(node->right);
    }
}

void ndelete(Node* node)

void Emplace(Node* &node, char c) {
}

int main()
{
    Node* root = 0;
    root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right = new Node(7);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);

    pre_traverse(root);
    cout << endl;

    post_traverse(root);
    cout << endl;

    in_traverse(root);
    cout << endl;

    return 0;
}

