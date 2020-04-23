#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int n;
	string a;
	int t = 1;
	while (cin >> n && n != 0) {
		cout << "SET " << t << '\n';
		t++;
		string *old = new string[n];
		string *replaced = new string[n];
		for (int i = 0; i < n; i++) {
			cin >> a;
			old[i] = a;
		}
		for (int i = 0, j = 0; i < ceil(n/2.0); i++, j+=2) {
			replaced[i] = old[j];
			if(j+2 <= n) replaced[n - i - 1] = old[j+1];
		}
		for (int i = 0; i < n; i++) {
			cout << replaced[i] << '\n';
		}
	}

	return 0;
}