#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace  std;

typedef pair<int, pair<int, int>> pipii;
int parent[1001];
char gender[1001];
bool check[1001];

int find(int x) { // 부모 노드를 찾는다
	if (x == parent[x])
		return x;
	else 
		return parent[x] = find(parent[x]);
}

void Union(int a, int b) { // 두 노드를 같은 부모로 연결한다
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}

bool same_parent(int a, int b) { // 두 노드가 같은 집합인지 확인
	a = find(a);
	b = find(b);
	if (a == b) return true;

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq; // 거리가 짧은순으로 정렬

	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 1; i <= N; i++) {
		cin >> gender[i];
	}

	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		if(gender[u] != gender[v]) // 서로 다른 성별의 대학교의 Edge만 연결
			pq.push({ d,{u,v} });
	}

	int sum = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();

		if (!same_parent(u, v)) {
			sum += dist;
			Union(u, v);
			// 연결된 대학교를 체크
			check[u] = true; 
			check[v] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) { // 대학교 중 연결되지 않은 경우가 있을경우에 -1 출력
			cout << -1;
			return 0;
		}
	}
	cout << sum;

	return 0;
}
