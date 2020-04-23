#include <iostream>

using namespace std;

int main() {

	int a, b, c;
	int tot = 0;

	cin >> a >> b;

	while (b--) {
		cin >> c;
		tot += a - c;
	}
	cout << tot + a;

	return 0;
}