#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	cin >> a;
	int count = 0;
	int i;
	int alimit = sqrt(a);
	bool found;
	while (true) {
		found = false;
		for (i = 2; i <= alimit; i++) {
			if (a%i == 0) {
				found = true;
				count++;
				a /= i;
				alimit = sqrt(a);
				break;
			}
		}
		if (a == 1) break;
		if (!found) {
			count++;
			break;
		}
		
	}
	cout << count;
	cin >> a;

	return 0;
}