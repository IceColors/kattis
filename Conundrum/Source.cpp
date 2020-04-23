#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a;
	

	cin >> a;
	int days = a.length();

	for (int i = 0; i < a.length(); i += 3) {
		if (a[i] == 'P') days--;
		if (a[i+1] == 'E') days--;
		if (a[i+2] == 'R') days--;

	}
	cout << days;
	return 0;
}