#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool hiss = false;
	string a;
	getline(cin, a);

	for (int i = 0; i < a.length() - 1; i++) {
		if (a[i] == 's' && a[i + 1] == 's') hiss = true;
	}

	if (hiss) cout << "hiss";
	else cout << "no hiss";

	return 0;
}