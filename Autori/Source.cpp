#include <iostream>
#include <string>


using namespace std;

int main() {

	string a, b;
	cin >> a;
	b.push_back(a[0]);
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == '-') {
			b.push_back(a[i + 1]);
		}

	}
	cout << b;


	return 0;
}