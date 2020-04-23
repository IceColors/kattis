#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	string a;
	getline(cin, a);
	stringstream stream(a);
	string word;
	vector<string> sentence;
	bool found = false;
	while (stream >> word) {
		sentence.push_back(word);
		if (count(sentence.begin(), sentence.end(), word) > 1) {
			found = true;
			break;
		}
	}
	
	if (found) cout << "no";
	else cout << "yes";
	return 0;
}