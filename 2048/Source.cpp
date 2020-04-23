#include <iostream>

using namespace std;

int main() {
	int board[4][4];
	int a;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a;
			board[i][j] = a;
		}
	}
	int direction;

	cin >> direction;
	if (direction == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {

				for (int k = j; k < 3; k++) {
					if (board[i][j] == 0) {
						for (int l = j; l < 3; l++) {

							board[i][l] = board[i][l + 1];
						}
						board[i][3] = 0;
					}
					else if (board[i][j + 1] == 0) {
						for (int l = j + 1; l < 3; l++) {

							board[i][l] = board[i][l + 1];
						}
						board[i][3] = 0;
					}
				}

				if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
					board[i][j] *= 2;
					for (int l = j + 1; l < 3; l++) {
						board[i][l] = board[i][l + 1];
					}
					board[i][3] = 0;

				}
			}
		}
	}

	else if (direction == 1) {
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 3; i++) {


				for (int k = j; k < 3; k++) {
					if (board[i][j] == 0) {
						for (int l = i; l < 3; l++) {

							board[l][j] = board[l + 1][j];
						}
						board[3][j] = 0;
					}
					else if (board[i + 1][j] == 0) {
						for (int l = i + 1; l < 3; l++) {

							board[l][j] = board[l + 1][j];
						}
						board[3][j] = 0;
					}
				}

				if (board[i][j] != 0 && board[i][j] == board[i + 1][j]) {
					board[i][j] *= 2;
					for (int l = i + 1; l < 3; l++) {
						board[l][j] = board[l + 1][j];
					}
					board[3][j] = 0;

				}
			}
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 3; j > 0; j--) {

				for (int k = j; k > 0; k--) {
					if (board[i][j] == 0) {
						for (int l = j; l > 0; l--) {

							board[i][l] = board[i][l - 1];
						}
						board[i][0] = 0;
					}
					else if (board[i][j - 1] == 0) {
						for (int l = j - 1; l > 0; l--) {
							board[i][l] = board[i][l - 1];
						}
						board[i][0] = 0;
					}
				}

				if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
					board[i][j] *= 2;
					for (int l = j - 1; l > 0; l--) {
						board[i][l] = board[i][l - 1];
					}
					board[i][0] = 0;

				}
			}
		}
	}
	else if (direction == 3) {
		for (int j = 0; j < 4; j++) {
			for (int i = 3; i > 0; i--) {

				for (int k = i; k > 0; k--) {
					if (board[i][j] == 0) {
						for (int l = i; l > 0; l--) {
							board[l][j] = board[l - 1][j];
						}
						board[0][j] = 0;
					}
					else if (board[i - 1][j] == 0) {
						for (int l = i - 1; l > 0; l--) {
							board[l][j] = board[l - 1][j];
						}
						board[0][j] = 0;
					}
				}

				if (board[i][j] != 0 && board[i][j] == board[i - 1][j]) {
					board[i][j] *= 2;
					for (int l = i - 1; l > 0; l--) {
						board[l][j] = board[l - 1][j];
					}
					board[0][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cin >> a;
	return 0;
}
