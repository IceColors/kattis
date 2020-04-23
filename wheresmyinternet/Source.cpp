#include <iostream>
#include <vector>

using namespace std;

void connect(vector< vector<int> >& houses, vector<bool>& connected, int index) {
	if (connected[index]) return;
	connected[index] = true;
	for (int i = 0; i < houses[index].size(); i++) {
		connect(houses, connected, houses[index][i]);
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	vector< vector<int> > houses(n, vector<int>());
	vector<bool> connected(n, 0);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		houses[a].push_back(b);
		houses[b].push_back(a);
	}

	connect(houses, connected, 0);

	bool allConnected = true;
	for (int i = 0; i < n; i++) {
		if (!connected[i]) {
			cout << i + 1 << '\n';
			allConnected = false;
		}
	}
	if (allConnected) cout << "Connected\n";
	return 0;
}