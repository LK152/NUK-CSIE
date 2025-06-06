#include "HuffmanTrie.h"
#include "iostream"
#include "string"

using namespace std;

void Huffman::buildHuffmanTree(int frequencies[26]) {
    HuffmanNode** nodes = new HuffmanNode*[26];
    int size = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        if (frequencies[c - 'a'] > 0) {
            nodes[size++] = new HuffmanNode(c, frequencies[c - 'a']);
        }
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (nodes[j]->freq > nodes[j + 1]->freq ||
                (nodes[j]->freq == nodes[j + 1]->freq && nodes[j]->ch > nodes[j + 1]->ch)) {
                HuffmanNode* temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size - 1; i++) {
        int min1 = -1, min2 = -1;
        for (int j = 0; j < size; j++) {
            if (nodes[j] != nullptr) {
                if (min1 == -1 || nodes[j]->freq < nodes[min1]->freq) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == -1 || nodes[j]->freq < nodes[min2]->freq) {
                    min2 = j;
                }
            }
        }

        HuffmanNode* newNode = new HuffmanNode('\0', nodes[min1]->freq + nodes[min2]->freq);
        newNode->left = nodes[min1];
        newNode->right = nodes[min2];

        nodes[min1] = newNode;
        nodes[min2] = nullptr;
    }

    for (int i = 0; i < 26; ++i) {
        if (nodes[i] != nullptr) {
            root = nodes[i];
            break;
        }
    }
    delete[] nodes;
}

void Huffman::generateCodes(HuffmanNode* node, string str, char codes[256][256]) {
    if (node == nullptr)
        return;

    if (node->left == nullptr && node->right == nullptr) {
        strcpy(codes[node->ch], str.c_str());
    }

    generateCodes(node->left, str + "0", codes);
    generateCodes(node->right, str + "1", codes);
}

void Huffman::deleteTree(HuffmanNode* node) {
    if (node == nullptr)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void Huffman::build(int freq[26]) {
    buildHuffmanTree(freq);
}

void Huffman::getCodes(char codes[256][256]) {
    generateCodes(root, "", codes);
}

TrieNode* bitTrieRoot = new TrieNode();

void Huffman::insertBitString(string bstr) {
    TrieNode* cur = bitTrieRoot;
    for (int i = 0; bstr[i]; i++) {
        int idx = bstr[i] - '0';
        if (!cur->next[idx])
            cur->next[idx] = new TrieNode();
        cur = cur->next[idx];
    }
    if (!cur->bitString) {
        cur->bitString = new char[bstr.size() + 1];
        strcpy(cur->bitString, bstr.c_str());
    }
    cur->isEnd = true;
}

string Huffman::encode(string s, char codes[256][256]) {
    string result = "";
    for (int i = 0; s[i]; i++) {
        unsigned char c = s[i];
        if (codes[c][0] != '\0') {
            result += codes[c];
        }
    }
    return result;
}

string Huffman::decode(string encoded) {
    string decoded = "";
    HuffmanNode* current = root;
    for (size_t i = 0; i < encoded.size(); ++i) {
        if (!current)
            break;

        if (encoded[i] == '0')
            current = current->left;
        else if (encoded[i] == '1')
            current = current->right;
        else
            return "";

        if (current->left == nullptr && current->right == nullptr) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}

void Huffman::collect(TrieNode* node, string* results, int& cnt, int lim) {
    if (!node || cnt >= lim)
        return;
    if (node->isEnd && node->bitString) {
        results[cnt++] = decode(node->bitString);
    }
    collect(node->next[0], results, cnt, lim);
    collect(node->next[1], results, cnt, lim);
}

int Huffman::autocomplete(string prefixBitStr, string* res) {
    TrieNode* cur = bitTrieRoot;
    for (int i = 0; prefixBitStr[i]; i++) {
        int idx = prefixBitStr[i] - '0';
        if (!cur->next[idx])
            return 0;
        cur = cur->next[idx];
    }
    int count = 0;
    collect(cur, res, count, 10);
    return count;
}

// Helper to compute edit distance between two strings (your existing function)
int Huffman::editDistance(string a, string b) {
    int dp[32][32];
    int m = (int)a.length(), n = (int)b.length();
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int mi = dp[i - 1][j];
                if (dp[i][j - 1] < mi)
                    mi = dp[i][j - 1];
                if (dp[i - 1][j - 1] < mi)
                    mi = dp[i - 1][j - 1];
                dp[i][j] = mi + 1;
            }
    return dp[m][n];
}

bool Huffman::fuzzyPrefixMatch(string word, string target) {
    int len = (int)target.size();
    if ((int)word.size() < len)
        return false;  // word too short

    string prefix = word.substr(0, len);
    return editDistance(prefix, target) <= 1;
}

void Huffman::collectFuzzy(TrieNode* node, string* results, int& count, string target, int limit) {
    if (!node || count >= limit)
        return;

    if (node->isEnd && node->bitString) {
        string decoded = decode(node->bitString);
        if (fuzzyPrefixMatch(decoded, target)) {
            results[count++] = decoded;
        }
    }

    collectFuzzy(node->next[0], results, count, target, limit);
    collectFuzzy(node->next[1], results, count, target, limit);
}

int Huffman::fuzzyAutocomplete(string target, string* res) {
    int count = 0;
    collectFuzzy(bitTrieRoot, res, count, target, 10);
    return count;
}