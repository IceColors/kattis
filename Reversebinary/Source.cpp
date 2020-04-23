#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int a;
	vector<int> bin;
	cin >> a;
	for (int i = 0; a != 0; i++) {
		bin.push_back(a % 2);
		a /= 2;

	}
	a = 0;
	for (int i = 0; i < bin.size(); i++) {
		a += bin[i] * pow(2, bin.size() - 1 - i);
	}
	cout << a;

	return 0;
}