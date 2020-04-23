#include <iostream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int main() {
	int n;
	int number = 0;

	while (cin >> n) {
		number++;
		int a;
		int smallest = INT_MAX;
		int largest = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> a;
			smallest = a < smallest ? a : smallest;
			largest = a > largest ? a : largest;
		}
		cout << "Case " << number << ": " << smallest << " " << largest << " " << largest - smallest << endl;
	}

	return 0;
}