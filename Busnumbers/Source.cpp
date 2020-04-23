#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, temp;
	vector<int> b;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> temp;
		b.push_back(temp);
	}
	sort(b.begin(), b.end());

	for (int i = 0; i < b.size(); i++) {
		int first = b[i];
		int last = b[i];
		int indexpluss = 0;
		for (int j = 1; j < b.size() - i; j++) {
			if (b[i] == b[i + j] - j) {
				last = b[i + j];
				indexpluss++;
			}
			else break;
		}
		i += indexpluss;
		if (last - first == 1) {
			cout << first << " ";
			i -= 1;
		}
		else if (last == first) cout << first << " ";
		else cout << first << "-" << last << " ";
	}
	cin >> a;
	cin >> a;
	cin >> a;
	return 0;
}