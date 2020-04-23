#include <iostream>
#include <vector>
#include <string>

using namespace std;

int coastLength(vector< vector<int> >& map, int x, int y) {
	int length = 0;
	if (map[x][y] == 1) {
		if (map[x + 1][y] == 2) length++;
		if (map[x - 1][y] == 2) length++;
		if (map[x][y + 1] == 2) length++;
		if (map[x][y - 1] == 2) length++;
	}
	return length;
}

void floodfill(vector< vector<int> >& map, vector< vector<int> >& visited, int x, int y) {
	if (x < 0 || x > (map.size() - 1) || y < 0 || y > (map[x].size() - 1)) {
		return;
	}
	if (visited[x][y]) {
		return;
	}
	visited[x][y] = 1;

	if (map[x][y] == 0) {
		map[x][y] = 2;
		floodfill(map, visited, x + 1, y);
		floodfill(map, visited, x - 1, y);
		floodfill(map, visited, x, y + 1);
		floodfill(map, visited, x, y - 1);
	}
}

int main() {
	int n, m;
	string a;
	cin >> n >> m;
	cin.ignore();
	vector< vector<int> > map(n + 2, vector<int>(m + 2, 0));
	vector< vector<int> > visited(n + 2, vector<int>(m + 2, 0));

	for (int i = 1; i <= n; i++) {
		getline(cin, a);
		for (int j = 0; j < m; j++) {
			map[i][j+1] = a[j] - '0';
		}
	}

	floodfill(map, visited, 0, 0);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			count += coastLength(map, i, j);
		}
	}

	cout << count;
	cin >> n;

	return 0;
}