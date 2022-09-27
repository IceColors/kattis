#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//visited[node][color bitmask]
int visited[300000][5 * 4 * 3 * 2 * 1] = { 0 };

vector<pair<int, vector<long>>> v;

long visit(long node, int bitmask) {

	if ((1 << v[node].first) & bitmask) {
		// already visited this color
		return 0;
	}

	if (visited[node][bitmask]) {
		// already visited this node with the exact same previous colors visited
		// we can then take advantage of that we have calculated the number before
		return visited[node][bitmask];
	}

	// else we visit the neighboring nodes
	// the visit to this node will only increase the number of paths if it is not the initial node (the first node is not a valid path in itself)
	long paths = bitmask ? 1 : 0;
	for (auto& next : v[node].second) {
		paths += visit(next, (1 << v[node].first) | bitmask);
	}
	visited[node][bitmask] = paths;
	return paths;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	long n, m, k;
	cin >> n >> m >> k;
	
	int color;
	for (long i = 0; i < n; i++) {
		cin >> color;
		v.push_back(make_pair(color, vector<long>()));
	}

	long a, b;
	for (long i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		v[a].second.push_back(b);
		v[b].second.push_back(a);
	}


	long sum = 0;

	for (long i = 0; i < n; i++) {
		sum += visit(i, 0);
	}

	cout << sum << endl;
}