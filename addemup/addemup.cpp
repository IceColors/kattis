#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	pair<long, long>* numbers = new pair<long, long>[200000];
	string nString;
	string sString;
	long i = 0;
	char c;
	while (cin.get(c) && c != '\n')
		if (!std::isspace(c))
		{
			std::cerr << "ERROR unexpected character '" << c << "' found\n";
			exit(EXIT_FAILURE);
		}
	getline(cin, sString);
	stringstream ss(sString);
	while (ss >> nString) {
		numbers[i] = pair<long, long>(-1, -1);
		numbers[i].first = stol(nString);
		if (nString.find_first_of('4') == string::npos && nString.find_first_of('7') == string::npos && nString.find_first_of('3') == string::npos) {
			string rString = "";
			for(int j = nString.size() - 1; j >= 0; j--){
				if (nString[j] == '1' || nString[j] == '8' || nString[j] == '0') {
					rString += nString[j];
				}
				else if (nString[j] == '2')
					rString += '2';
				else if (nString[j] == '5')
					rString += '5';
				else if (nString[j] == '6')
					rString += '9';
				else if (nString[j] == '9')
					rString += '6';
			}
			numbers[i].second = stol(rString);
		}
		i++;
	}
	bool flag = false;

	for (int j = 0; j < i; j++) {
		if (flag)
			break;
		for(int k = j+1; k < i; k++){
			pair<long, long> temp1 = numbers[j], temp2 = numbers[k];
			if (numbers[j].first + numbers[k].first == s) {
				flag = true;
				break;
			}
			else if (numbers[j].second != -1 && numbers[j].second + numbers[k].first == s) {
				flag = true;
				break;
			}
			else if (numbers[k].second != -1 && numbers[k].second + numbers[j].first == s) {
				flag = true;
				break;
			}
			else if (numbers[j].second != -1 && numbers[k].second != -1 && numbers[j].second + numbers[k].second == s) {
				flag = true;
				break;
			}
		}
	}

	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	delete[] numbers;
}