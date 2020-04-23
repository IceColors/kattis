#include <iostream>

using namespace std;

int main() {
	double emma = 0, gunnar = 0;
	int a, b;
	double propa;
	double propb;
	cin >> a >> b;
	propa = (a + b) / 2.0;
	cin >> a >> b;
	propb = (a + b) / 2.0;
	gunnar = (propa + propb) / 2.0;
	cin >> a >> b;
	propa = (a + b) / 2.0;
	cin >> a >> b;
	propb = (a + b) / 2.0;
	emma = (propa + propb) / 2.0;
	if (emma - gunnar > 0.0001) cout << "Emma";
	else if (gunnar - emma > 0.0001) cout << "Gunnar";
	else cout << "Tie";
	return 0;
}