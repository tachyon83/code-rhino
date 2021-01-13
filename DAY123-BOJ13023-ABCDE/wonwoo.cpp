#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > adj;
vector<bool> check;
int N, M, flag = 0;
void dfs(int cur, int cnt) {
	if (cnt == 4) {
		flag = 1;
		return;
	}

	check[cur] = true;
	int size = adj[cur].size();
	for (int i = 0; i < size; i++)
	{
		int next = adj[cur][i];
		if (!check[next]) {
			dfs(next, cnt + 1);
		}
		if (flag) {
			return;
		}
	}
	check[cur] = false;
}
int main(void) {
	cin.tie(0);	cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> N >> M;

	adj.resize(N);
	check.resize(N, false);
	int s, e;
	for (int i = 0; i < M; i++)	{
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 0; i < N; i++) {
		dfs(i, 0);
	}

	cout << flag;
}