#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
	string s;
	int a = 0, b = 0;
	cin >> s;
	string best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for (int i = 1; i < s.size() - 1; i++) {
		for (int j = i+1; j < s.size(); j++) {
			string s1, s2, s3;
			s1 = s.substr(0, i);
			s2 = s.substr(i, j-i);
			s3 = s.substr(j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			if (s1 + s2 + s3 < best)
				best = s1 + s2 + s3;
		}
	}

	cout << best <<endl;
}