#include <iostream>

using namespace std;

int main() {
	int n, t, min;
	int ind = -1;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> min;
		t -= min;
		if (ind == -1 && t < 0) {
			ind = i;
		}
	}
	if (ind == -1) cout << n;
	else cout << ind;
	return 0;
}