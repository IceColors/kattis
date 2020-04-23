#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a;
	while (a--) {
		cin >> b;
		if (b % 2) cout << b << " is odd" << endl;
		else cout << b << " is even" << endl;

	}
	
	return 0;
}