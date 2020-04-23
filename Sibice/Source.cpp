#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a, b, c, e, f;
	cin >> a >> b >> c;
	e = sqrt(pow(b, 2) + pow(c, 2));
	for (int i = 0; i < a; i++) {
		cin >> f;
		if (f <= e) cout << "DA\n";
		else cout << "NE\n";
	}


	return 0;
}