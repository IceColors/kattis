#include <iostream>
#include <string>

using namespace std;

int main() {
	int pieces[] = { 1, 1, 2, 2, 2, 8 };
	int a;
	for (int i = 0; i < 6; i++) {
		cin >> a;
		pieces[i] -= a;
	}
	
	for (int i = 0; i < 6; i++) {
		cout << pieces[i] << " ";
	}

	cin >> a;

	return 0;
}