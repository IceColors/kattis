#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	double a, b, c;

	while (n--) {
		cin >> a >> b >> c;
		if ((a + b == c) || (a-b == c) || (b-a ==c ) || (a*b == c) || (a/b == c) || (b/a == c)) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}