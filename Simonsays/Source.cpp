#include <iostream>
#include <string>

using namespace std;

int main() {
	int a;
	
	string s = "Simon says ";
	cin >> a;

	while (--a) {
		string b = "";
		cin >> b;
		if (b.compare(0, 10, s) == 0) {
			cout << "test";
		}
	}

	return 0;
}