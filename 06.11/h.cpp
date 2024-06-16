#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main() {
	int n;
	vector<string> v;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "Sleep") {
			string name;
			cin >> name;
			v.push_back(name);
		}
		if (cmd == "Kick") {
			if (v.size()) v.pop_back();
		}
		if (cmd == "Test") {
			if (v.size()) cout << v.back() << "\n";
			else cout << "Not in a dream\n";
		}
	}
	
	return 0;
}