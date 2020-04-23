#include <iostream>

using namespace std;

int main() {
	double c;
	int l;
	cin >> c;
	cin >> l;
	double cost = 0;
	double width;
	double height;

	while (l--) {
		cin >> width >> height;
		cost += width * height * c;
	}
	cout.precision(9);
	cout << fixed << cost;


	return 0;
}