#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	unordered_map<string, int> conclusions;
	int error = 0;
	string line;
	
	string a;
	for (int i = 1; i <= n; i++) {
		getline(cin, line);
		stringstream ssline(line);
		while (ssline >> a) {
			if (a == "->") break;
			if (conclusions[a] == 0) {
				error = i;
				goto en;
			}
		}
		ssline >> a;
		conclusions[a]++;
	}
	en:
	if (error == 0) cout << "correct" << endl;
	else cout << error;
}