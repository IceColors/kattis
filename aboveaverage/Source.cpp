#include <iostream>

using namespace std;

int main() {

	int c;
	cin >> c;

	while (c--) {
		int n;
		int a;
		cin >> n;
		int *students = new int[n];
		double total = 0;
		for(int i = 0; i < n; i++) {
			cin >> students[i];
			total += students[i];
		}
		double average = total / n;
		double howMany = 0;
		for (int i = 0; i < n; i++) {
			if (students[i] > average) {
				howMany++;
			}
		}
		double percentHowMany = 100 * howMany / n;
		cout.precision(3);
		cout << fixed << percentHowMany << '%' << endl;

		delete[] students;
	}


	return 0;
}