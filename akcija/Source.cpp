#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int n, b;
	cin >> n;
	vector<int> a;
	while (n--) {
		cin >> b;
		a.push_back(b);
	}
	sort(a.rbegin(), a.rend());
	long cost = 0;
	for (int i = 1; i <= a.size(); i++) {
		if (i % 3) cost += a[i - 1];
	}
	cout << cost;
	return 0;
}