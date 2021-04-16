#include <stdio.h>

#define INF 100000

int map[100][100];
int min_wall[100][100];
int visited[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N, M;

void solve(int x, int y, int wall) {
    int i, nx, ny;

    if (wall > min_wall[N - 1][M - 1])
        return;

    if (min_wall[x][y] <= wall)
        return;
    
    min_wall[x][y] = wall;

    if (x == (N - 1) && y == (M - 1))
        return;

    for (i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        if (visited[nx][ny])
            continue;

        visited[nx][ny] = 1;
        solve(nx, ny, wall + map[nx][ny]);
        visited[nx][ny] = 0;
    }
}

int main() {
    int i, j;

    scanf("%d %d", &N, &M);

    for (i = 0; i < M; i++) {
        for (j = 0;j < N; j++) {
            scanf("%1d", &map[i][j]);
            min_wall[i][j] = INF;
        }
    }

    visited[0][0] = 1;
    solve(0, 0, 0);

    printf("%d\n", min_wall[N - 1][M - 1]);

    return 0;
}
