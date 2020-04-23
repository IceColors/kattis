#include <iostream>

using namespace std;

int main() {
	int n;
	double life = 0;
	double year;
	double qual;
	cin >> n;
	while (n--) {
		cin >> qual >> year;
		life += year * qual;
	}
	cout.precision(9);
	cout << fixed << life;


	return 0;
}