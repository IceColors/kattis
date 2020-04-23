#include <iostream>
#include <climits>

using namespace std;

int main() {
	int n, p;
	cin >> n >> p;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
	}
	if (p == 100 && sum != p * n) {
		cout << "impossible";
		return 0;
	}
	for (int i = 0; i != INT_MAX; i++) {
		if ((sum + 100 * i) >= p * (n + i)) {
			cout << i;
			return 0;
		}
	}
	cout << "impossible";
}