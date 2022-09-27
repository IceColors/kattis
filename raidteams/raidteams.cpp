#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> s1, s2, s3;
vector<pair<string, bool>> names;

bool sortbysec(const pair<int, int>& a,
	const pair<int, int>& b)
{
	if (a.second < b.second)
		return false;
	else if (a.second > b.second)
		return true;
	else if (lexicographical_compare(names[a.first].first.begin(), names[a.first].first.end(), names[b.first].first.begin(), names[b.first].first.end()))
		return true;
	else return false;
}



int main() {
	int N;
	cin >> N;




	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		long long ss1, ss2, ss3;
		cin >> ss1 >> ss2 >> ss3;
		s1.push_back(pair<long long, long long>(i, ss1));
		s2.push_back(pair<long long, long long>(i, ss2));
		s3.push_back(pair<long long, long long>(i, ss3));
		names.push_back(pair<string, bool>(name, false));

	}

	sort(s1.begin(), s1.end(), sortbysec);
	sort(s2.begin(), s2.end(), sortbysec);
	sort(s3.begin(), s3.end(), sortbysec);

	long long highestS1 = 0, highestS2 = 0, highestS3 = 0;
	while (highestS1 < N && highestS2 < N && highestS3 < N) {



		// velg første største ikke brukte fra s1

		while (names[s1[highestS1].first].second) {
			highestS1++;
			if (highestS1 == N) return 0; 
		}
		long long id1 = s1[highestS1].first;
		names[id1].second = true;

		// velg første største ikke brukte fra s2

		while (names[s2[highestS2].first].second) {
			highestS2++;
			if (highestS2 == N) return 0;
		}
		long long id2 = s2[highestS2].first;
		names[id2].second = true;

		// velg første største ikke brukte fra s3

		while (names[s3[highestS3].first].second) {
			highestS3++;
			if (highestS3 == N) return 0;
		}
		long long id3 = s3[highestS3].first;
		names[id3].second = true;

		vector<string> selected = { names[id1].first , names[id2].first, names[id3].first };
		sort(selected.begin(), selected.end());

		cout << selected[0] << " " << selected[1] << " " << selected[2] << endl;
	}
}