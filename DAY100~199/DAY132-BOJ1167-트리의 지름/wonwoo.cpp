#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int v, w;
};
int N, start, diameter;
vector<vector<struct Node> > adj;
vector<bool> visit;
void dfs(int v, int d) {
	if (visit[v]) {
		return;
	}

	visit[v] = true;

	if (diameter < d) {
		diameter = d;
		start = v;
	}

	int size = adj[v].size();
	for (int i = 0; i < size; i++) {
		dfs(adj[v][i].v, d + adj[v][i].w);
	}
}
int main(void) {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> N;
	adj = vector<vector<struct Node> >(N + 1, vector<struct Node>());
	visit = vector<bool>(N + 1, false);

	int u, v, w;
	for (int i = 0; i < N; i++) {
		cin >> u;
		while (1) {
			cin >> v;
			if (v == -1) {
				break;
			}

			cin >> w;
			adj[u].push_back({ v,w });
			adj[v].push_back({ u,w });
		}
	}

	dfs(1, 0);
	visit = vector<bool>(N + 1, false);
	diameter = 0;
	dfs(start, 0);

	cout << diameter;
}