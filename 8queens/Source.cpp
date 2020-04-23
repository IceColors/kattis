#include <iostream>

using namespace std;

int main() {

	int chessboard[8][8] = {};
	int illegalboard[8][8] = {};
	int valid = true;
	int nq = 0;

	char a;
	int b;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			cin >> a;

			while (a != '*' && a != '.') {
				cin >> a;
			}

			if (a == '.') { b = 0; }
			else { b = 1; nq++;
			}
			chessboard[i][j] = b;
			

		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chessboard[i][j] == 1) {
				for (int k = 0; k < 8; k++) {
					if (!(k == j)) {
						illegalboard[i][k] = 1;
					}
					if (!(k == i)) {
						illegalboard[k][j] = 1;
					}
					int row = i;
					int col = j;
					while (++row != 8 && ++col != 8) {
						illegalboard[row][col] = 1;
					}
					row = i;
					col = j;
					while (++row != 8 && --col != -1) {
						illegalboard[row][col] = 1;
					}
					row = i;
					col = j;
					while (--row != -1 && ++col != 8) {
						illegalboard[row][col] = 1;
					}
					row = i;
					col = j;
					while (--row != -1 && --col != -1) {
						illegalboard[row][col] = 1;
					}
				}

			}
		}
	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (illegalboard[i][j] && chessboard[i][j]) {
				valid = false;
			}
		}
	}
	if (nq != 8) valid = false;

	if (valid) cout << "valid";
	else cout << "invalid";

	return 0;
}