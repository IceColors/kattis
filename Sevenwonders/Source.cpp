#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;



int main() {
	int T, C, G;
	string a;
	getline(cin, a);

	T = count(a.begin(), a.end(), 'T');
	C = count(a.begin(), a.end(), 'C');
	G = count(a.begin(), a.end(), 'G');

	cout << pow(T, 2) + pow(C, 2) + pow(G, 2) + min(T, min(C, G)) * 7;

	return 0;
}