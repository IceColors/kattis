#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	// [dna][letter index]  where gene letter will be 0 = A, 1 = C, 2 = G, 3 = T
	vector< vector<int> > dna(4101, vector<int>(4101, 0));

	// use abstract algebra for unique values for how many mistakes
	// create cyclic group
	// generator must be over N (4100 for the largest)
	// group size (p) must be 4100 * 4100

	// ------------------------------------
	// BE CAREFUL TO NOT USE TOO LARGE SIZE, OVERFLOW OR SOMETHING

	// use the elgamal script to generate a prime and safe generator
	// 64 bit has to be more than enough --- too much
	// generator has to be checked

	long long p = 3364350503, g = 5795553;

	// each dna gets a value from the generator
	// then for each col we can get an unique sum from that value
	vector<vector<long long>> colVals(m, vector<long long>(4, 0));

	vector<long long> powers(n);

	powers[0] = 1;
	for (long long i = 1; i < n; i++) {
		powers[i] = (powers[i - 1] * g) % p;
	}




	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			int val = 0;
			if (s[j] == 'A')
				dna[i][j] = 0;
			else if (s[j] == 'C')
				dna[i][j] = 1;
			else if (s[j] == 'G')
				dna[i][j] = 2;
			else if (s[j] == 'T')
				dna[i][j] = 3;
		}
	}

	// calculate the sum (which can tell which dna had the letter in the col) for each letter in each col
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			colVals[j][dna[i][j]] = (colVals[j][dna[i][j]] + powers[i]) % p;
		}
	}

	for (int i = 0; i < n; i++) {
		// expect to find k mistakes from each dna except the O.G. one, and since you can sum the unique values from the dnas and get another unique value, we can just check
		long long sum = 0;
		for (int j = 0; j < n; j++) {
			if (j == i)
				continue;
			sum = (sum + k * powers[j]) % p;
		}

		// now check if we get the same sum when we assume dna[i] is the correct dna
		long long check = 0;
		for (int j = 0; j < m; j++) {
			for (int h = 0; h < 4; h++) {
				if (dna[i][j] == h) 
					continue;
				check = (check + colVals[j][h]) % p;
			}
		}
		/*
		cout << "i : " << i << endl;
		cout << "check: " << check << endl;
		cout << "sum: " << sum << endl;
		*/
		if (check == sum) {
			cout << i + 1 << endl;
			break;
		}

	}
}