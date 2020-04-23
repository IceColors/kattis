#include <iostream>
#include <string>

using namespace std;

int main() {

	long h;
	cin >> h;
	string a;
	cin >> a;
	int modifier = 1;

	long s = 1;
	long times = 1;
	for (long i = 0; i < h; i++) {
		times *= 2;
		s += times;
	}
	long d = 1;
	for (long i = 0; i < a.length(); i++) {
		long l = 0, r =0;
		if (s & 1) {
			r = s - 2 * d;
			l = r + 1;
		}
		else {
			l = s - 2 * d;
			r = l - 1;
		}
		if (a[i] == 'L') {
			d = s - l;
			s = l;
		}
		else {
			d = s - r;	
			s = r;
		}

	}
	cout << s << endl;
	cin >> h;

	return 0;
}