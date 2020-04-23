#include <iostream>
#include <string>

using namespace std;

long long factorial(int a) {
	if (a == 1) return 1;
	return (a * factorial(a - 1));
}

int main() {
	int n;
	cin >> n;
	int a;
	string as;
	while (n--) {
		cin >> a;
		long long f = factorial(a);
		as = to_string(f);
		cout << as[as.length() - 1] << endl;
	}
	cin >> n;

	return 0;
}