#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int sum = 0;
	sum += x * 4 + y * 3;
	if (sum % 2) cout << "impossible" << endl;
	else cout << "possible" << endl;
}