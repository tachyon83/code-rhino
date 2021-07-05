#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

int map[50][50];
bool visited[50][50];
int dy[] = { 1,-1,0,0,1,-1,-1,1 };
int dx[] = { 0,0,1,-1,1,-1,1,-1 };

void BFS(int y, int x, int w ,int h) {
	queue<pair<int, int>> q;
	int i;
	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (i = 0; i < 8; i++) { // 걸어서 갈수있는 모든방향 확인
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < h && 0 <= nx && nx < w) { // 범위안에 있고
				if (!visited[ny][nx] && map[ny][nx] == 1) { // 방문하지 않은 섬이라면
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int solve(int w, int h) {
	int i, j;
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (!visited[i][j] && map[i][j] == 1) { // 방문하지 않았고 섬이라면
				BFS(i, j, w, h);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	int w, h;
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) // 종료
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		printf("%d\n",solve(w, h));
	}
	return 0;
}
