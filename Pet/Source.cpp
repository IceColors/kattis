#include <iostream>

using namespace std;

int main() {

	int a, b, tot, winperson;
	int wintot = 0;

	for (int i = 1; i < 6; i++) {
		tot = 0;
		for (int j = 0; j < 4; j++) {
			cin >> a;
			tot += a;
		}
		if (tot > wintot) {
			wintot = tot;
			winperson = i;
		}
	}
	cout << winperson << " " << wintot;

	return 0;
}