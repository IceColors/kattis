#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n, a;
	cin >> n;
	
	while (n--) {
		cin >> a;
		cout << (int)ceil(a / 400.0) << endl;
	}


	return 0;
}