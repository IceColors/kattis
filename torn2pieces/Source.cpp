#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

string hardSearch(map<string, vector<string>>& stations, map<string, bool> visited, string current, string goal) {
	if (current == goal) return (current);
	visited[current] = true;
	for (int i = 0; i < stations[current].size(); i++) {
		if (visited.find(stations[current][i]) == visited.end()) {
			
			string a = hardSearch(stations, visited, stations[current][i], goal);
			if (a != "") {
				return(current += " " + a);
			}
		}
	}
	return "";
}


int main() {

	int n;
	cin >> n;
	cin.ignore();

	map<string, vector<string>> stations;
	string a;

	for (int i = 0; i < n; i++) {
		getline(cin, a);
		stringstream ss;
		ss << a;
		string station;
		ss >> station;
		string connected;
		while (ss >> connected) {
			stations[station].push_back(connected);
			stations[connected].push_back(station);

		}
	}

	string start, end;
	cin >> start >> end;
	string path = hardSearch(stations, map<string, bool>(), start, end);
	if (path != "") cout << path;
	else cout << "no route found";
	return 0;
}