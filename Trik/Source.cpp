#include <iostream>

using namespace std;

int main() {

	char a;
	int number = 1;

	while (cin >> a && (a == 'A' || a == 'B' || a == 'C')) {
		if (a == 'A') {
			if (number == 1) number = 2;
			else if (number == 2) number = 1;
		}
		else if (a == 'B') {
			if (number == 2) number = 3;
			else if (number == 3) number = 2;
		}
		else if (a == 'C') {
			if (number == 1) number = 3;
			else if (number == 3) number = 1;
		}

	}
	cout << number;
	return 0;
}