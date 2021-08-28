#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int parent[301];
vector<pair<int, pair<int, int>>> v;

int find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	parent[b] = a;
	return true;
}

int main() {
	int n, i, j, cost;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &cost);
		v.push_back({ cost, { i,0 } }); 
		parent[i] = i;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &cost);
			if (i >= j) continue;
			v.push_back({ cost,{i,j} });
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;

	for (i = 0; i < v.size(); i++) {
		int c = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (Union(a, b)) { // 같은 집합이 아니라면 연결
			ans += c;
		}
	}

	printf("%d", ans);
	return 0;
}
