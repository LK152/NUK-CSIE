#include "iostream"
#include "vector"
#include "string"

using namespace std;

string ans(int n) {
	int sum = 0;
	for (int i = 1;i<=n/2;i++) {
		if (n%i == 0) sum += i;
	}
	
	if (sum > n) return "abundant\n";
	if (sum < n) return "deficient\n";
	
	return "perfect\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << ans(n);
	}
	
	return 0;
}