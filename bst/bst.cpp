#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int depths[300000*2+2];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	set<int> nodes;
	while (n--) {

		static long long  totalDepth = 0;

		int a;
		cin >> a;

		nodes.insert(a);
		int depth = 0;

		set<int>::iterator it = nodes.find(a);
		if (it != nodes.begin()) {
			it--;
			depth = max(depths[*(it)], depth);
			it++;
		}
		if (it != nodes.end()) {
			it++;
			if(it != nodes.end())
				depth = max(depths[*(it)], depth);
			it--;
		}

		depths[a] = depth+1;
		totalDepth += depth;
		
		cout << totalDepth << '\n';
	}
}