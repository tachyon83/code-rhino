#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	int sum = 0;
	while (pq.size() > 1) {
		int f = pq.top();
		pq.pop();
		int s = pq.top();
		pq.pop();

		sum += (f + s);

		pq.push(f + s);
	}

	cout << sum << '\n';

	return 0;
}
