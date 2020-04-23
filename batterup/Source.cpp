#include <iostream>

using namespace std;

int main() {
	int n;
	
	int s_atbat = 0;

	cin >> n;
	int n_atbat = n;
	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == -1) {
			n_atbat--;
			continue;
		}
		s_atbat += a;
	}
	cout.precision(9);
	cout << fixed << (double)s_atbat / n_atbat;
	cin >> a;

	return 0;
}