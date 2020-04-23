#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int days = 1;
	for (int i = 1; i < n; i+=i) {
		days++;
	}
	cout << days;

	return 0;
}