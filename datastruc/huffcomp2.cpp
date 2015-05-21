#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <deque>

using namespace std;

typedef map<unsigned char, deque<bool>> CodeTable;

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
    deque<Node*> Q = {node};
    Node* n;

    while (!Q.empty()) { // Breadth-first printing
        n = Q.front();
        if (n) {
            cout << *n;
            Q.push_back(n->left);
            Q.push_back(n->right);
        }
        Q.pop_front();
    }
    cout << endl;
}

void print_ct(const CodeTable &code) {
    for (const auto &kv : code) {
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

void huffman_code(Node* const node, CodeTable &code,
                  deque<bool> bv={}) { // Depth-first preorder traversal
    if (!node->left) { // Equivalent to !node->right since the tree is FULL
        code[(node->str).c_str()[0]] = bv;
        return;
    }
    bv.push_back(0);
    huffman_code(node->left, code, bv); // Append a 0 when moving left
    bv.back() = 1;
    huffman_code(node->right, code, bv); // Append a 1 when moving right
}

void flush_deque(deque<bool> &buffer, ofstream &file, unsigned short bits=8) {
    if (!bits) {
        return;
    }
    unsigned char c = 0;
    for (unsigned short i = 0; i < bits; ++i) {
        c += (1 << (7-i)) * buffer.front();
        buffer.pop_front();
    }
    file << c;
}

void serialize_ct(CodeTable &code, ofstream &file) {
    deque<bool> buffer;

    for (const auto &kv : code) {
        file.put(kv.first); // Character
        file.put(kv.second.size()); // Length of code
        for (const bool &b : kv.second) {
            buffer.push_back(b);
        }
        while (buffer.size() >= 8) {
            flush_deque(buffer, file);
        }
        flush_deque(buffer, file, buffer.size());
    }
}

int main() {
    Node* root = 0;

    unsigned int freq[256];
    fill_n(freq, 256, 0);

    unsigned char c;
    ifstream file;

    file.open("file.txt", ios::in);
    while (file >> noskipws >> c) {
        freq[c]++;
    }

    for (short i = 0; i < 256; ++i) { // Construct linked list
        if (freq[i]) {
            emplace_list(root, new Node(string(1, i), freq[i]));
        }
    }

    while (root->next) { // Construct binary tree
        emplace_list(root, huffman_parent(root));
    }

    CodeTable code;
    huffman_code(root, code);

    print_ct(code);

    deque<bool> buffer;
    file.clear();
    file.seekg(0, ios::beg); // Reset original file for second reading

    ofstream newfile;
    newfile.open("compfile.txt", ios::out);

    newfile.put(code.size());
    serialize_ct(code, newfile);

    unsigned short bufsize = 0;

    while (file >> noskipws >> c) {
        for (const bool &b : code[c]) {
            buffer.push_back(b);
            bufsize++;
        }
        while (bufsize >= 8) { // Flush as many bytes as possible
            flush_deque(buffer, newfile);
            bufsize = bufsize - 8;
        }
    }

    unsigned short remainder = (8 - bufsize) % 8;
    flush_deque(buffer, newfile, bufsize);
    newfile.put(remainder);

    file.close();
    newfile.close();
    delete_tree(root);

    return 0;
}

