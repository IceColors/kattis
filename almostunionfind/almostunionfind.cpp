#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n && cin >> m) {
		

		vector<set<long>> sets(n + 1);
		vector<unsigned long long> sum(n + 1);
		vector<long> ind(n + 1);

		for (int i = 0; i <= n; i++) {
			sets[i].insert(i);
			sum[i] = i;
			ind[i] = i;
		}

		for (int i = 0; i < m; i++) {
			int o;
			cin >> o;
			if (o == 1) {
				int p, q;
				cin >> p >> q;

				int setp = ind[p];
				int setq = ind[q];
				
				if (setq == setp) continue;

				if (sets[setp].size() > sets[setq].size()) {
					swap(setp, setq);
				}

				for (auto e : sets[setp]) {
					ind[e] = setq;
					sets[setq].insert(e);
				}
				sum[setq] += sum[setp];
				sum[setp] = 0;
				sets[setp].clear();
			}
			if (o == 2) {
				int p, q;
				cin >> p >> q;

				int setp = ind[p];
				int setq = ind[q];

				if (setq == setp) continue;

				sets[setq].insert(p);
				sets[setp].erase(p);
				sum[setq] += p;
				sum[setp] -= p;
				ind[p] = setq;
			}
			if (o == 3) {
				int p;
				cin >> p;
				int setp = ind[p];

				cout << sets[setp].size() << " " << sum[setp] << '\n';
			}
		}
	}
}