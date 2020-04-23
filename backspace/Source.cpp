#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, ans;
	int j = 0;
	getline(cin, a);
	unsigned long long asize = a.length();
	for (unsigned long long i = 0; i < asize; i++) {
		if (a[i] == '<') ans.pop_back();
		else ans.push_back(a[i]);
	}
	cout << ans;
	return 0;
}