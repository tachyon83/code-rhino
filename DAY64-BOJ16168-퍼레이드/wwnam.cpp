#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int V, E;
vector<bool> check;
vector<vector<int> > graph;
vector<int> cntArr;
void dfs(int cur) {
	if (check[cur])
		return;
	check[cur] = true;

	int size = graph[cur].size();
	for (int i = 0; i < size; i++) {
		cntArr[cur]++;
		dfs(graph[cur][i]);
	}
}
int main(void) {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int u, v;

	cin >> V >> E;

	check.resize(V + 1, false);
	graph.resize(V + 1);
	cntArr.resize(V + 1, 0);
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0, ans = 0;
	for (int i = 1; i <= V; i++) {
		if (!check[i]) {
			cnt++;
			cntArr.assign(V + 1, 0);
			dfs(i);

			for (int i = 1; i <= V; i++) {
				if (cntArr[i] % 2 == 1) {
					ans++;
				}
			}
		}
	}

	if (cnt == 1 && (ans == 0 || ans == 2)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}