#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string b;
	cin >> n >> b;
	string a;
	int score = 0;
	for (int i = 0; i < n * 4; i++) {
		cin >> a;
		if (a[1] == b[0]) {
			switch (a[0]) {
			case 'A':
				score += 11;
				break;

			case 'K':
				score += 4;
				break;

			case 'Q':
				score += 3;
				break;

			case 'J':
				score += 20;
				break;

			case 'T':
				score += 10;
				break;
			case '9':
				score += 14;
				break;
			}
		}
		else {
			switch (a[0]) {
			case 'A':
				score += 11;
				break;

			case 'K':
				score += 4;
				break;

			case 'Q':
				score += 3;
				break;

			case 'J':
				score += 2;
				break;

			case 'T':
				score += 10;
				break;
			}
		}
	}
	cout << score;

	return 0;
}