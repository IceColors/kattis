#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	string a;
	string b;
	string c;

	for (int i = 0; i < t; i++) {
		getline(cin, a);


		while (cin >> b && b != "what") {
			cin >> b; //goes
			cin >> b;
			int ind = a.find(b);
			while (ind != string::npos && ((ind == 0 || a[ind - 1] == ' ') && (ind + b.length() == a.length() || a[ind + b.length()] == ' '))) {
				if (ind == 0 && ind + b.size() == a.size()) a.erase(ind, b.length());
				else if (ind == 0) a.erase(ind, b.length() + 1);
				else if (ind + b.length() == a.length()) a.erase(ind-1, b.length()+1);
				else a.erase(ind, b.length() + 1);
				ind = a.find(b);
			}
		}
		cout << a << '\n';
		getline(cin, a);
	}


	return 0;
}