#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int numbers[42] = {};
	int temp;
	int count = 0;
	

	for (int i = 0; i < 10 && cin >> temp; i++) {
		if (!numbers[temp % 42]) count++;
		numbers[temp % 42] = 1;
	}

	cout << count;

	return 0;
}