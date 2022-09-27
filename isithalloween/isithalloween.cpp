#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	getline(cin, a);
	cout << ((a == "OCT 31" || a == "DEC 25") ? "yup" : "nope");
}