#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool ascending = true;
	bool descending = true;
	string lastName;
	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;
		if (i != 0) {
			for (int j = 0; j < name.size(); j++) {
				if (name[j] > lastName[j]) {
					descending = false;
					break;
				}

				else if (name[j] < lastName[j]) {
					ascending = false;
					break;
				}
			}
			
		}
		lastName = name;
	}
	if (ascending) cout << "INCREASING";
	else if (descending) cout << "DECREASING";
	else cout << "NEITHER";
	cin >> n;

	return 0;
}