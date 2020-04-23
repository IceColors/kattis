#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int ng, nm;
		int a;
		cin >> ng >> nm;
		vector<int> godzilla;
		vector<int> mecha;

		for (int i = 0; i < ng; i++) {
			cin >> a;
			godzilla.push_back(a);
		}
		sort(godzilla.rbegin(), godzilla.rend());
		for (int i = 0; i < nm; i++) {
			cin >> a;
			mecha.push_back(a);
		}
		sort(mecha.rbegin(), mecha.rend());

		while (godzilla.size() > 0 && mecha.size() > 0) {
			if (godzilla.back() < mecha.back()) {
				godzilla.pop_back();
			}
			else mecha.pop_back();
		}

		if (godzilla.size() == 0) {
			cout << "MechaGodzilla\n";
		}
		else cout << "Godzilla\n";
	}

	return 0;
}