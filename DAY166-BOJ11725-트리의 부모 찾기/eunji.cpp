#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> tree(N + 1, vector<int>());
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	queue<int> q;
	q.push(1);
	int par[100001] = { 0, };
	int visit[100001] = { false, };
	visit[1] = true;

	while (!q.empty()) {
		int parnode = q.front();
		q.pop();
		for (int i = 0; i < tree[parnode].size(); i++) {
			if (!visit[tree[parnode][i]]) {
				par[tree[parnode][i]] = parnode;
				q.push(tree[parnode][i]);
				visit[tree[parnode][i]] = true;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << par[i] << "\n";
	}


}
