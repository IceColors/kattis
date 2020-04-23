#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, m;

	cin >> n >> m;

	vector<int> probs(m + n + 1, 0);
	int highest = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			probs[i + j]++;
			if (probs[i + j] > probs[highest]) highest = i + j;
		}
	}

	cout << highest << "\n";
	while (highest < probs.size() - 1 && probs[highest + 1] == probs[highest]) {
		highest++;
		cout << highest << "\n";
		
	}


	return 0;
}