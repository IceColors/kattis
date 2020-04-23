	#include <iostream>
	#include <string>
	#include <algorithm>

	using namespace std;

	int main() {
		string a, b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int c, d;
		cout << (stoi(a) > stoi(b) ? stoi(a) : stoi(b));
		return 0;
	}