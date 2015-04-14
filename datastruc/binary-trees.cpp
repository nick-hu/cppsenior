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

void level_traverse(Node* node, bool descend=true) {
    /*
    if (node) {
        if (!descend) {
            cout << node->num << " ";
        }
        if (descend) {
            level_traverse(node->left, false);
            level_traverse(node->right, false);
            level_traverse(node->left);
            level_traverse(node->right);
        }
    }
    */
}

void ndelete(Node* &node) {
    if (node->left) {
        ndelete(node->left);
    }
    if (node->right) {
        ndelete(node->right);
    }
    delete node;
    node = 0;
}

void Emplace(Node* &node, short n) {
    if (n <= node->num) {
        if (!node->left) {
            node->left = new Node(n);
            return;
        }
        Emplace(node->left, n);
    }
    else {
        if (!node->right) {
            node->right = new Node(n);
            return;
        }
        Emplace(node->right, n);
    }
}


int main()
{
    Node* root = new Node(6);
    Emplace(root, 2);
    Emplace(root, 7);
    Emplace(root, 1);
    Emplace(root, 4);
    Emplace(root, 3);
    Emplace(root, 5);
    Emplace(root, 9);
    Emplace(root, 8);

    pre_traverse(root);
    cout << endl;

    post_traverse(root);
    cout << endl;

    in_traverse(root);
    cout << endl;

    level_traverse(root);
    cout << endl;

    ndelete(root);

    return 0;
}

