#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int sum = 0;
	string line;
	getline(cin, line);
	stringstream ss(line);
	int n;
	char c;

	while (ss >> n) {
		ss >> c;
		if (c == '-') {
			sum -= n;
			ss >> n >> c;
			sum += n+1;
		}
		else {
			sum += 1;
		}
	}

	cout << sum << endl;
}