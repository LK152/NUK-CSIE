#include "iostream"
#include "queue"

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0;i<n;i++) {
        queue<int> q;
        int x, gap = 2;
        cin >> x;
        for (int j = 1;j<=x;j++) {
            q.push(j);
        }
        while (q.size() > 3) {
            size_t len = q.size();
            if (!(gap % 2)) {
                for (int j = 0;j<len/2;j++) {
                    q.push(q.front());
                    q.pop();
                    q.pop();
                }
                if (len % 2) {
                    q.push(q.front());
                    q.pop();
                }
            } else {
                for (int j = 0;j<len/3;j++) {
                    q.push(q.front());
                    q.pop();
                    q.push(q.front());
                    q.pop();
                    q.pop();
                }
                while (len%3) {
                    q.push(q.front());
                    q.pop();
                    len--;
                }
            }
            gap = gap == 2 ? 3 : 2;
        }
        while (q.size() != 1) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << q.front() << "\n";
    }

    return 0;
}