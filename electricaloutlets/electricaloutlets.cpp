#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		int sum = 1;
		for (int i = 0; i < k; i++) {
			int o;
			cin >> o;
			sum += o - 1;
		}
		cout << sum << endl;
	}
}