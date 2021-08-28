#include <cstdio>
#include <memory.h>

int n, m;
int map[500][500];
int cache[500][500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int dfs(int x,int y) {
	int i;
	if (x == m - 1 && y == n - 1) return 1; // 도착지점이면
	if (cache[x][y] != -1)
		return cache[x][y];

	cache[x][y] = 0;
	for (i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
			if (map[nx][ny] < map[x][y]) { // 내리막일 경우
				cache[x][y] += dfs(nx, ny);
			}
		}
	}
	return cache[x][y];
}
int main() {

	scanf("%d %d", &m, &n);
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	memset(cache, -1, sizeof(cache));

	printf("%d",dfs(0,0));
	return 0;
}
