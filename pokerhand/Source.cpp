#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	string a;
	string b;
	for (int i = 0; i < 5; i++) {
		cin >> b;
		a += b[0];
	}
	int highest = 0;
	int current;
	for (int i = 0; i < 5; i++) {
		current = count(a.begin(), a.end(), a[i]);
		if (current > highest) highest = current;
	}
	cout << highest;

	return 0;
}