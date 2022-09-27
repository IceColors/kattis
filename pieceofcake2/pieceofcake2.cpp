#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
	p1 = b * c * 4;
	p2 = (a - b) * c * 4;
	p3 = (a - c) * b * 4;
	p4 = (a - b) * (a - c) * 4;
	cout << max(p1, max(p2, max(p3, p4)));
}