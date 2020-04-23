#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	string a, b;
	cin >> a;
	int tot = 0;
	int exp;
	int num;

	for (int i = 0; i < stoi(a); i++) {
		cin >> b;
		exp = stoi(b.substr(b.size() - 1));
		num = stoi(b.substr(0, b.size() - 1));
		tot += pow(num, exp);
	}
	cout << tot;
	cin >> a;

	return 0;
}