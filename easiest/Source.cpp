#include <iostream>
#include <string>

using namespace std;

int main() {
	string n;
	int i_n;
	int p;
	int sum_n;
	int sum_p;
	string s_p;

	while (cin >> n && n != "0") {
		sum_n = 0;
		i_n = stoi(n);

		for (int i = 0; i < n.size(); i++) {
			sum_n += n[i] - '0';
		}

		for (int i = 11; true; i++) {
			sum_p = 0;
			p = i_n * i;
			s_p = to_string(p);
			for (int j = 0; j < s_p.size(); j++) {
				sum_p += s_p[j] - '0';
			}
			if (sum_p == sum_n) {
				cout << i << endl;
				break;
			}
		}
	}
}