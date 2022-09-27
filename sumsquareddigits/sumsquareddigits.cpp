#include <iostream>

using namespace std;

int main() {
	int p;
	cin >> p;

	for (int i = 1; i <= p; i++) {
		uint32_t n;
		int b;
		cin >> b >> b >> n;
		int sum = 0;
		for (unsigned long long j = b; n > 0; j *= b) {
			sum += ((n % j) / (j / b)) * ((n % j) / (j / b));
			n -= n % j;
		}
		cout << i << " " << sum << endl;
	}
}