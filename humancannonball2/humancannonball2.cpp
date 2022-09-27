#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		double v0, d, x1, h1, h2;
		cin >> v0 >> d >> x1 >> h1 >> h2;
		double t = x1/(v0 * cos(d * M_PI / 180.0));
		double y = v0 * t * sin(d * M_PI / 180.0) - 0.5 * 9.81 * t * t;
		if (y - h1 >= 1 && h2 - y >= 1) {
			cout << "Safe" << endl;
		}
		else cout << "Not Safe" << endl;
	}
}