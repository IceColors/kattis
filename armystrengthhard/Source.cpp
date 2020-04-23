#include <iostream>
#include <list>

using namespace std;

int main() {

	long long n, a;
	cin >> n;
	while (n--) {
		list<long long> gz, mg;
		long long gzn, mgn;
		cin >> gzn >> mgn;
		while (gzn--) {
			cin >> a;
			gz.push_back(a);
		}
		gz.sort();
		while (mgn--) {
			cin >> a;
			mg.push_back(a);
		}
		mg.sort();

		while (gz.size() != 0 && mg.size() != 0) {
			if (mg.front() > gz.front()) gz.pop_front();
			else mg.pop_front();
		}
		if (mg.size() == 0) cout << "Godzilla\n";
		else cout << "MechaGodzilla\n";
	}
	cin >> a;
	return 0;
}
