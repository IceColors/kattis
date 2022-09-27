#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	[&s](ostream& os)->ostream& { string a; for (int i = 0; i < (s.size() - 2) * 2; i++) a += "e"; os << a; return os; }(cout << "h") << "y" << endl;
}