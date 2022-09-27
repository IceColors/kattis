#include <iostream>

using namespace std;

int main() {
	int g, s, c;
	cin >> g >> s >> c;

	int sum = g * 3 + s * 2 + c;
	if (sum > 7) cout << "Province or Gold" << endl;
	else if (sum > 5) cout << "Duchy or Gold" << endl;
	else if (sum > 4) cout << "Duchy or Silver" << endl;
	else if (sum > 2) cout << "Estate or Silver" << endl;
	else if (sum > 1) cout << "Estate or Copper" << endl;
	else cout << "Copper" << endl;
}