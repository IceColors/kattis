#include <iostream>

using namespace std;

int main() {
	int P;
	cin >> P;
	for (int i = 0; i < P; i++) {
		int notUsed;
		cin >> notUsed;
		int N;
		cin >> N;

		long long sum = 0;
		for (int v = 1; v <= N; v++) {
			sum += v;
			sum++;
		}
		cout << notUsed << " " << sum << "\n";
	}
}