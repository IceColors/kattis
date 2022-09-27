#include <iostream>

using namespace std;

int main() {
	long long l, n;
	cin >> l >> n;
	int times = 1;
	while (l % n) {
		n -= l % n;
		times++;
	}
	cout << times;
}