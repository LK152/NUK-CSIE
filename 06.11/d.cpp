#include "iostream"
#include "vector"
#include "string"

using namespace std;

int isCool(string s) {
	int arr[26] = {0}, occ = 0;
	for (int i = 0;i<s.size();i++) {
		arr[s[i]-'a']++;
	}
	for (int i = 0;i<26;i++) {
		if (arr[i]) occ++;
		for (int j = i+1;j<26;j++) {
			if (arr[i] == arr[j] && arr[i] != 0) return 0;
		}
	}
	
	if (occ == 1) return 0;
	
	return 1;
}

int main() {
	int n, cs = 1;
	while (cin >> n) {
		int ans = 0;
		string s;
		while (n--) {
			cin >> s;
			if (isCool(s)) ans++;
		}
		cout << "Case " << cs++ << ": " << ans << "\n";
	}
	return 0;
}