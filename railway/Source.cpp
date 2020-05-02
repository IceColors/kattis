#include <iostream>
#include <string>

using namespace std;

void main() {
	int n, m;
	cin >> n >> m;

	int* Ai = new int[n];
	int* Bi = new int[n];
	int* Ci = new int[n];

	char* A = new char[n];
	char* B = new char[n];
	char* C = new char[n];

	for (int i = 0; i < m; i++) {
		string inp;
		cin >> inp;
		string s_number = inp.substr(0, inp.size()-1);
		int number = stoi(s_number);
		char letter = inp[inp.size() - 1];

		cin >> inp;
		s_number = inp.substr(0, inp.size() - 1);
		int number2 = stoi(s_number);
		char letter2 = inp[inp.size() - 1];

		if (letter == 'A') {
			Ai[number] = number2;
			Ai
		}
		else if (letter == 'B') {

		}
		else {

		}

	}

	delete[] A;
	delete[] B;
	delete[] C;
}