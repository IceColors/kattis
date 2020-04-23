#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q, x;
	cin >> n >> q;
	vector<bool> primes(n + 1, true);
	int count = 0;
	primes[0] = false;
	primes[1] = false;

	int nsqrt = sqrt(n);

	for (int i = 2; i <= nsqrt; i++) {
		if (primes[i]) {
			count++;
			for (int j = i * 2; j <= n; j += i) {
				primes[j] = false;
			}
		}
	}
	for (int i = nsqrt + 1; i <= n; i++) {
		if (primes[i]) count++;
	}

	cout << count << '\n';

	while (q--) {
		cin >> x;
		cout << primes[x] << '\n';
	}


	return 0;
}