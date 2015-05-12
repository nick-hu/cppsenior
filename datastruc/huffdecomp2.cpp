#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, char> DecodeTable;
// Strings are hashable and thus lookup time will be constant

void byte_to_bitstr(const unsigned char &b, string &str,
                    const unsigned char num_bits=8) {
    for (unsigned char bit = 0; bit < num_bits; ++bit) {
        str.push_back((((b >> (7 - bit)) & 1) == 0) ? '0' : '1');
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
    unsigned char mapsize, c, codelen, codebyte;
    unsigned short _, byte, num_bytes, num_bits;

    DecodeTable code;
    code.reserve(256);

    ifstream file;
    file.open("compfile.txt", ios::in);
    file >> noskipws >> mapsize;

    string charcode;
    for (_ = 0; _ < mapsize; ++_) { // Iterate over each table row
        file >> noskipws >> c; // Store character
        file >> noskipws >> codelen; // Length of code in bits
        num_bytes = (codelen-1) / 8 + 1; // Length of code in bytes

        for (byte = 0; byte < num_bytes-1; ++byte) {
            file >> noskipws >> codebyte; // Get "byte-sized" portion of code
            byte_to_bitstr(codebyte, charcode);
        }
        file >> noskipws >> codebyte;
        byte_to_bitstr(codebyte, charcode, (codelen % 8 ? codelen % 8 : 8));

        code[charcode] = c;
        charcode.clear();
    }



    unsigned char textbyte;
    string buffer, codestr;
    unsigned short codesize = 0;

    ofstream newfile;
    newfile.open("decompfile.txt", ios::out);

    while (file >> noskipws >> textbyte) {
        if (file.peek() == EOF) { // Remove excess bits from buffer
            buffer.erase(buffer.end() - textbyte, buffer.end());
        }
        flush_string(buffer, newfile, code, codestr, codesize);
        byte_to_bitstr(textbyte, buffer);
    }

    file.close();
    newfile.close();

    return 0;
}
