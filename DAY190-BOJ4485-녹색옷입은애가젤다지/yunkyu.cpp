#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 987654321
using namespace std;

typedef pair<int, pair<int, int>> pipii;

int cnt = 0;
int cave[125][125];
int dist[125][125];
int visited[125][125];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void dijkstra(int n) {
	int i;
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
	pq.push({ cave[0][0],{0,0} });
	visited[0][0] = true;
	dist[0][0] = cave[0][0];

	while (!pq.empty()) {
		int cost = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		if (cost > dist[y][x]) continue; // 이미 체크한 경로일경우 스킵

		for (i = 0; i < 4; i++) { // 근처 공간에 대해 방문
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nextCost = cost + cave[ny][nx];
			if (0 <= ny && ny < n && 0 <= nx && nx < n && visited[ny][nx] == false) { // 방문하지 않았고 동굴안이라면
				if (nextCost < dist[ny][nx]) { // 더 적은 비용이 드는 경로라면 갱신
					dist[ny][nx] = nextCost;
					visited[ny][nx] = true; 
					pq.push({ nextCost,{ny,nx} });
				}
			}
		}
	}

	printf("Problem %d: %d\n", ++cnt, dist[n - 1][n - 1]);
	return;
}
int main() {
	int n, i, j;

	while (1) {
		scanf("%d", &n);
		if (n == 0) // 종료
			break;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &cave[i][j]);
				dist[i][j] = INF;
			}
		}
		memset(visited, false, sizeof(visited));

		dijkstra(n);
	}
	return 0;
}
