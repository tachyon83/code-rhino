#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Edge {
	int type;
	int u;
	int v;
}Edge;

vector<Edge> edge;
int parent[1001];
int cnt;

bool cmp1(const Edge& a, const Edge& b) { // 오름차순 정렬
	return a.type > b.type;
}

bool cmp2(const Edge& a, const Edge& b) { // 내림차순 정렬
	return a.type < b.type;
}

int find(int x) { // 부모 노드 찾는다
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
} 

void Union(int a, int b) { // 노드를 같은 집합으로 합친다
	a = find(a);
	b = find(b);
	parent[b] = a;
}

bool same_parent(int a, int b) { // 부모가 같은지
	a = find(a);
	b = find(b);
	if (a != b)
		return false;

	return true;
}

int kruskal(int N, bool (*cmp)(const Edge &,const Edge &)) {
	int i,res = 0;
	// 초기화
	for (i = 0; i <= N; i++) parent[i] = i;

	// 최악의 경우엔 오르막길이 우선 최선의 경우엔 내리막길 우선으로 합치기위해
	sort(edge.begin(), edge.end(), cmp);

	for (i = 0; i < edge.size(); i++) {
		int t = edge[i].type;
		int u = edge[i].u;
		int v = edge[i].v;
		if (!same_parent(u, v)) {
			Union(u, v);
			if (t == 0) res++; // 오르막길일시 카운트 + 1
		}
	}

	return res * res;
}
int main() {
	int N, M, start = 0, i;
	scanf("%d %d", &N, &M);
	for (i = 0; i <= M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge.push_back({ c,a,b });
	}

	int ans = kruskal(N, cmp2) - kruskal(N, cmp1);
	printf("%d",ans);
	return 0;
}
