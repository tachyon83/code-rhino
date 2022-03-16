#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vc(n);
	vector<int> result(n);

	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}

	stack<int> stIdx;
	stack<int> stData;
	for (int i = 0; i < n; i++) {
		if (!stData.empty()) {
			while (!stData.empty()) {
				if (stData.top() < vc[i]) {
					result[stIdx.top()] = vc[i];
					stIdx.pop();
					stData.pop();
				}
				else {
					break;
				}
			}
		}

		stIdx.push(i);
		stData.push(vc[i]);
		result[i] = -1;

	}

	while (!stData.empty()) {
		result[stIdx.top()] = -1;
		stIdx.pop();
		stData.pop();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
