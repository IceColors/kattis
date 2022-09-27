#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int mi = 100, ma = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			mi = min(mi, a);
			ma = max(ma, a);
		}
		cout << (ma - mi) * 2 << endl;

	}
}