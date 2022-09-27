#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

double clip(double n, double lower, double upper) {
	return max(lower, min(n, upper));
}

int main() {
	unsigned int n, k;
	cin >> n >> k;

	long long* heights = new long long [n + 1];

	for (unsigned int i = 0; i < n + 1; i++) {
		cin >> heights[i];
	}

	for (unsigned int i = 0; i < k; i++) {
		double g;
		cin >> g;
		double* heights2 = new double[n + 1];
		for (unsigned int j = 0; j < n + 1; j++) {
			heights2[j] = heights[j] - g*10*j;
		}
		int* heights3 = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			heights3[j] = j;
		}
		stable_sort(heights3, heights3+n+1, [&](int k, int l) { return heights2[k] < heights2[l]; });
		double length = -1;
		long long a = 10000000000000;
		for (int j = 0; j < n+1; j++) {
			if (a > heights3[j]) a = heights3[j];
			else {
				int xa = a;
				int xb = heights3[j];
				double rest = 0;
				if (xa > 0) rest = max(rest, (double)(heights2[xb] - heights2[xa]) / abs(heights2[xa] - heights2[xa-1]));
				if (xb < n) rest = max(rest, (double)(heights2[xb] - heights2[xa]) / abs(heights2[xb+1] - heights2[xb]));
				length = max(length, xb - xa + clip(rest, 0.0, 1.0));
			}
			
		}
		delete[] heights3;
		delete[] heights2;
		if (length > 0) cout << fixed << setprecision(20) << length << endl;
		else cout << "impossible" << endl;

	}
}