#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
int map[1001][1001];
bool visited[1001][1001][2]; // 3차원 배열로 현재까지 벽을 부순지 안부순지 구분
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int BFS(int y, int x) {
	visited[y][x][0] = true;
	int i;
	queue<pair<pair<int, int>, pair<int,bool>>> q;
	q.push({ {y,x},{1,false} });

	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		int cnt = q.front().second.first; // 현재까지 거리
		bool check = q.front().second.second; // 벽을 부순지 체크
		q.pop();

		if (y == N - 1 && x == M - 1) { // 도착했다면 종료
			return cnt;
		}
		
		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) { // 범위안에 있을때
				if (map[ny][nx] == 1 && !check) { // 벽이고 아직 부순적이 없다면
					visited[ny][nx][1] = true;
					q.push({ {ny,nx},{cnt + 1,true} });
				}
				else if (map[ny][nx] == 0 && !visited[ny][nx][check] ) { // 벽이 아니라면
					visited[ny][nx][check] = true;
					q.push({ {ny,nx},{cnt + 1,check} });
				}
			}
		}
	}

	return -1;
}

int main() {
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d",BFS(0, 0));

	return 0;
}
