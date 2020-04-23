#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector< pair<int, string> > cups;
	string a, b;
	while (n--) {
		cin >> a >> b;
		if (a[0] - '0' >= 0 && a[0] - '9' <= 0) {
			cups.push_back(pair<int, string>(stoi(a)/2, b));
		}
		else {
			cups.push_back(pair<int, string>(stoi(b), a));
		}
	}
	sort(cups.begin(), cups.end());
	for (int i = 0; i < cups.size(); i++) {
		cout << cups[i].second << endl;
	}



	return 0;
}