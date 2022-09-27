#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>


using namespace std;

int main() {
	int N;
	cin >> N;
	cout.precision(20);
	while (N--) {
		int n, l, d, g;
		cin >> n >> l >> d >> g;
		double ngon = (n * l * l) / (4 * tan(M_PI / n));
		double square = l * d * g;
		ngon += square * n; // utvidelsene til sidene
		double cornerCircle = M_PI * (d * g) * (d * g) / n;
		ngon += cornerCircle * n;
		cout << ngon << endl;
	}
}