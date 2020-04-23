#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	string a;
	long long n;
	cin >> a;

	if (a.length() < 4) {
		n = stoll(a);
		switch (n) {
		case 1: cout << "1\n";
			break;
		case 2: cout << "2\n";
			break;
		case 6: cout << "3\n";
			break;
		case 24: cout << "4\n";
			break;
		case 120: cout << "5\n";
			break;
		case 720: cout << "6\n";
			break;
		}
	}
	else {
		int current = 6;
		double sum = 4 * log10(2) + 2 * log10(3) + log10(5);
		while(sum < a.length()) {
			sum += log10(++current);
		}
		cout << current - 1 << endl;
	}
	cin >> a;


	return 0;
}