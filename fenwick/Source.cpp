#include <iostream>


using namespace std;

long long getSum(long long tree[],	long long index) {
	long long sum = tree[0];

	while (index > 0) {
		sum += tree[index];
		index -= index & (-index);
	}
	return sum;
}

void addToTree(long long tree[], long long n, long long index, long long value) {
	index++;
	while (index < n + 5) {
		tree[index] += value;
		index += index & (-index);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, q;
	cin >> n >> q;
	char b;
	cin.ignore();
	long long ind, num;

	long long *tree = new long long[n+1]();

	for (long long i = 0; i < q; i++) {
		cin >> b >> ind;
		if (b == '+') {
			cin >> num;
			addToTree(tree, n, ind, num);
		}
		else if (b == '?') {
			cout << getSum(tree, ind) << '\n';
		}
	}

	delete[] tree;
	return 0;
}