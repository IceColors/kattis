#include <iostream>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a;
	cin >> a;
	unsigned long long qCount = 0;
	unsigned long long count0 = 0;
	unsigned long long count1 = 0;
	unsigned long long inversions = 0;

	unsigned long long mod = 1000000007;
	long long exp = 1;
	long long prevExp = 1;

	for (long long i = 0; i < a.size(); i++) {
		if (a[i] == '?') {

			inversions = (inversions * 2) % mod + (count1 * exp) % mod;
			inversions += qCount * prevExp;

			qCount += 1;

			prevExp = exp;
			exp *= 2;
			exp = exp % mod;

		}
		else if (a[i] == '0') {
			if (qCount != 0) {
				inversions += (count1 * exp) % mod + (prevExp * qCount) % mod;

				
			}
			
			else {
				inversions += count1;
			}

			count0 += 1;
			count0 = count0 % mod;
		}
		else if (a[i] == '1') {
			count1 += 1;
			count1 = count1 % mod;
		}
		inversions = inversions % 1000000007;

	}

	cout << inversions % 1000000007;
	cin >> a;
	return 0;
}