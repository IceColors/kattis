#include <iostream>

using namespace std;

long long modMmult(long long x, long long y, long long m) {
	if (x == 0 || y == 0) {
		return 0;
	}
	else if (x == 1) { return y % m; }
	else if (y == 1) { return x % m; }
	else if ((x | y) < ((1UL << 32) - 1UL)) { return (x * y) % m; }

	if (x > y) swap(x, y);

	long long val = 0;

	x %= m;
	while (y) {
		if (y & 1) {
			val = (val + x) % m;
		}

		x = (2 * x) % m;
		y >>= 1;
	}

	return val;
}

long long modInv(long long x, long long m) {
	long long a = 0, aa = 1, b = m, bb = x;

	while (bb) {
		long long q = b / bb;
		long long tempaa = aa;
		aa = a - q * aa;
		a = tempaa;

		long long tempbb = bb;
		bb = b - q * bb;
		b = tempbb;
	}

	if (b > 1) {
		return -1;
	}
	if (a < 0) {
		a += m;
	}

	return a;
}

int main() {
	unsigned long long n, t;
	while (cin >> n >> t && n && t) {
		while (t--) {
			unsigned long long x, y;
			char op;
			cin >> x >> op >> y;

			if (op == '+') {
				cout << (x + y) % n << '\n';
			}

			else if (op == '-') {
				cout << (x + n - y) % n << '\n';
			}

			else if (op == '*') {
				cout << modMmult(x, y, n) << '\n';
			}

			else if (op == '/') {
				long long yy = modInv(y, n);
				if (yy == -1) {
					cout << -1 << '\n';
					continue;
				}

				cout << modMmult(x, yy, n) << '\n'; 
			}
		}
	}

}