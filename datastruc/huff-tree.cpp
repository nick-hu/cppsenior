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
    fill_n(str, 256, '\0');
    strcpy(str, s);
    freq = f;
    n = next;
    l = left;
    r = right;
}

bool operator< (const Node &a, const Node &b) {
    return a.freq < b.freq;
}

void traverse_list(Node* node) {
    if (!node) {
        cout << endl;
        return;
    }
    cout << "(" << node->str << " " << node->freq << ")";
    traverse_list(node->next);
}

void emplace_list(Node* &node, const char* s, unsigned int f) {
    if (!node || (f <= node->freq)) { 
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
    while (file >> c) {
        freq[c]++;
    }
    file.close();

    emplace_list(root, "hi", 4);

    traverse_list(root);

    emplace_list(root, "hi", 3);

    traverse_list(root);

    emplace_list(root, "hi", 7); 

    traverse_list(root);

    return 0;
}

