#include "iostream"
#include "set"

using namespace std;

bool isSurprising(string str) {
    string temp;
    set<string> set;

    if (str.length() == 1) return 1;

    for (int d = 0;d<=str.length()-2;d++) {
        set.clear();
        int k = 0;
        while (1) {
            temp = str[k];
            temp += str[k+d+1];
            if (!set.count(temp)) set.insert(temp);
            else return 0;
            if (k+d+1 == str.length()-1) break;
            k++;
        }
    }

    return 1;
}

int main() {
    string str;

    while (1) {
        getline(cin, str);
        if (str[0] == '*') return 0;
        cout << str << " is" << (isSurprising(str) ? " " : " NOT ") << "surprising.\n";
    }


    return 0;
}