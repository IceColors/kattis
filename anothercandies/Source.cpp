#include <iostream>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int mod = n;
		unsigned long long a;
		int rest = 0;
		while (n--) {
			cin >> a;
			rest = (rest + a) % mod;
		}
		if (rest == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}