#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main() {
	int a, b;
	cin >> a;
	cin >> b;

	cout << ceil(a / sin((3.14159265359 * b) /180));

	cin >> a;
	return 0;
}