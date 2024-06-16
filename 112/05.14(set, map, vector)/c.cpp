#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n, m;
    vector<char> v;

    while (cin >> n >> m) {
        v.clear();
        for (int i = 0;i<n*2;i++) v.push_back('G');
        int b = 0, idx = 0, cnt = 1;
        while (b != n) {
            if (v[idx] == 'G' && cnt == m) {
                v[idx] = 'B';
                b++;
                cnt = 1;
            }
            if (v[idx] == 'B' && cnt == m) {
                idx++;
                if (idx + 1 >= n*2) idx = 0;
                continue;
            }
            if (idx + 1 >= n*2) idx = 0; 
            idx++;
            cnt++;
        }

        for (auto it = v.begin();it != v.end();it++) {
            cout << *it;
        }
        cout << "\n\n";
    }

    return 0;
}