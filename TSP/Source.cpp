#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector< vector<float> > coordinates;
vector<int> tour;


void GreedyTour(int);
float dist(int, int);


int main() {

	float x, y;
	int num;
	cin >> num;
	coordinates.push_back(vector<float>());

	for (int i = 0; i < num; i++) {

		cin >> x;
		cin >> y;
		coordinates.push_back(vector<float>());
		coordinates[i].push_back(x);
		coordinates[i].push_back(y);


	}
	for (int i = 0; i < num; i++) {
		tour.push_back(i);
	}
	GreedyTour(num);


	for (int i = 0; i < tour.size(); i++) {
		cout << tour[i] << endl;
	}
	cin >> num;

	return 0;
}

void GreedyTour(int n) {
	vector<bool> used(n, false);
	used[0] = true;
	for (int i = 1; i < n; i++) {
		int best = -1;
		for (int j = 0; j < n; j++) {
			if (!used[j] && (best == -1 || dist(tour[i - 1], j) < dist(tour[i - 1], best))) {
				best = j;
			}
		}
		tour[i] = best;
		used[best] = true;
	}
}

float dist(int a, int b) {
	return (sqrt(pow(coordinates[a][0] - coordinates[b][0], 2)) + sqrt(pow(coordinates[a][1] - coordinates[b][1], 2)));
}