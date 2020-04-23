#include <iostream>

using namespace std;

int main() {
	int n, x;

	cin >> n;
	while (n) {
		int	s1 = 0;
		int	s2 = 0;
		int	s3 = 0;

		cin >> x;
		cout << x << " ";
		cin >> x;
		for (int i = 1; i <= x; i++) s1 += i;
		for (int i = 0; i < x; i++) s2 += i*2 + 1;
		for (int i = 1; i <= x; i++) s3 += i*2;

		cout << s1 << " " << s2 << " " << s3 << endl;
		n--;
	}


	return 0;
}