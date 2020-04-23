#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int r, n, a;
	cin >> r >> n;
	vector<bool>hotel(r, 0);

	for (int i = 0; i < n; i++) {
		cin >> a;
		hotel[a-1] = 1;
	}
	int ind = find(hotel.begin(), hotel.end(), 0) - hotel.begin();
	if ((ind + 1) > hotel.size()) cout << "too late";
	else cout << ind + 1;
	cin >> a;


	return 0;
}