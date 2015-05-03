#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    Node();
    Node(string, unsigned int, Node*, Node*, Node*);

    string str;
    unsigned int freq;
    Node* next;
    Node* left;
    Node* right;
};

Node::Node() {}

Node::Node(string s, unsigned int f, Node* n=0, Node* l=0, Node* r=0) {
    str = s;
    freq = f;
    next = n;
    left = l;
    right = r;
}

ostream& operator<< (ostream &out, const Node &node) {
    out << "('";

    char npc[8]; // Char array holds text for non-printable characters
    for (const char &c : node.str) {
        if (c < ' ' || c > '~') { // Non-printable character
            sprintf(npc, "\\%#x",  c);
            out << npc;
            continue;
        }
        out << c;
    }

    out << "' " << node.freq << ") ";
    return out;
}

void print_list(Node* const node) {
    if (!node) {
        cout << endl;
        return;
    }
    cout << *node;
    print_list(node->next);
}

void print_tree(Node* const node) {
    queue<Node*> Q;
    Node* n;
    Q.push(node);

    while (!Q.empty()) { // Breadth-first printing
        n = Q.front();
        if (n) {
            cout << *n;
            Q.push(n->left);
            Q.push(n->right);
        }
        Q.pop();
    }
    cout << endl;
}

void print_map(const map<char, vector<bool>> &m) {
    for (const auto &kv : m) {
        cout << kv.first << " : ";
        for (const bool &b : kv.second) {
            cout << b;
        }
        cout << endl;
    }
}

void emplace_list(Node* &node, Node* child) {
    if (!node || child->freq > node->freq) {
        child->next = node;
        node = child;
        return;
    }
    emplace_list(node->next, child);
}

void delete_tree(Node* &node) {
    if (node) { 
        delete_tree(node->left);
        delete_tree(node->right);
        delete node; // Post-order deletion
        node = 0;
    }
}

Node* huffman_parent(Node* &node) {
    if (!node || !node->next) { // Not enough nodes to construct a tree!
        return 0;
    }

    if (!node->next->next || !node->next->next->next) {
        Node** rc = (!node->next->next) ? &node : &(node->next);
        Node* lc = (*rc)->next;

        string newstr = lc->str + (*rc)->str;
        unsigned int newfreq = lc->freq + (*rc)->freq;
        Node* parent = new Node(newstr, newfreq, 0, lc, *rc);

        *rc = 0; // No need to set lc to 0 -- it is at the end of the list
        return parent;
    }

    return huffman_parent(node->next); // Traverse list until child nodes
}

void huffman_code(Node* const node, map<char, vector<bool>> &code, 
                  vector<bool> bv={}) { // Depth-first preorder traversal
    if (!node->left) { // Equivalent to !node->right since the tree is FULL
        code[(node->str).c_str()[0]] = bv;
        return;
    }
    bv.push_back(0);
    huffman_code(node->left, code, bv);
    bv.back() = 1;
    huffman_code(node->right, code, bv);
}

int main()
{
    Node* root = 0;

    unsigned int freq[256];
    fill_n(freq, 256, 0);

    char c;
    ifstream file;

    file.open("file.txt", ios::in);
    while (file.get(c)) {
        if (c == '\n') continue;
        freq[c]++;
    }
    file.close();

    for (short i = 0; i < 256; ++i) { // Construct linked list
        if (freq[i]) {
            emplace_list(root, new Node(string(1, i), freq[i]));
        }
    }

    while (root->next) { // Construct binary tree
        emplace_list(root, huffman_parent(root));
    }

    print_tree(root);

    map<char, vector<bool>> code;
    huffman_code(root, code);

    print_map(code);

    delete_tree(root);

    return 0;
}

