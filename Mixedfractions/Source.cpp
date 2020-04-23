#include <iostream>

using namespace std;

int main() {
	int a, b;
	while (cin >> a && cin >> b && a && b) {
		int whole = 0;
		for (a; a >= b; a -= b) {
			whole++;
		}
		cout << whole << " " << a << " / " << b << endl;
	}

	return 0;
}