#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int minutes;
	string problem;
	string correct;

	map<string, int> punishment;
	int score = 0;
	int solved = 0;

	while (cin >> minutes && minutes != -1 && cin >> problem >> correct) {
		if (correct == "wrong" && punishment[problem] != -1) {
			punishment[problem] += 20;
		}
		else if(correct == "right" && punishment[problem] != -1){
			score += minutes + punishment[problem];
			solved++;
			punishment[problem] = -1;
		}
	}
	cout << solved << " " << score;

	return 0;
}