#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

long long facN(long long a) {
	if (a == 1 || a == 0) return 1;
	long double sum = log10(sqrt(2 * M_PI * a)) + a * log10(a/M_E);


	return floor(sum) + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	while (cin >> n) {
		cout << facN(n) << '\n';
	}
	return 0;
}