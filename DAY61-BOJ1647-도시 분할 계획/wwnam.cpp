#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int weight, src, dst;
};
int V, E;
vector<int> parent;
vector<edge> graph;
bool compareEdge(edge a, edge b) {
	return a.weight < b.weight;
}
int findParent(int x) {
	if (parent[x] != x) {
		parent[x] = findParent(parent[x]);
	}
	return parent[x];
}
void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}
int kruskal() {
	int ans = 0, size = graph.size();
	int w, s, d, last;

	for (int i = 0; i < size; i++)
	{
		w = graph[i].weight;
		s = graph[i].src;
		d = graph[i].dst;

		if (findParent(s) != findParent(d)) {
			unionParent(s, d);
			ans += w;
			last = w;
		}
	}

	ans -= last;
	return ans;
}
int main(void) {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	cin >> V >> E;
	parent.resize(V + 1, 0);
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	int s, d, w;
	for (int i = 0; i < E; i++) 	{
		cin >> s >> d >> w;
		graph.push_back({ w, s, d });
	}

	sort(graph.begin(), graph.end(), compareEdge);
	cout << kruskal();
}