#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void floodMap(const vector< vector<char> >& map, vector< vector<int> >& islandMap, const int x, const int y, int& islandSum, vector<pair<int, int>>& visit) {
	if (islandMap[x][y] != 0) {
		return;
	}

	if (map[x][y] == '#' || map[x][y] == 'X') {

		bool discoveredNeighbors = false;
		if (y != 0 && islandMap[x][y - 1] != 0) {
			discoveredNeighbors = true;
		}

		if (y != map[0].size()-1 && islandMap[x][y + 1] != 0) {
			discoveredNeighbors = true;
		}

		if (x != 0 && islandMap[x - 1][y] != 0) {
			discoveredNeighbors = true;
		}

		if (x != map.size()-1 && islandMap[x + 1][y] != 0) {
			discoveredNeighbors = true;
		}

		if (!discoveredNeighbors) {
			islandMap[x][y] = ++islandSum;
		}
		else {
			islandMap[x][y] = islandSum;
		}

		if (y != 0 && islandMap[x][y - 1] == 0 && (map[x][y-1] == '#' || map[x][y-1] == 'X')) {
			visit.push_back(pair<int, int>(x, y - 1));
		}

		if (y != map[0].size()-1 && islandMap[x][y + 1] == 0 && (map[x][y + 1] == '#' || map[x][y + 1] == 'X')) {
			visit.push_back(pair<int, int>(x, y + 1));
		}

		if (x != 0 && islandMap[x-1][y] == 0 && (map[x - 1][y] == '#' || map[x -1][y] == 'X')) {
			visit.push_back(pair<int, int>(x-1, y));
		}

		if (x != map.size()-1 && islandMap[x+1][y] == 0 && (map[x + 1][y] == '#' || map[x + 1][y] == 'X')) {
			visit.push_back(pair<int, int>(x +1, y));
		}

	}
}


int checkX(vector< vector<char> >& map, int x, int y) {
	int nCon = 0;
	if (map[x][y] == 'X') {
		if (y != 0 && map[x][y - 1] == 'B') nCon++;
		if (y != map[0].size()-1 && map[x][y + 1] == 'B') nCon++;
		if (x != 0 && map[x-1][y] == 'B') nCon++;
		if (x != map.size()-1 && map[x+1][y] == 'B') nCon++;
	}
	return nCon;
}

void connectIslands(vector< vector<char> >& map, vector< vector<int> >& busMap, int x, int y) {
	if (map[x][y] == 'X') {
		
		if (y != 0 && map[x][y - 1] == 'B') {
			int yEnd = y - 1;
			for (; yEnd >= 0; yEnd--) {
				if (map[x][yEnd] == 'X')
					break;
			}
			if (busMap[x][yEnd] != busMap[x][y]) {
				int endVal = busMap[x][yEnd];
				for (int i = 0; i < busMap.size(); i++) {
					for (int j = 0; j < busMap[0].size(); j++) {
						if (busMap[i][j] == endVal)
							busMap[i][j] = busMap[x][y];
					}
				}
			}
		}
		if (y != map[0].size() - 1 && map[x][y + 1] == 'B') {
			int yEnd = y + 1;
			for (; yEnd < map[0].size() ; yEnd++) {
				if (map[x][yEnd] == 'X')
					break;
			}
			if (busMap[x][yEnd] != busMap[x][y]) {
				int endVal = busMap[x][yEnd];
				for (int i = 0; i < busMap.size(); i++) {
					for (int j = 0; j < busMap[0].size(); j++) {
						if (busMap[i][j] == endVal)
							busMap[i][j] = busMap[x][y];
					}
				}
			}
		}
		if (x != 0 && map[x - 1][y] == 'B') {
			int xEnd = x - 1;
			for (; xEnd >= 0; xEnd--) {
				if (map[xEnd][y] == 'X')
					break;
			}
			if (busMap[xEnd][y] != busMap[x][y]) {
				int endVal = busMap[xEnd][y];
				for (int i = 0; i < busMap.size(); i++) {
					for (int j = 0; j < busMap[0].size(); j++) {
						if (busMap[i][j] == endVal)
							busMap[i][j] = busMap[x][y];
					}
				}
			}
		}
		if (x != map.size() - 1 && map[x+1][y] == 'B') {
			int xEnd = x + 1;
			for (; xEnd < map.size(); xEnd++) {
				if (map[xEnd][y] == 'X')
					break;
			}
			if (busMap[xEnd][y] != busMap[x][y]) {
				int endVal = busMap[xEnd][y];
				for (int i = 0; i < busMap.size(); i++) {
					for (int j = 0; j < busMap[0].size(); j++) {
						if (busMap[i][j] == endVal)
							busMap[i][j] = busMap[x][y];
					}
				}
			}
		}
	}

}


int main() {
	string inp;
	int n = 1;
	while(getline(cin, inp)) {
		vector< vector<char> > map(inp.length(), vector<char>());
		do {
			for (int i = 0; i < inp.length(); i++)
				map[i].push_back(inp[i]);
		} while (getline(cin, inp) && !inp.empty());

		cout << "Map " << n << endl;
		n++;
		vector< vector<int> > islandMap(map.size(), vector<int>(map[0].size(), 0));
		vector<pair<int, int>> visit;
		int islandSum = 0;

		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[0].size(); j++) {
				floodMap(map, islandMap, i, j, islandSum, visit);
				while (!visit.empty()) {
					int x1 = visit.back().first;
					int y1 = visit.back().second;
					visit.pop_back();
					floodMap(map, islandMap, x1, y1, islandSum, visit);
				}
			}
		}

		cout << "islands: " << islandSum << endl;

		int bridges = 0;
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[0].size(); j++) {
				bridges += checkX(map, i, j);
			}
		}
		cout << "bridges: " << bridges / 2 << endl;


		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[0].size(); j++) {
				connectIslands(map, islandMap, i, j);
			}
		}
		int busSum = 0;
		vector<int> lanes;
		for (int i = 0; i < map[0].size(); i++) {
			for (int j = 0; j < map.size(); j++) {
				if (islandMap[j][i] != 0 && count(lanes.begin(), lanes.end(), islandMap[j][i]) == 0) {
					busSum++;
					lanes.push_back(islandMap[j][i]);
				}
			}
		}
		cout << "buses needed: " << busSum << endl << endl;
	}
}