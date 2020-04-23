#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n, m, a;
	cin >> n;

	while (n--) {
		cin >> m;
		vector<int> moves;
		int maxDist = 0;
		for (int i = 0; i < m; i++) {
			cin >> a;
			moves.push_back(a);
			maxDist += a;
		}
		vector< vector<int> > bestMoves(m+1, vector<int>(maxDist+1, INT_MAX));
		vector<char> moveMax(m);
		bestMoves[0][0] = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= maxDist; j++) {
				if (bestMoves[i][j] != INT_MAX) {

					int upPos = j + moves[i];
					int downPos = j - moves[i];
					
					if (bestMoves[i + 1][upPos] > (bestMoves[i][j] > upPos ? bestMoves[i][j] : upPos)) {
						bestMoves[i + 1][upPos] = (bestMoves[i][j] > upPos ? bestMoves[i][j] : upPos);
					}

					if (downPos >= 0) {
						if (bestMoves[i + 1][downPos] > bestMoves[i][j]) {
							bestMoves[i + 1][downPos] = bestMoves[i][j];
						}
					}

				}
			}
		}

		for (int i = 0; i <= m; i++) {
			for (int j = 0; j < maxDist; j++) {
				if (bestMoves[i][j] != INT_MAX) {
				}
			}
		}
		string ans;

		if (bestMoves[m][0] == INT_MAX) cout << "IMPOSSIBLE\n";

		else {
			int pos = 0; 
			for (int i = m; i > 0; i--) {
				if (pos - moves[i - 1] >= 0) {

					if (bestMoves[i - 1][pos - moves[i - 1]] > bestMoves[i - 1][pos + moves[i - 1]]) {
						pos += moves[i - 1];
						ans.append("D");
					}
					else {
						pos -= moves[i - 1];
						ans.append("U");
					}
				}
				else {
					pos += moves[i - 1];
					ans.append("D");
				}
			}
			reverse(ans.begin(), ans.end());
			cout << ans << endl;
		}


	}
	cin >> a;

	return 0;
}