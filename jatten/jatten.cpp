#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	long long M, N, x1, x2, y1, y2;
	cin >> N >> M >> x1 >> y1 >> x2 >> y2;

	// plan
	// sjekk rundt verteksene
	//sjekk rundt midten
	// pass på å få verteksene i inter

	long double a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	long double relation1 = ((long double)x1 - x2) / (y1 - y2);

	long long middlex1 = (x1 + x2) / 2;
	long long middlex2 = ceil((x1 + x2) / 2.0);

	long long middley1 = (y1 + y2) / 2;
	long long middley2 = ceil((y1 + y2) / 2.0);

	vector<pair<long long, long long>> interesting = { {x1, y1}, {x2, y2}, {middlex1, middley1},{middlex2, middley2}, {0, 0}, {0, M - 1}, {N - 1, 0},{N - 1, M - 1} };

	// go around point

	for (pair<long long, long long> p : interesting)
	{
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				pair<long long, long long> point = p;
				point.first += i;
				point.second += j;

				//ensure not outside
				if (point.first < 0 || point.first >= N || point.second < 0 || point.second >= M)
					continue;

				// ensure the point isn't in the other one
				if (point.first == x1 && point.second == y1 || point.first == x2 && point.second == y2)
					continue;

				// ensure not on the line 
				long double relation2 = ((long double)x1 - point.first) / (y1 - point.second);
				if (relation1 == relation2 || relation1 == -relation2)
					continue;

				if (x1 - x2 == 0 && point.first == x1) {
					continue;
				}

				if (y1 - y2 == 0 && point.second == y1) {
					continue;
				}

				long double b = (x1 - point.first) * (x1 - point.first) + (y1 - point.second) * (y1 - point.second);
				long double c = (x2 - point.first) * (x2 - point.first) + (y2 - point.second) * (y2 - point.second);

				if (a + b == c || b + c == a || a + c == b) {
					continue;
				}
				else if (a + b < c || b + c < a || a + c > b) {
					cout << point.first << " " << point.second << endl;
					return 0;
				}
			}
		}
		

	}

}