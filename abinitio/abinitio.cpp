#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long v, e, q;
	cin >> v >> e >> q;

	vector<bitset<4000>> nodes(4000, bitset<4000>(0));
	long long a, b;
	for (long long i = 0; i < e; i++) {
		cin >> a >> b;
		nodes[a][b] = true;
	}

	bool isInverted = false;
	bool isTrans = false;
	
	for (long long i = 0; i < q; i++) {
		/*
		cout << endl << endl;
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (isInverted && !isTrans) {
					cout << !nodes[i][j] << " ";
				}
				else if (isInverted && isTrans) {
					cout << !nodes[j][i] << " ";
				}
				else if (!isInverted && !isTrans) {
					cout << nodes[i][j] << " ";
				}
				else if (!isInverted && isTrans) {
					cout << nodes[j][i] << " ";
				}

			}
		
			cout << endl << endl;
		}
		cout << endl;
		*/
		long long query;
		cin >> query;
		if (query == 1) {
			// add vertex 
			v++;
			if (isInverted) {
				for (auto& n : nodes) {
					n[v - 1] = 1;
				}
				nodes[v - 1].set();
			}
			if (!isInverted) {
				for (auto& n : nodes) {
					n[v - 1] = 0;
				}
				nodes[v - 1] = 0;
			}
		}
		else if (query == 2) {
			// add edge 
			cin >> a >> b;
			if (isInverted && !isTrans) {
				nodes[a][b] = 0;
			}
			else if (isInverted && isTrans) {
				nodes[b][a] = 0;
			}
			else if (!isInverted && !isTrans) {
				nodes[a][b] = 1;
			}
			else if (!isInverted && isTrans) {
				nodes[b][a] = 1;
			}

		}
		else if (query == 3) {
			// delete all edges to and from node
			cin >> a;
			if (isInverted) {
				for (auto& n : nodes) {
					n[a] = 1;
				}
				nodes[a].set();
			}
			if (!isInverted) {
				for (auto& n : nodes) {
					n[a] = 0;
				}
				nodes[a] = 0;
			}

		}
		else if (query == 4) {
			// remode edge from a to b
			cin >> a >> b;
			if (isInverted && !isTrans) {
				nodes[a][b] = 1;
			}
			else if (isInverted && isTrans) {
				nodes[b][a] = 1;
			}
			else if (!isInverted && !isTrans) {
				nodes[a][b] = 0;
			}
			else if (!isInverted && isTrans) {
				nodes[b][a] = 0;
			}
		}
		else if (query == 5) {
			// transpose graph
			isTrans = !isTrans;

		}
		else if (query == 6) {
			// complement graph
			isInverted = !isInverted;
		}
	}

	// output

	// precalc powers
	vector<long long> pows(4000, 0);
	pows[0] = 1;
	for (int i = 1; i < v; i++) {
		pows[i] = (pows[i - 1] * 7) % 1000000007;
	}
	/*
	cout << endl << endl;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (isInverted && !isTrans) {
				cout << !nodes[i][j] << " ";
			}
			else if (isInverted && isTrans) {
				cout << !nodes[j][i] << " ";
			}
			else if (!isInverted && !isTrans) {
				cout << nodes[i][j] << " ";
			}
			else if (!isInverted && isTrans) {
				cout << nodes[j][i] << " ";
			}
			
		}
		cout << endl << endl;
	}
	*/

	cout << v << '\n';
	for (int i = 0; i < v; i++) {
		int outdegree = 0;
		for (int j = 0; j < v; j++) {
			if (i == j) continue;
			if (isInverted && !isTrans) {
				outdegree += !nodes[i][j];
			}
			else if (isInverted && isTrans) {
				outdegree += !nodes[j][i];
			}
			else if (!isInverted && !isTrans) {
				outdegree += nodes[i][j];
			}
			else if (!isInverted && isTrans) {
				outdegree += nodes[j][i];
			}
			
		}
		long long hash = 0;
		for (int d = 0, j = 0; j < v; j++) {
			if (i == j) continue;
			if (isInverted && !isTrans) {
				if (!nodes[i][j])
					hash = (hash + j * pows[d++] % 1000000007) % 1000000007;
			}
			else if (isInverted && isTrans) {
				if (!nodes[j][i])
					hash = (hash + j * pows[d++] % 1000000007) % 1000000007;
			}
			else if (!isInverted && !isTrans) {
				if (nodes[i][j])
					hash = (hash + j * pows[d++] % 1000000007) % 1000000007;
			}
			else if (!isInverted && isTrans) {
				if (nodes[j][i])
					hash = (hash + j * pows[d++] % 1000000007) % 1000000007;
			}
			
		}
		hash %= 1000000007;
		cout << outdegree << " " << hash << '\n';;
	}
}