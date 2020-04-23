#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {

	vector<int> primes(32001, true);
	primes[0] = primes[1] = true;
	for (int i = 2; i*i < 32000; i++) {
		if(primes[i]){
			for (int j = 2 * i; j <= 32000; j += i) {
				primes[j] = false;
			}
			
		}
	}


	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		int ways = 0;
		vector<pair<int, int> > combos;
		for (int i = 2; i <= ceil(a/2.0); i++) {
			if (primes[i] && primes[a-i]) {
				ways++;
				combos.push_back(pair<int, int>(i, a-i));
			}
		}
		cout << a << " has " << ways << " representation(s)\n";
		for (int i = 0; i < combos.size(); i++) {
			cout << combos[i].first << "+" << combos[i].second << "\n";
		}
		cout << "\n";
	}
	return 0;
}