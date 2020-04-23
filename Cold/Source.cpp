#include <iostream>

using namespace std;

int main() {
	int a, b;
	int tot = 0;
	cin >> a;
	while (a--) {
		cin >> b;
		if (b < 0) tot++;
	}
	cout << tot;
	cin.ignore();
	return 0;
}