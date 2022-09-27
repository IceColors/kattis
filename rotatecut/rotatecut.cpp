#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		long long flips;
		string s;

		cin >> flips >> s;
		
		int length = s.size();

		bool popFront = true;

		int toRemoveFront = 0;
		int toRemoveBack = 0;
		for (long long i = 0; i < min(2000LL, flips); i++) {
			int toRemove = length / 4;
			length -= toRemove;
			if (popFront)
				toRemoveFront += toRemove;
			else
				toRemoveBack += toRemove;
			popFront = !popFront;
		}

		length = s.size() - toRemoveBack;
		for (int i = toRemoveFront; i < length; i++) {
			cout << s[i];
		}
		cout << endl;
	}
}