#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 1; i < 101; i++) {
		bool flag = false;
		if (s.length() % i == 0) {
			flag = true;
			int offset = 0;
			for (int j = 0; j < s.length(); j += i) {
				for (int k = j; k < j + i; k++) {
					//cout << "i: " << i << " checking from position " << j << " if " << s[j + ((k + offset + 1) % i)] << " != " << s[k % i] << endl;
					if (s[j + ((k + offset) % i) ] != s[k % i]) {
						//cout << " false" << endl;
						flag = false;
						break;
					}
					
				}
				offset += 1;
				if (flag == false) break;
			}
			
		}
		if (flag == true) {
			cout << i;
			break;
		}
			
	}
}