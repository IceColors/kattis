#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n;
	while (cin >> n && n != 0) {
		long long sum = 0;
		vector<long long> moneys;
		for (long long i = 0; i < n; i++) {
			double money;
			cin >> money;
			sum += round(money*100);
			moneys.push_back(round(money * 100));
		}

		long avg = sum / n;
		long rest = sum % n;

		long long ex = 0;
		int peopleOver = 0;


		for (int i = 0; i < n; i++) {
			if (moneys[i] > avg) {
				ex += moneys[i] - avg;
				peopleOver++;
			}
		}

		if (peopleOver >= rest) {
			ex -= rest;
		}
		else {
			ex -= peopleOver;
		}

		cout.precision(2);
		cout << fixed << "$" << double(ex)/100 << endl;
	}
}