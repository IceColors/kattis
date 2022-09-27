#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;

	pair<int, int>* vals = new pair<int, int>[N];

	int lastReset = -1;
	int lastResetVal = 0;

	for(int i = 0; i < Q; i++) {
		string op;
		cin >> op;
		
		if (op == "SET") {
			int n, val;
			cin >> n >> val;
			vals[n-1] = pair<int, int>(val, i);
		}
		else if (op == "RESTART") {
			lastReset = i;
			cin >> lastResetVal;
		}
		else {
			int n;
			cin >> n;
			if (vals[n-1].second <= lastReset) {
				cout << lastResetVal << '\n';
			}
			else {
				cout << vals[n-1].first << '\n';
			}
		}
	}

	delete[] vals;
}