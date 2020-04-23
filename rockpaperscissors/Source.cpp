#include <iostream>
#include <vector>
#include <string>


using namespace std;


int main() {

	int n, k;

	while (cin >> n && n != 0 && cin >> k) {
		vector< pair<int, int> > player(n, pair<int, int>(0, 0));
		int games = (n * k * (n - 1)) / 2; 
		int indA, indB;
		string moveA, moveB;

		for (int i = 0; i < games; i++) {
			cin >> indA >> moveA >> indB >> moveB;
			indA--;
			indB--;
			if (moveA == "rock" && moveB == "scissors" ||
				moveA == "scissors" && moveB == "paper" ||
				moveA == "paper" && moveB == "rock") {
				player[indA].first++;
				player[indA].second++;
				player[indB].second++;
			}
			else if (moveB == "rock" && moveA == "scissors" ||
				moveB == "scissors" && moveA == "paper" ||
				moveB == "paper" && moveA == "rock") {
				player[indB].first++;
				player[indB].second++;
				player[indA].second++;
			}
		}

		for (int i = 0; i < n; i++) {
			cout.precision(3);
			if (player[i].second) cout << fixed << (double)player[i].first / player[i].second << endl;
			else cout << "-" << endl;
		}
		cout << endl;
	}


	

	return 0;
}