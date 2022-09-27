#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;

	for (int i = 0; i < 1000000000; i++) {
		long long newNumber = n + i;
		long long copyNumber = newNumber;
		int sum = 0;
		while (copyNumber > 0) {
			int digit = copyNumber % 10;
			copyNumber /= 10;
			sum += digit;
		}
		if (newNumber % sum == 0)
		{
			cout << newNumber << endl;
			break;
		}
	}
}