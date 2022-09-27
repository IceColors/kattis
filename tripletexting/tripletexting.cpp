#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
	string a;
	cin >> a;
	int len = a.length() / 3;
	string fin;
	for (int i = 0; i < len; i++) {
		fin += a[i] == a[i + len] ? a[i] : (a[i + len] == a[i + 2 * len] ? a[i + len] : a[i]);
	}
	cout << fin;
}