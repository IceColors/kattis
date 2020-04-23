#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	int n;

	cin >> n;
	while (n--) {
		cin >> a;
		cout << a.size() << endl;
	}
	cin >> a;
	return 0;
}