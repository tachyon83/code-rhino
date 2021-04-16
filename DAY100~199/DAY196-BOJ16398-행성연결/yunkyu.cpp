//행성 연결
//https://www.acmicpc.net/problem/16398

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pipii;
int cost[1000][1000];
int parent[1000];
vector<pipii> v;

int find(int x) { // 부모 노드를 찾는다
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

bool sameParent(int a, int b) { // 같은 부모 노드를 가지고 있는지 확인
	a = find(a);
	b = find(b);
	if (a == b) return true;
	return false;
}

void Union(int a, int b) { // 두 노드를 같은 집합으로 합쳐준다
	a = find(a);
	b = find(b);
	
	if (a != b)
		parent[b] = a;
}
int main() {
	int N, i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (i = 0; i < N; i++) parent[i] = i; // i노드의 부모노드를 가리킴

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			v.push_back({ cost[i][j], { i,j} }); // 하나의 경로만 저장
		}
	}

	sort(v.begin(), v.end()); // 작은 유지 비용순으로 정렬

	long long ans = 0;
	for (i = 0; i < v.size(); i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		int c = v[i].first;
		if (!sameParent(a, b)) { // 작은 경로부터 연결
			Union(a, b);
			ans += c;
		}
	}

	printf("%lld", ans); 
	return 0;
}
