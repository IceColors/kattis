#include <iostream>

using namespace std;

int main() {
	int n, r, e, c;

	cin >> n;

	while (n--) {
		cin >> r >> e >> c;
		if (e - r == c) cout << "does not matter" << endl;
		else if (e - r > c) cout << "advertise" << endl;
		else cout << "do not advertise" << endl;
	}

	return 0;
}