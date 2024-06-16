#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main() {
	int p;
	vector<int> v;
	cin >> p;
	while (p--) {
		v.clear();
		int n;
		string s;
		cin >> n >> s;
		while (n--) {
			int a;
			string cmd;
			cin >> cmd;
			if (cmd == "IN") {
				cin >> a;
				v.push_back(a);
			}
			if (cmd == "OUT") {
				if (v.size() == 0) {
					cout << "None\n";
					continue;
				}
				if (s == "FIFO") {
					cout << *v.begin() << "\n";
					v.erase(v.begin());
				}
				if (s == "FILO") {
					cout << *(v.begin() + v.size()-1) << "\n";
					v.pop_back();
				}
			}
		}
	}
				
	

	return 0;
}