#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool caseInSensStringCompareCpp11(std::string & str1, std::string &str2)
{
	return ((str1.size() == str2.size()) && std::equal(str1.begin(), str1.end(), str2.begin(), [](char & c1, char & c2) {
		return (c1 == c2 || std::toupper(c1) == std::toupper(c2));
	}));
}

using namespace std;

int main() {
	vector<string> a;
	string inp;
	
	while (cin >> inp) {
		for (int i = 0; i < a.size(); i++) {
			if (caseInSensStringCompareCpp11(inp, a[i])) {
				inp = ".";
				break;
			}
		}
		a.push_back(inp);
	}

	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}

	return 0;
}