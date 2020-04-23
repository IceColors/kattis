#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	double wholePizza = pow(a, 2) * M_PI;
	double cheezyPizza = pow(a-b, 2) * M_PI;
	cout << setprecision(9);
	cout << fixed << (cheezyPizza / wholePizza) * 100;



	return 0;
}