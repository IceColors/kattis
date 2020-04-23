#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;






int main() {

	map<string, string> dictionary;


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int index;
	string a, b, c;
	while (getline(cin, a) && a != "") {
		index = a.find(' ');
		b = a.substr(0, index);
		c = a.substr(index + 1, a.size() - 1);
		dictionary[c] = b;
	}
	map<string, string>::iterator it;
	while (getline(cin, a)) {

		it = dictionary.find(a);
		if (it != dictionary.end()) {
			cout << it->second << '\n';
		}
		else cout << "eh\n";
	}

	return 0;

}