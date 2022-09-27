#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;


string lines[15000];
string sols[15000];
int characterCount[15000][26];
int bitmask[15000];
int lineLength[15000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n_lines = 0;

	while (cin >> lines[n_lines] && lines[n_lines][0] != '0') {
		lineLength[n_lines] = lines[n_lines].size();
		for (int i = 0; i < lineLength[n_lines]; i++) {
			characterCount[n_lines][lines[n_lines][i] - 'a']++;
			bitmask[n_lines] |= 1 << (lines[n_lines][i] - 'a');
		}
		++n_lines;
	}

	bool isDominant, allLettersContained;

	int n_sols = 0;

	for (int it1 = 0; it1 < n_lines; it1++) {
		isDominant = true;
		for (int it2 = 0; it2 < n_lines && isDominant; it2++) {
			if (it1 == it2) continue;

			// check bitmap
			// if for example 00101 and 11000 it is impossible to be superset
			// 00101 &~(11000) = 00101 & 00111 = 00101 != 0 currect
			// 00101 &~(00101) = 00101 & 11010 = 0 == 0		correct
			// 00101 &~(11111) = 00101 & 00000 = 0 == 0		correct

			if ((bitmask[it1] & ~bitmask[it2]) != 0)
				continue;

			// if it2 is equal or srmaller than it1, then it2 cannot be a superset of it1
			if (lineLength[it1] >= lineLength[it2])
				continue;
			
			allLettersContained = true;

			for (char c : lines[it1]) {
				if (characterCount[it1][c-'a'] > characterCount[it2][c-'a']) {
					allLettersContained = false;
				}
			}

			if (allLettersContained) {
				isDominant = false;
			}
		}
		if (isDominant) {
			sols[n_sols++] = lines[it1];
		}
	}

	sort(sols, sols + n_sols);
	for (int i = 0; i < n_sols; i++) {
		cout << sols[i] << '\n';
	}
}