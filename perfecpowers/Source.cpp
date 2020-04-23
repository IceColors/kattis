#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long a, aa;
	long asqrt;
	double pw;
	while (cin >> aa && aa != 0) {
		a = fabs(aa);
		asqrt = sqrt(a);
		pw = 0;
		for (long i = 2; i <= asqrt; i++) {
			if (fmod(a, i) == 0) {
				int result = round(log(a) / log(i));
				if ((aa > 0 || result % 2) && pow(i, round(result)) == a) {
					pw = result;
					break;

				}
			}
		}
		if (pw) {
			cout << pw << endl;
		}
		else cout << 1 << endl;

	}


	return 0;
}