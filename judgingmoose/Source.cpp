#include <iostream>

using namespace std;


int main() {
	int a, b;

	cin >> a >> b;

	if (!a && !b) cout << "Not a moose";
	else if (a != b) cout << "Odd " << (a>b?a:b) * 2;
	else cout << "Even " << a * 2;

	cin >> a;
	return 0;
}