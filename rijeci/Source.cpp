#include <iostream>

using namespace std;

int main() {
	int k;
	int a = 1;
	int tempb;
	int b = 0;
	cin >> k;
	while(k--) {

		tempb = b + a;
		a = b;
		b = tempb;
	}
	cout << a << " " << b;
}