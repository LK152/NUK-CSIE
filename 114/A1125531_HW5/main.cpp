#include "HuffmanTrie.h"
#include "iostream"
#include "string"

using namespace std;

int main() {
    int n, freq[26] = {0}, k;
    string wrds[1000];

    cin >> n;
    k = n;
    while (n--) {
        string in;
        cin >> in;
        wrds[n] = in;
        for (char c : in) {
            freq[c - 'a']++;
        }
    }

    Huffman hfm;
    hfm.build(freq);

    char codes[256][256];
    hfm.getCodes(codes);

    for (char c = 'a'; c <= 'z'; c++) {
        if (freq[c - 'a'])
            cout << '\'' << c << '\'' << ": " << codes[c] << "\n";
    }

    for (int i = 0; i < k; i++) {
        hfm.insertBitString(hfm.encode(wrds[i], codes));
    }

    cin >> n;
    while (n--) {
        string in, cod;
        cin >> in;
        // for (char c : in) {
        //     cod.append(codes[c]);
        // }
        string res[10];
        int fnd = hfm.autocomplete(hfm.encode(in, codes), res);
        cout << "Autocomplete '" << in << "':\n";
        for (int i = 0; i < fnd; i++) {
            if (res[i] != "")
                cout << res[i] << "\n";
        }
        string fres[10];
        int ffnd = hfm.fuzzyAutocomplete(in, fres);
        cout << "Fuzzy '" << in << "':\n";
        for (int i = 0; i < fnd; i++) {
            if (fres[i] != "")
                cout << fres[i] << "\n";
        }
        // cout << cod << "\n";
        // cout << hfm.decode(cod) << "\n";
    }

    return 0;
}