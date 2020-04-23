#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> vars;

void def(string, int);

int main() {
	string func, var;
	int val;

	while (true) {
		cin >> func;
		if (func == "def") {
			cin >> var >> val;
			def(var, val);
		}
		else if (func == "print") {
			cin >> var;
			cout << vars[var] << endl;
		}
	}



	return 0;
}

void def(string name, int val) {
	vars[name] = val;
}

void calc(string line) {
	string ans;
	for(line, )
}