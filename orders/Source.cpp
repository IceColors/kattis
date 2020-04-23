#include <iostream>
#include <vector>
#include <map>

using namespace std;

void goThrough(vector< vector<int> >& ways, int& target, vector<int>& item, vector<int> route, int& found, int sum = 0, int level = 0) {
	if (sum == target) {
		ways.push_back(route);
		return;
	}
	if (sum > target) return;
	if (found > 2) return;
	int itemsize = item.size();
	for (int i = level; i < itemsize; i++) {
		int newSum = sum + item[i];
		route.push_back(i);
		goThrough(ways, target, item, route, found, newSum, i);
		route.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> item(0);
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		item[i] = a;
	}

	int m;
	cin >> m;


	while (m--) {
		vector< vector<int> > answers;
		cin >> a;
		int found = 0;
		goThrough(answers, a, item, vector<int>(), found);
		if (answers.size() == 0) cout << "Impossible\n";
		else if (answers.size() > 1) {
			cout << "Ambiguous\n";
			
		}

		else {
			int answersize = answers[0].size() - 1;
			for (int i = 0; i < answersize; i++) {
				cout << answers[0][i] + 1 << " ";
			}
			cout << answers[0].back() + 1;
			cout << '\n';
		}

	}
	cin >> a;
	return 0;
}