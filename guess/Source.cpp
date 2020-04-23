#include <iostream>
#include <string>

using namespace std;

int main() {
	int min = 1;
	int max = 1000;
	int mid = 1000 / 2;
	string a;
	cout << mid << endl;

	while (cin >> a) {
		if (a == "lower") max = mid;
		else if (a == "higher") min = mid+1;
		else break;
		mid = (max + min) / 2;
		cout << mid << endl;
		
	}

	return 0;
}