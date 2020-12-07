//크루스칼 사용
#include <iostream>
#include <vector>
#include <algorithm>
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
vector <edge> edges;
int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		edges.push_back({ from,to,val });
	}
	cout << kruskal();
	return 0;
}

int kruskal() {
	for (int i = 1; i <= V; i++) par[i] = i;
	int sum = 0;
	sort(edges.begin(), edges.end(), comp);
	for (int i = 0; i < edges.size(); i++) {
		if(!iscycle(edges[i])) sum += edges[i].val;
	}
	return sum;
}
int comp(const edge a,const edge b) {
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
