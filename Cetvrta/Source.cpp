#include <iostream>

using namespace std;

int main() {

	int a[3];
	int b[3];

	for (int i = 0; i < 3; i++) {
		cin >> a[i] >> b[i];
	}
	if (a[0] == a[1]) cout << a[2] << " ";
	else if (a[1] == a[2]) cout << a[0] << " ";
	else  if(a[0] == a[2]) cout << a[1] << " ";
	if (b[0] == b[1]) cout << b[2] << "\n";
	else if (b[1] == b[2]) cout << b[0] << "\n";
	else  if (b[0] == b[2]) cout << b[1] << "\n";
	return 0;
}