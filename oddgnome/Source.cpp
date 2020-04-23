#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	while (n--) {
		int g;
		cin >> g;
		int oldgnome;
		int gnome;
		cin >> oldgnome;
		bool found = false;
		for (int i = 2; i <= g; i++) {
			cin >> gnome;
			if (!found && oldgnome + 1 != gnome) {
				cout << i << endl;
				found = true;
			}
			oldgnome = gnome;
		}
	}

	return 0;
}