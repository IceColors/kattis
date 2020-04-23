#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {

	int n;
	string message;
	cin >> n;

	while (n--) {
		cin >> message;
		
		int m = sqrt(message.length());
		m *= m;
		cout << m << endl;

	}
	cin >> n;

	return 0;
}