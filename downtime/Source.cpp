#include <iostream>
#include <list>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	list<int> req;
	int record = 0;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		req.push_back(a);
		while (req.back() - req.front() >= 1000) req.pop_front();
		if (req.size() > record) record = req.size();
	}

	int servers = record / k;
	if (record%k) servers++;
	cout << servers;



	return 0;
}