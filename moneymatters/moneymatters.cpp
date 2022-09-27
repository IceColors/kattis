#include <iostream>
#include <vector>

using namespace std;



vector < pair<int, vector<int>>> person;
vector<bool> visited;

int visit(int ind) {
	if (visited[ind])
		return 0;
	visited[ind] = true;

	int sum = person[ind].first;
	for (const auto& next : person[ind].second) {
		sum += visit(next);
	}
	return sum;
}

int main() {
	int n, m;
	cin >> n >> m;

	

	for (int i = 0; i < n; i++) {
		int money;
		cin >> money;
		person.push_back(make_pair(money, vector<int>()));
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		person[a].second.push_back(b);
		person[b].second.push_back(a);
	}
	
	visited.resize(person.size());

	bool possible = true;
	for (int i = 0; i < n; i++) {
		if (visit(i) != 0) {
			possible = false;
			break;
		}
	}

	cout << (possible ? "POSSIBLE" : "IMPOSSIBLE");

}