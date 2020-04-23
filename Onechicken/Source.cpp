#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	a = b - a;

	if (a > 0) {
		if (a == 1) cout << "Dr. Chaz will have 1 piece of chicken left over!";
		else cout << "Dr. Chaz will have " << a << " pieces of chicken left over!";
	}

	else if (a < 0) {
		if (a == -1) cout << "Dr. Chaz needs 1 more piece of chicken!";
		else cout << "Dr. Chaz needs " << -a << " more pieces of chicken!";
	}


	return 0;
}