#include <stdio.h>

#define MAX 1001

unsigned short graph[MAX][MAX];
int visited[MAX];

void dfs(int N, int a) {
    int i;

    visited[a] = 1;

    for (i = 1; i <= N; i++) {
        if (visited[i] || !graph[a][i])
            continue;

        dfs(N, i);
    }
}

int main() {
    int i, N, M, x, y, ans;

    scanf("%d %d ", &N, &M);

    for (i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }

    ans = 0;

    for (i = 1; i <= N; i++) {
        if (visited[i])
            continue;

        dfs(N, i);
        ans++;
    }

    printf("%d\n", ans);
    
    return 0;
}
