#include <iostream>
#include <vector>


using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long int> list;
	vector< pair<long int, long int> > rightAndLeft;

	int a;
	cin >> a;
	list.push_back(a);
	long int left = list[0];
	rightAndLeft.push_back(pair<long int, long int>());
	rightAndLeft[0].first = left;

	for (int i = 1; i < n; i++) {
		cin >> a;
		list.push_back(a);
		rightAndLeft.push_back(pair<long int, long int>());
		rightAndLeft[i].first = left;
		left = (a > left ? a : left);
	}
	long int right = list[n-1];

	for (int i = n-1; i > -1; i--) {
		rightAndLeft[i].second = right;
		right = (list[i] > right ? right : list[i]);
	}
	int counter = 0;
	
	for (int i = 0; i < n; i++) {

		if (list[i] >= rightAndLeft[i].first && rightAndLeft[i].second > list[i] || i == n-1 && list[i] >= rightAndLeft[i].first) {
			counter++;
		}
	}
	cout << counter;



	return 0;
}