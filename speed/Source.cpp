#include <iostream>
#include <vector>
#define DBL_MAX 1.7976931348623158e+308
using namespace std;

int main() {

	int n, t, a;
	vector<int> d;
	vector<int> s;

	cin >> n >> t;
	double min = DBL_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a;
		d.push_back(a);
		cin >> a;
		min = a < min ? a : min;
		s.push_back(a);
	}
	min = -min;
	double max = 1001000.0;
	double mid, sum;

	while (max - min > 0.000000001) {
		mid = (max + min) / 2;
		sum = 0.0;
		for (int i = 0; i < n; i++) {
			sum += d[i] / (s[i] + mid);
		}
		if (sum > t) min = mid;
		else if (sum < t) max = mid;
		else break;
	}
	cout.precision(9);
	cout << fixed << mid;
	cin >> n;

	return 0;
}