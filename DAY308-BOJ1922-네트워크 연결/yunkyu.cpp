#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,pair<int, int>>> v;
int parent[1001];

int find(int x) { // x 의 부모를 찾는다
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) // 부모가 같다면 합치지 않음
		return false;
		
	parent[a] = b; //  같은 부모로

	return true;
}

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int i;
	for (i = 1; i <= n; i++)  // 부모를 자신으로 초기화
		parent[i] = i;

	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ c,{a,b} });
	}

	sort(v.begin(), v.end()); // cost 오름차순으로 정렬

	int ans = 0;
	for (i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		
		if (Union(a, b)) // a, b 를 같은 집합으로 합쳤다면 cost 더해줌
			ans += cost;
	}

	printf("%d", ans);

	return 0;
}
