#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int depth[100001];

int DFS(int curr){
	int i;
	visited[curr] = true;

	for (i = 0; i < v[curr].size(); i++) {
		int next = v[curr][i];
		if (!visited[next]) {
			depth[curr] = max(depth[curr], DFS(next) + 1); // 리프노드로 부터의 거리중 가장 긴 거리로 갱신
		}
	}

	return depth[curr];
}

void BFS(int start,int d) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	int i,ans = 0;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			if (!visited[next] && depth[next] >= d) { // 노드에 남은 거리가 D이상이고 방문하지 않았다면 
				q.push(next);
				visited[next] = true;
				ans++; 
			}
		}
	}

	printf("%d", ans * 2); // 돌아오는 경로를 고려해 * 2 
}

int main() {
	int n, s, d;
	scanf("%d %d %d", &n, &s, &d);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		// 그래프 생성
		v[x].push_back(y);
		v[y].push_back(x);
	}

	DFS(s); // 각 노드에서부터 리프노드까지의 최대 깊이를 구함
	BFS(s, d); // 이동 거리 구함 

	return 0;
}
