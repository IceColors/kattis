#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	double a2w = pow(2.0, -5.0 / 4.0);
	double a2h = pow(2.0, -3.0 / 4.0);

	vector<int> paper;
	int a;
	double tot = 0;
	int price = 1;
	bool possible = false;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		tot += price * a2h;
		a2h /= 2;
		swap(a2h, a2w);
		price *= 2;
		price -= a;

		if (price <= 0) {
			possible = true;
			break;
		}

	}

	cout.precision(9);
	if (possible) cout << fixed << tot;
	else cout << "impossible";

	cin >> a;
	return 0;
}