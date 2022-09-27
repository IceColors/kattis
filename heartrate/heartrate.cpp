#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		double b;
		double p;
		cin >> b >> p;
		double bpm = (60. * b) / p;
		double abpm = 60. / (p/(b-1));
		cout << setprecision(4) << fixed << abpm << " " << bpm << " "
			<< bpm + bpm - abpm << endl;
	}
}