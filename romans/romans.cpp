#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double x;
	cin >> x;
	cout << setprecision(0) << fixed << x * 1000 * (5280.0 / 4854) << endl;
}