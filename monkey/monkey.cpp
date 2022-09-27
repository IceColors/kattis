#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long double d, w, c;
	cin >> d >> w >> c;
	long double tot = 0;
	long double full = floor(w / c);
	long double over = (w / c) - full;
	//cout << "full= " << full << " over= " << over << endl;
	tot += over / (2 * full + 1);
	for (int i = 1; i <= full; i++) {
		tot += 1.0 / (2 * i - 1);
	}
	long double f = tot * c - d;
	cout.precision(15);
	if (f < 0) {
		cout << 0 << endl;
	}
	
	else cout << f << endl;
}