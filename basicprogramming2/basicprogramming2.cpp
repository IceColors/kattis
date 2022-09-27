#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector<long long> a(n);
	vector<long long> r(200001, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 200000) continue;
		r[a[i]]++;
	}

	if (t == 1) {
		bool flag = 0;
		for (int i = 0; i < 7777 / 2 + 1; i++) {
			if (r[i] > 0 && r[7777 - i] > 0) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "Yes\n" : "No\n");
	}
	else if (t == 2) {
		sort(a.begin(), a.end());
		bool flag = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] == a[i + 1]) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "Contains duplicate\n" : "Unique\n");
	}
	else if (t == 3) {
		bool flag = 1;
		map<int, int> b;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (b.find(a[i]) == b.end())
				b.insert({ a[i], 1 });
			else {
				b[a[i]]++;
				if (b[a[i]] > n / 2) {
					flag = 0;
					cout << a[i] << '\n';
					break;
				}

			}
		}
		if (flag)
			cout << "-1\n";
	}
	else if (t == 4) {

		sort(a.begin(), a.end());
		if (!(a.size() % 2)) {
			cout << a[n / 2 - 1] << " " << a[n / 2] << '\n';
		}
		else {
			cout << a[n / 2] << '\n';
		}
	}

	else if (t == 5) {

		sort(a.begin(), a.end());
		for (auto& i : a) {
			if (i < 100)
				continue;
			if (i > 999)
				break;
			cout << i << " ";
		}
		cout << '\n';
	}
}