#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Edge {
	int u;
	int v;
	int cost;
}Edge;
int N, M;
vector<Edge> graph;
int parent[100001];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

bool Union(int a,int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	parent[b] = a;
	return true;
}
bool cmp(const Edge& a, const Edge& b) {
	return a.cost < b.cost;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph.push_back({ a,b,c });
	}
	sort(graph.begin(), graph.end(), cmp); // 오름차순 정렬

	int maxEdge = 0;
	int sum = 0;
	for (int i = 0; i < graph.size(); i++) {
		int cost = graph[i].cost;
		int u = graph[i].u;
		int v = graph[i].v;
		if (Union(u, v)) { 
			sum += cost; 
			maxEdge = max(maxEdge, cost); 
		}
	}

	printf("%d", sum - maxEdge);
	return 0;
}
