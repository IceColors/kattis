#include <iostream>
#include <string>

using namespace std;

int main() {

	int n; 
	cin >> n;
	string a, b;
	cin >> a >> b;
	bool success = true;
	for (int i = 0; i < a.size(); i++) {
		if (n % 2) {
			if (a[i] == b[i]) {
				success = false;
				break;
			}
		}
		else {
			if (a[i] != b[i]) {
				success = false;
				break;
			}
		}
	}
	if (success) cout << "Deletion succeeded";
	else cout << "Deletion failed";
	cin >> a;
	return 0;
}