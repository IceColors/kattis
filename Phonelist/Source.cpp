#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int a, b;
	string c;

	cin >> a;
	while (a--) {
		vector<string> numbers;
		bool consistent = true;
		cin >> b;
		while (b--) {
			cin >> c;
			numbers.push_back(c);
		}
		sort(numbers.begin(), numbers.end());

		for (int i = 0; i < numbers.size() - 1; i++) {
			if (numbers[i+1].compare(0, numbers[i].length(), numbers[i]) == 0) {
				consistent = false;

			}
		}

		if (consistent) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	cin >> a;
	return 0;
}