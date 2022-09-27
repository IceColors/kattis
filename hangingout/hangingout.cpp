#include <iostream>
#include <string>

using namespace std;

int main() {
	int L, x;
	cin >> L >> x;
	int sum = 0;
	int times = 0;

	for (int i = 0; i < x; i++) {
		string a;
		int t;
		cin >> a >> t;
		if (a == "enter") {
			if (sum + t > L) times++;
			else sum += t;
		}
		else {
			sum -= t;
		}
	}
	cout << times;
}