#include "iostream"
#include "map"
#include "string"

using namespace std;

int main() {
    int n, m, p;
    string s;
    map<string, int> mp;
    while (cin >> n) {
        for (int i = 0;i<n;i++) {
            cin >> s;
            mp[s] = 0;
        }
        cin >> m;
        for (int i = 0;i<m;i++) {
            int t = 0;
            for (int j = 0;j<n;j++) {
                cin >> p >> s;
                mp[s] += p;
            }
            map<string, int>::iterator it;
            for (it = mp.begin();it!=mp.end();it++) {
                if (it->second > mp["memory"]) ++t;
            }
            cout << t+1 << "\n";
        }
        mp.clear();
    }

    return 0;
}