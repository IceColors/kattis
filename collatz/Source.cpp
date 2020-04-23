#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void collatz(vector<long>* pv, long n) {
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			pv->push_back(n);
		}
		else {
			n = n * 3 + 1;
			pv->push_back(n);
		}
	}
}

int main() {
	long a, b;
	while (cin >> a >> b && a && b) {
		vector<long> collatza;
		vector<long> collatzb;
		vector<long>::iterator it;

		collatza.push_back(a);
		collatzb.push_back(b);
		collatz(&collatza, a);
		collatz(&collatzb, b);
		long aSteps;
		long bSteps;
		long meetingPlace;

		for (long i = 0; i < collatza.size(); i++) {
			it = find(collatzb.begin(), collatzb.end(), collatza[i]);
			if (it != collatzb.end()) {
				meetingPlace = collatza[i];
				aSteps = i;
				bSteps = it - collatzb.begin();
				break;
			}
		}
		cout << a << " needs " << aSteps << " steps, ";
		cout << b << " needs " << bSteps << " steps, ";
		cout << "they meet at " << meetingPlace << endl;
	}

	return 0;
}