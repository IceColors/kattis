#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<double, double>> bugs {};

vector<vector<vector<double>>> calculated;
int fails[10];

int ntime, nbugs;
double frate;

double prob(int t, int bitmask, int num) {
	if (t == ntime || bitmask == ((1 << nbugs) - 1)) return 0;
	if (calculated[t][bitmask][num] == -1) {
		int best = -1;
		double bestVal = -1;
		for (int i = 0; i < nbugs; i++) {
			if(bitmask & (1<<i))
				continue;
			if (bugs[i].first * bugs[i].second > bestVal) {
				bestVal = bugs[i].first * bugs[i].second;
				best = i;
			}
		}

		double oldPercent = bugs[best].first;
		bugs[best].first *= frate;
		fails[best]++;
		double value = (1 - oldPercent) * prob(t + 1, bitmask, num + 1);

		bugs[best].first = oldPercent;
		fails[best]--;

		// verdi fra at man fikser en bug = sannsynlighetn for å fikse den * (verdien + verdiene fra resten når den er fikset)
		value += bugs[best].first * (bugs[best].second + prob(t + 1, bitmask | (1 << best), num - fails[best]));
		calculated[t][bitmask][num] = value;
	}
	return calculated[t][bitmask][num];
}

int main() {
	cin >> nbugs >> ntime >> frate;
	calculated = vector<vector<vector<double>>>(100, vector<vector<double>>(1<<10, vector<double>(100, -1)));


	for (int i = 0; i < nbugs; i++) {
		double t1, t2;
		cin >> t1 >> t2;
		bugs.push_back(make_pair(t1, t2));
	}

	cout.precision(15);
	cout << prob(0, 0, 0) << endl;
}