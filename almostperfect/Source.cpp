#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long p, sum;
	while (cin >> p) {
		sum = 1;
		int base = floor(sqrt(p));
		for (long long i = 2; i <= base; i++) {
			if (p % i == 0) {
				sum += i;
				if(p/i != i) sum += p / i;
			}
			
		}
		if (sum == p) cout << p << " perfect" << endl;
		else if (abs(p-sum) <= 2) cout << p << " almost perfect" << endl;
		else cout << p <<" not perfect" << endl;
	}
	return 0;
}