#include <iostream>

using namespace std;

int main() {

	int n, base;
	cin >> n;
	base = 2;
	for (int i = 1; i <= n; i++) {
		base += base - 1;
	}
	cout << base * base;
	cin >> n;
	return 0;
}