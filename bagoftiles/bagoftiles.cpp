#include <iostream>
#include <cstring>

using namespace std;


int leftArr[35][300005]{ { 0 } };
int rightArr[35][300005]{ { 0 } };


long binomialCoefficients(long n, long k) {
	long* C = new long[k + 1]{ 0 };
	C[0] = 1;
	for (long i = 1; i <= n; i++) {
		for (long j = min(i, k); j > 0; j--)
			C[j] = C[j] + C[j - 1];
	}
	long temp = C[k];
	delete[] C;
	return temp;
}

void addHalf(int tiles[], int n, int m, int offset, int arr[][300005]) {
	unsigned long maxSize = (1 << m);

	for (int i = 0; i < maxSize; i++) {
		int sum = 0;
		int curr = 0;
		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) {
				sum += tiles[j+offset];
				curr++;
			}
		}
		arr[curr][sum]++;
	}
}

int count(int tiles[], int n, int m, int t) {
	memset(leftArr, 0, sizeof(leftArr));
	memset(rightArr, 0, sizeof(rightArr));

	addHalf(tiles, n, m / 2, 0, leftArr);
	addHalf(tiles, n, m - m / 2, m / 2, rightArr);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= t; j++) {
			int curr = leftArr[i][j];
			sum += curr * rightArr[n - i][t - j];
		}
	}
	sum += leftArr[n][t] + rightArr[n][t];

	return sum;
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int g;
	cin >> g;
	for (int game = 1; game <= g; game++) {
		int m;
		cin >> m;
		int* tiles = new int[m];
		for (int i = 0; i < m; i++) {
			cin >> tiles[i];
		}
		int n, t;
		cin >> n >> t;

		int combinations = 0;
		int noncombs = 0;

		// finn alle kombinasjoner med n tiles for å få t
		if (n == 0 && t == 0 || m == 0)
			combinations = 1;
		else if (n == 0 && t > 0)
			noncombs = 1;
		else {
			combinations = count(tiles, n, m, t);
			noncombs = binomialCoefficients(m, n) - combinations;
		}
		

		cout << "Game " << game << " -- " << combinations << " : " << noncombs << '\n';

		delete[] tiles;
	}
}