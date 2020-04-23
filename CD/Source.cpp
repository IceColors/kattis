#include <iostream>
#include <unordered_set>


using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		int tot = 0;
		unordered_set<int> nArr;
		int a;
		int lastIndex = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			nArr.insert(a);
		}

		for (int i = 0; i < m; i++) {
			cin >> a;
			if (nArr.count(a)) {
				tot++;
			}
		}
		cout << tot << endl;

	}
	return 0;
}