#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, g;
	cin >> n;

	for (int i = 0; i < n; i++) {
		unsigned long long c;
		cin >> g;
		
		vector<unsigned long long> people;

		for (int j = 0; j < g; j++) {
			cin >> c;
			people.push_back(c);
		}

		unsigned long long alone;

		sort(people.begin(), people.end());

		for (int j = 0; j < g; j += 2) {
			if (j + 1 == g || people[j] != people[j + 1]) {
				alone = people[j];
				break;
			}
		}
		
		cout << "Case #" << i + 1 << ": " << alone << endl;
	}


	return 0;
}