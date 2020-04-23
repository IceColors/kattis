#include <iostream>
#include <math.h>

using namespace std;


int main() {
	long long m, n;
	int t;
	cin >> m >> n >> t;

	switch (t) {
	case 1: { long long num = 1;
			for (long long i = 0; i < n; i++) {
				num *= i + 1;
				if (num > m) goto TLE;
				}
			cout << "AC";
			break;
			TLE:;
			cout << "TLE";
			break;
	}	
	case 2: { if (m >= pow(2, n)) cout << "AC";
			else cout << "TLE";
			break; }
	case 3: { if (m >= pow(n, 4)) cout << "AC";
			else cout << "TLE";
			break; }
	case 4: { if (m >= pow(n, 3)) cout << "AC";
			else cout << "TLE";
			break; }
	case 5: { if (m >= pow(n, 2)) cout << "AC";
			else cout << "TLE";
			break; }
	case 6: { if (m >= n * log2l(n)) cout << "AC";
			else cout << "TLE";
			break; }
	case 7: { if (m >= n) cout << "AC";
			else cout << "TLE";
			break; }
	}
	cin >> n;
	return 0;
}