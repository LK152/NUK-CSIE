#include "iostream"
#include "vector"
#include "string"

using namespace std;

int interpret(string s) {
	int match = 0;
	string ans[2] = {"one", "two"};
	if (s.size() == 3) {
		for (int i = 0;i<2;i++) {
			match = 0;
			for (int j = 0;j<3;j++) {
				if (s[j] == ans[i][j]) match++;
			}
			if (match >= 2) return i+1;
		}
	}
	
	return 3;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		cout << interpret(s) << "\n";
	}
	
	return 0;
}