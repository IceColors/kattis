#include <iostream>

using namespace std;

int main() {
	int n, m;
	string last, b;
	cin >> n >> m >> last >> b;
	string ans(m, '0');
	for (int i = m - n, j = 0; i < m; i++) {
		ans[i] = last[j++];
	}
	for (int i = m - n-1; i >= 0; i--) {
		ans[i] = (((b[i + n] - 'a') - (ans[i + n]-'a') + 26) % 26)+'a';
	}
	cout << ans;
}