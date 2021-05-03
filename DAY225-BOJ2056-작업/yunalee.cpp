#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000;

int main() {
	int idx[MAX] = { 0 }, n, a[MAX], d[MAX] = { 0 };
	queue<int> q;
	vector<int> arr[MAX];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k, x;
		cin >> k >> x;
		a[i] = k;
		for (int j = 0, v; j < x; j++) {
			cin >> v;
			arr[v].push_back(i);
			idx[i]++;
		}
	}

	for (int i = 1; i <= n; i++){
		if (idx[i] == 0) {
			q.push(i);
			d[i] = a[i];
		}
	}


	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : arr[cur]) {
			d[next] = max(d[next], d[cur] + a[next]);
			idx[next]--;
			if (idx[next] == 0) {
				q.push(next);

			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, d[i]);
	}

	cout << result << '\n';

}
