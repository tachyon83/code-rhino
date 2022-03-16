//prim으로 하면 유니온 처리가 어려워져서 kruskal로 하는걸 추천합니다
//출력은 double로하면 안되요. long double로 해야 맞아요 (이때, .2llf 로 출력해야함)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct edge {
	int from;
	int to;
	long double val;
}edge;
typedef struct spaceGod {
	int row;
	int col;
}spaceGod;

int comp(const edge a, const edge b);
bool iscycle(edge eg);
int find(int k);
int par[1001];

int main(){
	int N, M;
	cin >> N >> M;
	vector<spaceGod> Gods(N + 1);
	for (int i = 1; i <= N; i++) {
		int col, row;
		cin >> col >> row;
		Gods[i] = { row,col };
	}
	vector<edge> edges;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			long double val = sqrt(pow(Gods[i].row - Gods[j].row, 2) + pow(Gods[i].col - Gods[j].col, 2));
			edges.push_back({i,j,val });
		}
	}
	for (int i = 1; i <= N; i++) par[i] = i;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		if(iscycle({ from,to,0.0 })) continue;
	}

	long double sum = 0;

	sort(edges.begin(), edges.end(), comp);

	for (int i = 0; i < edges.size(); i++) {
		if (!iscycle(edges[i]) ) sum += edges[i].val;
	}

	printf("%.2llf", sum);
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
