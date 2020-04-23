#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ops[] = { '+','-','*','/' };
		int a;
		cin >> a;
		int j, h, g, sum;
		for (j = 0; j < 4; j++) {
			for (h = 0; h < 4; h++) {
				for (g = 0; g < 4; g++) {
					vector<int>nums(4, 4.0);
					vector<char>op = { ops[j],ops[h], ops[g] };
					for (int f = 0; f < op.size(); f++) {
						if (op[f] == '*'){
							nums[f] = nums[f] * nums[f + 1];
							nums.erase(nums.begin() + f + 1);
							op.erase(op.begin() + f);
							f--;
						}
						else if (op[f] == '/') {
							nums[f] = nums[f] / nums[f + 1];
							nums.erase(nums.begin() + f + 1);
							op.erase(op.begin() + f);
							f--;
						}
					}
					sum = nums[0];
					for (int f = 0; f < op.size(); f++) {
						if (op[f] == '+') {
							sum += nums[f + 1];
						}
						if (op[f] == '-') {
							sum -= nums[f + 1];
						}
					}
					if (sum == a) {
						goto done;
					}
				}
			}
		}
	done:;
		if (sum == a) {
			cout << "4 " << ops[j] << " 4 " << ops[h] << " 4 " << ops[g] << " 4 = " << a << endl;
		}
		else {
			cout << "no solution" << endl;
		}

	}


	return 0;
}