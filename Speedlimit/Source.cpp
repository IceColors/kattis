#include <iostream>

using namespace std;

int main() {

	int a, b, c, lastc, tot;

	while (cin >> a && a != -1) {
		tot = 0;
		lastc = 0;
			
		for (int i = 0; i < a; i++) {
			cin >> b >> c;
			c -= lastc;
			tot += b * c;
			lastc += c;
		}
		cout << tot << " miles" << endl;
	}

	return 0;
}