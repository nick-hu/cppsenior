#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, char> DecodeTable;
// Strings are hashable and thus lookup time will be constant

struct Byte {
    Byte(char, unsigned char);

    union {
        char chr;
        unsigned char num;
    };
};

Byte::Byte(char c=0, unsigned char n=0) : chr(c), num(n) {}

void byte_to_bitstr(const Byte &b, string &str, unsigned char num_bits=8) {
    unsigned char bit;
    string bitstr;
    for (bit = 0; bit < num_bits; ++bit) {
        str.push_back((((b.num >> (7 - bit)) & 1) == 0) ? '0' : '1');
        bitstr.push_back((((b.num >> (7 - bit)) & 1) == 0) ? '0' : '1');
    }
}

void flush_string(string &buffer, ofstream &file, const DecodeTable &code,
                  string &charcode, unsigned short &minlen) {
    DecodeTable::const_iterator it;

    unsigned short _ = minlen, buflen = buffer.length();
    for (_; _ < buflen; ++_) {
        charcode.push_back(buffer[minlen++]);
        it = code.find(charcode);
        if (it != code.end()) {
            file.put(it->second);
            buffer.erase(0, (it->first).length());
            charcode.clear();
            minlen = 0;
        }
    }
}

int main() {
    Byte mapsize, codelen, codebyte;
    char c;
    unsigned char i, byte, bit, num_bytes, num_bits;

    DecodeTable code;
    code.reserve(256);

    ifstream file;
    file.open("compfile.txt", ios::in);
    file.get(mapsize.chr);

    string charcode;
    for (i = 0; i < mapsize.num; ++i) { // Iterate over each table row
        file.get(c); // Store character
        file.get(codelen.chr); // Length of code in bits
        num_bytes = (codelen.num-1) / 8 + 1; // Length of code in bytes

        for (byte = 0; byte < num_bytes; ++byte) {
            file.get(codebyte.chr); // Get "byte-sized" portion of code
            num_bits = (byte == num_bytes - 1) ? (codelen.num % 8) : 8;
            byte_to_bitstr(codebyte, charcode, (!num_bits ? 8 : num_bits));
        }

        code[charcode] = c;
        charcode.clear();
    }

    Byte textbyte;
    string buffer, codestr;
    unsigned short codesize = 0;

    ofstream newfile;
    newfile.open("decompfile.txt", ios::out | ios::binary);

    while (file.get(textbyte.chr)) {
        if (file.peek() == EOF) { // Remove excess bits from buffer
            buffer.erase(buffer.end() - textbyte.num, buffer.end());
        }
        flush_string(buffer, newfile, code, codestr, codesize);
        byte_to_bitstr(textbyte, buffer);
    }

    file.close();
    newfile.close();

    return 0;
}
