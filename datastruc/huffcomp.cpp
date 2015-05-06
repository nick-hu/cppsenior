#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    Node();
    Node(const char*, unsigned int, Node*, Node*, Node*);

    char str[256];
    unsigned int freq;
    Node* next;
    Node* left;
    Node* right;
};

Node::Node() {}

Node::Node(const char* s, unsigned int f, Node* n=0, Node* l=0, Node* r=0) {
    strncpy(str, s, 256);
    freq = f;
    next = n;
    left = l;
    right = r;
}

ostream& operator<< (ostream &out, const Node &node) {
    out << "('";

    char c, npc[8];
    for (short i = 0; i < strlen(node.str); ++i) {
        c = node.str[i];
        if (c < ' ' || c > '~') { // Non-printable character
            sprintf(npc, "\\%#x", c);
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

    while (!Q.empty()) {
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
        delete node;
        node = 0;
    }
}

Node* huffman_parent(Node* &node) {
    if (!node || !node->next) {
        return 0;
    }

    if (!node->next->next || !node->next->next->next) {
        Node** rc = (!node->next->next) ? &node : &(node->next);
        Node* lc = (*rc)->next;

        Node* parent = new Node(lc->str, lc->freq + (*rc)->freq, 0, lc, *rc);
        strcat(parent->str, (*rc)->str);

        *rc = 0;
        return parent;
    }

    return huffman_parent(node->next);
}

void huffman_code(Node* const node, vector<bool> code[], vector<bool> bv={}) {
    if (!node->left) {
        code[(node->str)[0]] = bv;
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

    char cstring[2] = {'\0', '\0'};
    for (short i = 0; i < 256; ++i) {
        if (freq[i]) {
            cstring[0] = i;
            emplace_list(root, new Node(cstring, freq[i]));
        }
    }

    while (root->next) {
        emplace_list(root, huffman_parent(root));
    }

    print_tree(root);

    vector<bool> code[256];
    huffman_code(root, code);

    for (short i = 0; i < 256; ++i) {
        if (!code[i].empty()) {
            printf("%c : ", i);
            for (const bool &b : code[i]) {
                cout << b;
            }
            cout << endl;
        }
    }

    delete_tree(root);

    return 0;
}

