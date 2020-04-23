#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int main() {
	int n, com, x;
	while (cin >> n) {
		bool st = true;
		bool qu = true;
		bool pr = true;
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;

		for (int i = 0; i < n; i++) {
			cin >> com;
			cin >> x;
			if (com == 1) {
				s.push(x);
				q.push(x);
				p.push(x);
			}
			else {
				if (s.size() > 0) {
					if (s.top() != x) st = false;
					s.pop();

					if (q.front() != x)	qu = false;
					q.pop();

					if (p.top() != x) pr = false;
					p.pop();
				}
				else st = qu = pr = false;
			}
		}



		if (st && !(qu || pr)) cout << "stack" << endl;
		else if (qu && !(st || pr)) cout << "queue" << endl;
		else if (pr && !(qu || st)) cout << "priority queue" << endl;
		else if (pr && qu || pr && st || st && qu) cout << "not sure" << endl;
		else cout << "impossible" << endl;
	}

	return 0;
}