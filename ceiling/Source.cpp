#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	vector<string> shapes;
	int n, k;
	cin >> n >> k;
	while (n--) {
		string shape;
		string inp;
		getline(cin, inp);
		for (int i = 0; i < k; i++) {
			if (shape.size() == 0) {
				shape += inp[i];
			}
			else if(shape[i] >)

		}
	}

	return 0;
}