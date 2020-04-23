#include <iostream>
#include <string>


using namespace std;

int main() {

	string encoded;
	string decoded;
	getline(cin, encoded);
	for (int i = 0; i < encoded.length(); i++) {
		decoded += encoded[i];
		if (encoded[i] == 'a'
			|| encoded[i] == 'e'
			|| encoded[i] == 'i'
			|| encoded[i] == 'o'
			|| encoded[i] == 'u') 
		{
			i += 2;
		}
	}
	cout << decoded;

	return 0;
}