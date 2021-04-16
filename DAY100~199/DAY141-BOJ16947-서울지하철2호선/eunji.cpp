#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int par[3001];
vector<int> adj[3001];
bool cycle[3001] = { false, };
bool visit[3001] = { false, };
void unionPath(int u, int k);
int find(int u);
bool findCycle(int u, int s, int depth);
int bfs(int k);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		unionPath(x, y);
	}
	//findCycle(cycleStart);
	for (int i = 1; i <= N; i++) {
		cout << bfs(i) << " ";
	}

}
void unionPath(int u, int k) {
	int paru = find(u);
	int park = find(k);
	if (paru != park) par[paru] = park;
	else { cycle[u] = true; visit[u] = true;	findCycle(u, u, 0); }

}

int find(int u) {
	if (par[u] == u) return u;
	return par[u] = find(par[u]);
}

bool findCycle(int u, int s, int depth) {
	if (u == s && depth > 1) return true;

	for (int i = 0; i < adj[u].size(); i++) {
		if (adj[u][i] == s && depth > 1) return true;
		if (visit[adj[u][i]]) continue;
		visit[adj[u][i]] = true;
		cycle[adj[u][i]] = true;
		if (findCycle(adj[u][i], s, depth + 1)) return true;
		cycle[adj[u][i]] = false;
	}
	return false;
}

int bfs(int k) {
	bool visit[3001] = { false, };
	queue<pair<int, int>> q;
	q.push({ k,0 });
	visit[k] = true;
	while (!q.empty()) {
		int num = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (cycle[num]) return depth;
		for (int i = 0; i < adj[num].size(); i++) {
			if (!visit[adj[num][i]]) {
				visit[adj[num][i]] = true;
				q.push({ adj[num][i] , depth + 1 });
			}
		}
	}
	return 0;
}
