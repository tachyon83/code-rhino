#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int n;
int map[101][101];
bool visited[101][101];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

void mark(int y, int x, int num) { // 각 섬에 대해 다르게 번호를 매김
	queue<pair<int, int>> q;
	map[y][x] = num;
	q.push({ y,x });

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (map[ny][nx] != 0 && map[ny][nx] != num) {
					map[ny][nx] = num;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int BFS(int num) {
	queue<pair<pair<int, int>,int>> q; // 좌표, 현재까지의 다리 길이
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == num) { // 해당하는 섬이면 큐에 삽입
				q.push({ { i,j } ,0 });
				visited[i][j] = true;
			}
			
		}
	}

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < n) { // 범위 안에 있고
				if (!visited[ny][nx]) { // 방문하지 않았을때
					if (map[ny][nx] == 0) { // 바다면 다리 만듬
						visited[ny][nx] = true;
						q.push({ { ny,nx }, cnt + 1 });
					}
					else if (map[ny][nx] && map[ny][nx] != num) { // 다른 섬에 도착했다면 다리 길이 반환
						return cnt;
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int num = 2;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				mark(i, j, num);
				num++;
			}		
		}
	}

	int ans = 10001;
	for (i = 2; i < num; i++) {
		memset(visited, false, sizeof(visited));
		ans = min(ans,BFS(i)); // 모든 섬에서 BFS 수행 가장 작은 다리길이 구함
	}

	printf("%d", ans);
	return 0;
}
