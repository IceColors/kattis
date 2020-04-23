#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, b;
	vector<int> a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> b;
		a.push_back(b);
	}
	
	int highestIndex = -1;
	for (int i = 1; i < 7; i++) {
		if (count(a.begin(), a.end(), i) == 1) {
			highestIndex = distance(a.begin(), find(a.begin(), a.end(), i));
		}
	}
	if (highestIndex != -1) cout << highestIndex + 1;
	else cout << "none";
	cin >> b;

	return 0;
}