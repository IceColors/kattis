#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	string a;
	string b;

	while (getline(cin, a) && getline(cin, b)) {
		int bin = b.find(a, 0);
		if (bin != string::npos) {
			cout << bin;
			bin++;
		}
		
		while ((bin = b.find(a, bin)) != string::npos) {
			cout << " " << bin;
			bin++;
		}
		cout << endl;


		
	}
	return 0;
}