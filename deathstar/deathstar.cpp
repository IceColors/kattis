#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n,0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long inp;
			cin >> inp;
			a[i] = a[i] | inp;
			a[j] = a[j] | inp;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
