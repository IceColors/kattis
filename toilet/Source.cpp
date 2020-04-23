#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	getline(cin, a);
	bool toilet;

	if (a[0] == 'U') toilet = 1;
	else toilet = 0;

	bool tU = toilet;
	bool tD = toilet;
	bool tF = toilet;

	int aU = 0;
	int aD = 0;
	int aF = 0;

	for (int i = 1; i < a.length(); i++) {
		if (a[i] == 'U') {
			if (tD) {
				aD++;
				tD = 0;
			}
			else {
				aD += 2;
				tD = 0;
			}
			if (!tU) {
				aU++;
				tU = 1;
			}
			if (!tF) {
				aF += 1;
				tF = 1;
			}
		}
		if (a[i] == 'D') {
			if (tU) {
				aU+=2;
				tU = 1;
			}
			else {
				aU++;
				tU = 1;
			}
			if (tD) {
				aD++;
				tD = 0;
			}
			if (tF) {
				aF += 1;
				tF = 0;
			}
		}
	}
	cout << aU << endl << aD << endl << aF << endl;
}