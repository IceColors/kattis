#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>




using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	multiset<long> cookiez;
	multiset<long>::iterator it;
	multiset<long>::iterator it2;

	string cookie;

	long size = 0;
	long cookiel;

	while (cin >> cookie) {
		if (cookie[0] == '#') {
			if (size > 0) {
				cout << *(it) << '\n';

				it2 = it;
				size--;
				if (size != 0)it--;

				cookiez.erase(it2);

				if (!(size % 2) && size != 0) it++;
			}
		}
		else {
			cookiel = stol(cookie);
			cookiez.insert(cookiel);
			size++;
			if (size == 1) it = cookiez.begin();
			else if (size % 2) {
				if (cookiel < *it) it--;

			}
			else {
				if (cookiel >= *it) it++;
			}
		}
	}


	return 0;
}