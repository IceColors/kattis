#include <iostream>
#include <string>

using namespace std;

int main() {

	int n;
	string a, b;
	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, a);
		getline(cin, b);
		cout << a << '\n';
		cout << b << '\n';
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == b[i]) cout << '.';
			else cout << '*';
		}
		cout << "\n\n";
	}

	return 0;
}