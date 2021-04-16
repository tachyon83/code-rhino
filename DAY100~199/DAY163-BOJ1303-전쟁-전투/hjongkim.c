#include <stdio.h>

int N, M;
int W_power, B_power;
int map[100][100];
int visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int dfs(int x, int y, int team) {
    int k;
    int nx, ny;
    int count = 1;

    visited[x][y] = 1;

    for (k = 0; k < 4; k++) {
        nx = x + dx[k];
        ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (map[nx][ny] != team || visited[nx][ny])
            continue;
        
        count += dfs(nx, ny, team);
    }

    return count;
}

int main() {
    int i, j, count;
    char temp;

    scanf("%d %d ", &M, &N);

    W_power = B_power = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%c ", &temp);
            if (temp == 'W')
                map[i][j] = 0;
            else // B
                map[i][j] = 1;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (visited[i][j])
                continue;

            count = dfs(i, j, map[i][j]);
            if (map[i][j])
                B_power += (count * count);
            else
                W_power += (count * count);
        }
    }

    printf("%d %d\n", W_power, B_power);

    return 0;
}
