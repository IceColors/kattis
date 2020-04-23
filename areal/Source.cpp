#include <iostream>
#include <math.h>
#include <iomanip> 

using namespace std;

int main() {
	long double a;
	cin >> a;
	a = sqrt(a) * (long double)4.0;
	cout << setprecision(20) << a;

	return 0;
}