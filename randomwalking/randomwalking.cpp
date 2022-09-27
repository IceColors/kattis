#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> nodes;
vector<vector<double>> numbers;
vector<vector<double>> bits;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n, e;
	while (cin >> k >> n >> e && k && n && e) {
		long long n2 = 1L << n;
		nodes = vector < vector<int>>(n2, vector<int>());
		numbers = vector<vector<double>>(k, vector<double>(n2, 0));
		bits = vector<vector<double>>(k, vector<double>(n, 0));

		for (int i = 0; i < e; i++) {
			int v0, v1;
			cin >> v0 >> v1;
			nodes[v0].push_back(v1);
			nodes[v1].push_back(v0);
		}

		double percentage = 1.0 / n2;
		for (int i = 0; i < n2; i++) {
			numbers[0][i] = percentage;
		}

		bool flag = false;
		for (int i = 1; i < k; i++) {
			for (int j = 0; j < n2; j++) {
				for (int m = 0; m < nodes[j].size(); m++) {
					int pN = nodes[j][m];
					numbers[i][j] += numbers[i - 1][pN] / nodes[pN].size();
				}
			}
			for (int j = 0; j < n; j++) {
				double jBitPercentage = 0;
				for (int m = 0; m < n2; m++) {
					// if number contains bit
					if ((1L << j) & m) {
						jBitPercentage += numbers[i][m];
					}
				}
				if (jBitPercentage <= 0.25 || jBitPercentage >= 0.75) {
					flag = true;
					break;
				}
			}

			if (flag)
				break;
		}
		if (flag) cout << "No\n";
		else cout << "Yes\n";
	}


}