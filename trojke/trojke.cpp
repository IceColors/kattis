#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> letter;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			char c;
			cin >> c;
			if (c != '.')
				letter.push_back(make_pair(x, y));
		}
	}

	int sum = 0;

	for (int i = 0; i < letter.size(); i++) {
		for (int j = i + 1; j < letter.size(); j++) {
			for (int k = j + 1; k < letter.size(); k++) {
				double xDiff1 = (double)letter[i].first - letter[j].first;
				double yDiff1 = (double)letter[i].second - letter[j].second;

				double xDiff2 = (double)letter[i].first - letter[k].first;
				double yDiff2 = (double)letter[i].second - letter[k].second;

				if (xDiff1 == 0 && xDiff2 == 0) {
					sum++;
				}
				else if (yDiff1 == 0 && yDiff2 == 0) {
					sum++;
				}
				else if (xDiff1 != 0 && xDiff2 != 0 && yDiff1 != 0 && yDiff2 != 0) {
					double scale1 = xDiff1 / yDiff1;
					double scale2 = xDiff2 / yDiff2;

					if (scale1 == scale2) {
						sum++;
					}
				}
			}
		}
	}

	cout << sum << endl;

}