#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	int cases;
	cin >> cases;

	while (cases--) {

		string instructions;
		cin >> instructions;
		long long n;
		cin >> n;
		list<long long> l;
		string a;
		cin >> a;
		long long it = 1;
		for (long long i = 0; i < n; i++) {
			long long temp;
			long long next = a.find(",", it);
			temp = stoll(a.substr(it, next - it));
			l.push_back(temp);
			it = next + 1;
		}
		int dir = 1; //drops first element
		for (long long i = 0; i < instructions.length(); i++) {
			if (instructions[i] == 'R') dir = !dir;
			else if (instructions[i] == 'D') {
				if (l.size() > 0) {
					if (dir)	l.pop_front();
					else l.pop_back();
				}
				else {
					cout << "error\n";
					goto end;
				}
			}
		}
		cout << "[";
		if (dir) {
			for (long long i = (long long)l.size() - 1; i > 0; i--) {
				cout << l.front();
				l.pop_front();
				cout << ",";
			}
			if (l.size() == 1) cout << l.front();
			cout << "]\n";
		}
		else {
			for (long long i = (long long)l.size() - 1; i > 0; i--) {
				cout << l.back();
				l.pop_back();
				cout << ",";
			}
			if(l.size() == 1) cout << l.back();
			cout << "]\n";
		}
	end:;
	}
}