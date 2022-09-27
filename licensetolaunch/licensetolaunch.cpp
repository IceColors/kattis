#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long best = n;
	long long id = 0;
	for(long long i = 0; i < n; i++) {
		long long a;
		cin >> a;
		if (a < best) {
			best = a;
			id = i;
		}
	}
	cout << id << endl;
}