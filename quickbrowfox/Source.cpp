#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int a;
	cin >> a;
	string temp;
	getline(cin, temp);

	for (int i = 0; i < a; i++) {
		bool alphabet[26] = {};
		
		getline(cin, temp);

		
		bool pangram = true;
		
		for (int j = 0; j < 26; j++) {
			if (!(count(temp.begin(), temp.end(), j + 'a') || count(temp.begin(), temp.end(), j + 'A'))) {
				alphabet[j] = true;
				pangram = false;
			}
		}

		if (pangram) {
			cout << "pangram" << endl;
		}
		else {
			cout << "missing ";
			for (int j = 0; j < 26; j++) {
				if (alphabet[j]) {
					cout << (char)(j + 'a');
				}
			}
			cout << endl;
		}

	}
	return 0;
}