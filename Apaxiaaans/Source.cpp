#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	char temp;

	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if (i == 0 || input[i] != input[i - 1]) {
			cout << input[i];
		}
	}

	cin >> input;

	return 0;
}