#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int a;
	string b;
	while (cin >> a && a != 0 && cin >> b) {
		for (int i = 0; i < b.length(); i++) {
			for (int j = 0; j < a; j++) {
				if (b[i] == 'Z') b[i] = '_';
				else if (b[i] == '_') b[i] = '.';
				else if (b[i] == '.') b[i] = 'A';
				else b[i]++;
			}
		}
		for (int j = b.length() - 1; j >= 0; j--) {
			cout << b[j];
		}
		cout << endl;
	}


}