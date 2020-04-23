#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 1; i <= c; i++) {
		if (!(i % a) && !(i % b)) cout << "FizzBuzz" << endl;
		else if (!(i % a)) cout << "Fizz" << endl;
		else if (!(i % b)) cout << "Buzz" << endl;
		else cout << i << endl;

	}
	return 0;
}