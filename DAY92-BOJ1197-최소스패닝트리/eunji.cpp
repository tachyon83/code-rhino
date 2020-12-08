//크루스칼과 프림알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct {
	int from;
	int to;
	int val;
}edge;
int par[10001];
int V, E;
bool iscycle(edge eg);
int find(int k);
int kruskal();
int comp(const edge a, const edge b);
int prim();
vector <edge> edges;
vector<pair<int, int>> edges2[10001];
int main() {
	cin >> V >> E;
	//true->prim   false->kruskal
	int flag = true;
	if (E < V) flag = false;

	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		if (flag) {
			edges2[from].push_back({ to,val });
			edges2[to].push_back({ from,val });
		}
		else  edges.push_back({ from,to,val });
	}

	if (flag) cout << prim();
	else cout << kruskal();

	return 0;
}

//크루스칼-간선의 갯수가 작을때
int kruskal() {
	for (int i = 1; i <= V; i++) par[i] = i;
	int sum = 0;
	sort(edges.begin(), edges.end(), comp);

	for (int i = 0; i < edges.size(); i++) {
		if (!iscycle(edges[i])) sum += edges[i].val;
	}

	return sum;
}
int comp(const edge a, const edge b) {
	return a.val < b.val;
}
bool iscycle(edge eg) {
	int u = find(eg.from);
	int v = find(eg.to);

	if (u == v) return true;
	par[u] = v;
	return false;
}
int find(int k) {
	if (par[k] == k) return k;
	return 	par[k] = find(par[k]);
}

//프림-간선의 갯수가 클때
int prim() {
	int sum = 0;
	bool visit[100001] = { false, };
	//임의로 1부터 시작
	visit[1] = true;

	priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < edges2[1].size(); i++) {
		pq.push({ edges2[1][i].second,edges2[1][i].first });
	}
	while (!pq.empty()) {
		int val = pq.top().first;
		int next = pq.top().second;
		pq.pop();
		if (visit[next]) continue;
		visit[next] = true;
		sum += val;
		for (int i = 0; i < edges2[next].size(); i++) {
			pq.push({ edges2[next][i].second,edges2[next][i].first });
		}
	}

	return sum;
}
