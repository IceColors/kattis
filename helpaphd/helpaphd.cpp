#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int N;
	cin >> N;

	while (N--) {
		string line;
		cin >> line;
		if (line == "P=NP") {
			cout << "skipped\n";
		}
		else {
			stringstream ss(line);
			int a, b;
			char plus;
			ss >> a >> plus >> b;
			cout << a + b << '\n';
		}
	}
}