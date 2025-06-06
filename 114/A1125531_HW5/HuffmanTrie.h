#ifndef HUFFMANTRIE_H
#define HUFFMANTRIE_H

#include "iostream"
#include "string"

using namespace std;

struct TrieNode {
    TrieNode* next[2];
    char* bitString;
    bool isEnd;

    TrieNode() : isEnd(false) {
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

class Huffman {
   private:
    HuffmanNode* root;

    void buildHuffmanTree(int frequencies[26]);
    void generateCodes(HuffmanNode* node, string str, char codes[256][256]);
    void deleteTree(HuffmanNode* node);

   public:
    Huffman() : root(nullptr) {}
    ~Huffman() {
        deleteTree(root);
    }

    void build(int frequencies[26]);
    void getCodes(char codes[256][256]);
    void insertBitString(string bstr);
    void collect(TrieNode* node, string* res, int& cnt, int lim);
    void collectFuzzy(TrieNode* node, string* res, int& cnt, string target, int lim);
    int editDistance(string a, string b);
    int autocomplete(string pre, string* res);
    int fuzzyAutocomplete(string target, string* res);
    string encode(string s, char codes[256][256]);
    string decode(string encoded);
    bool fuzzyPrefixMatch(string word, string target);
};

#endif