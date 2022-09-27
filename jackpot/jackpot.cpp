#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	return (a / gcd(a, b)) * b;
}


long long nlcm(vector<long long> wheels) {
	if (wheels.size() > 2) {
		long long t = wheels.back();
		wheels.pop_back();
		return lcm(t, nlcm(wheels));
	}
	else return lcm(wheels[0], wheels[1]);
}

int main() {
	int n, w;
	cin >> n;
	while (n--) {
		vector<long long> wheels;
		cin >> w;
		while (w--) {
			long long t;
			cin >> t;
			wheels.push_back(t);
		}
		if (wheels.size() == 1) {
			cout << wheels[0] << endl;
			continue;
		}
		long long per = nlcm(wheels);
		if (per > 1000000000) {
			cout << "More than a billion." << endl;
		}
		else cout << per << endl;
	}
}