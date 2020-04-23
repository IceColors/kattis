#include <iostream>

using namespace std;

int main() {

	int capacity, stations;
	cin >> capacity >> stations;

	int onTrain = 0;
	bool possible = true;
	int a;
	for (int i = 0; i < stations; i++) {
		cin >> a;
		onTrain -= a;
		if (onTrain < 0) possible = false;

		cin >> a;
		onTrain += a;
		if (onTrain > capacity) possible = false;

		cin >> a;
		if (a && onTrain != capacity) possible = false;
	}
	if (onTrain) possible = false;
	
	if (possible) cout << "possible\n";
	else cout << "impossible\n";
	cin >> a;

	return 0;
}