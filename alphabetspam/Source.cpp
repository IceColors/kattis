#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a;
	cin >> a;
	double whitespace = 0;
	double lowercase = 0;
	double uppercase = 0;
	double symbols = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] > 96 && a[i] < 123) lowercase++;
		else if (a[i] == '_') whitespace++;
		else if (a[i] > 64 && a[i] < 91) uppercase++;
		else symbols++;
	}
	cout.precision(9);
	cout << fixed << whitespace / a.length() << endl;
	cout << lowercase / a.length() << endl;
	cout << uppercase / a.length() << endl;
	cout << symbols / a.length() << endl;

	cin >> a;

	return 0;
}