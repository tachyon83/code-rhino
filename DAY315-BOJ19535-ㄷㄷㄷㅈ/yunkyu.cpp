#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[300001];
bool visited[300001];
long long sz[300001];
long long d = 0, g = 0;

void cnt(int n) {
	visited[n] = true; // 방문

	if (sz[n] >= 3) { // 노드가 n개(3개 이상) 연결돼있다면 G tree를 nC3개 만들수있다 
		g += (sz[n] * (sz[n] - 1) * (sz[n] - 2)) / 6;
	}

	for (auto node : graph[n]) { 
		if (!visited[node]) { // 방문하지 않은 노드라면
			if(sz[n] > 1 && sz[node] > 1) // 두 노드가 각각을 제외하고 다른 노드들(n개,m개)과 연결돼있다면
				d += (sz[n] - 1) * (sz[node] - 1); // n * m만큼 D tree를 만들수 있다 (-1은 서로를 제외)
			cnt(node);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 각 노드에서 연결되어 있는 노드들의 개수를 구함
	for (int i = 1; i <= n; i++)
		sz[i] = graph[i].size();

	cnt(1);

	if (d > 3 * g) // D - tree
		printf("D");
	else if (d < 3 * g) // G - tree
		printf("G");
	else // DUDUDUNGA tree
		printf("DUDUDUNGA");
	
	return 0;
}
