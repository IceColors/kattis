#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long c = 0, w = 0, t = 0;
	map<string, long long> res;
	string a;
	for(long long i = 0; i < n; i++){
		cin >> a;
		res[a]++;
	}
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		cin >> a;
		if (res[a] != 0) {
			sum++;
			res[a]--;
		}
	}
	cout << sum;
	cin >> a;

	return 0;
}