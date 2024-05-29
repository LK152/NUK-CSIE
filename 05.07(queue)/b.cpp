#include "iostream"
#include "queue"

using namespace std;

int main() {
    int t, n, x, scenario = 1, id[1000000];
    string cmd;
    while (1) {
        queue<int> q, team[1000];
        cin >> t;
        if (!t) return 0;
        for (int i = 1;i<=t;i++) {
            cin >> n;
            for (int j = 0;j<n;j++) {
                cin >> x;
                id[x] = i;
            }
        }
        cout << "Scenario #" << scenario << "\n";
        while (cin >> cmd) {
            if (cmd[0] == 'S') break;

            if (cmd[0] == 'E') {
                cin >> x;
                if (team[id[x]].empty()) q.push(id[x]);
                team[id[x]].push(x);
            }

            if (cmd[0] == 'D') {
                cout << team[q.front()].front() << "\n";
                team[q.front()].pop();
                if (team[q.front()].empty()) q.pop();
            }
        }
        cout << "\n";
        while (!q.empty()) {
            while (!team[q.front()].empty()) team[q.front()].pop();
            q.pop();
        }
        scenario++;
    }

    return 0;
}