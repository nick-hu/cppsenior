#include <iostream>
#include <fstream>
#include <string.h>

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

bool operator< (const Node &a, const Node &b) {
    return a.freq < b.freq;
}

void repr_print(const char* s) {
    char c;

    for (short i = 0; i < sizeof(s); ++i) {
        c = s[i];
        if (!c) { // Null
            break;
        }
        else if (c < ' ' || c > '~') { // Non-printable character
            printf("\\%#x", c);
        }
        else { // Ordinary, printable character
            cout << c;
        }
    }
}

void traverse_list(Node* node) {
    if (!node) {
        cout << endl;
        return;
    }

    cout << "('";
    repr_print(node->str);
    cout << "' " << node->freq << ")";

    traverse_list(node->next);
}

void emplace_list(Node* &node, const char* s, unsigned int f) {
    if (!node || (f >= node->freq)) {
        node = new Node(s, f, node);
        return;
    }
    emplace_list(node->next, s, f);
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
        freq[c]++;
    }
    file.close();

    char cstring[2] = {'\0', '\0'};
    for (short i = 0; i < 256; ++i) {
        if (freq[i]) {
            cstring[0] = i;
            emplace_list(root, cstring, freq[i]);
        }
    }

    traverse_list(root);

    return 0;
}

