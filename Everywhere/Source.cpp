#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int a, b;
	string temp;
	cin >> a;


	for (int i = 0; i < a; i++) {
		cin >> b;
		vector<string> cities;
		for (int j = 0; j < b; j++) {
			cin >> temp;
			if (!std::count(cities.begin(), cities.end(), temp)) {
				cities.push_back(temp);
			}

		}
		cout << cities.size() << endl;
	}

	return 0;
}