#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	int longestTime = 0;
	vector<int> trees;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b;
		trees.push_back(b);
	}
	sort(trees.rbegin(), trees.rend());


	for (int i = 0; i < a; i++) {
		if (longestTime < trees[i] + i + 2) longestTime = trees[i] + i + 2;
	}

	cout << longestTime;
	return 0;
}