#include <stdio.h>

#define INF 10000000
#define MAX(A,B) (A > B ? A : B)

int N;
int map[1001][1001];
int visit[1001];
int dis[1001];
int goback[1001];

int get_close_index() {
    int min = INF;
    int i, ret;
    for (i = 1; i <= N; i++) {
        if(dis[i] < min && !visit[i]) {
            min = dis[i];
            ret = i;
        }
    }

    return ret;
}

void dijkstra(int start) {
    int i, j, temp;
    for (i = 1; i <= N; i++) {
        visit[i] = 0;
        dis[i] = map[start][i];
    }

    visit[start] = 1;

    for (i = 1; i <= N; i++) {
        temp = get_close_index();
        visit[temp] = 1;
        for (j = 1; j <= N; j++) {
            if (visit[j])
                continue;

            if(dis[temp] + map[temp][j] < dis[j]) {
                dis[j] = dis[temp] + map[temp][j];
            }
        }

    }
}

int main() {
    int i, j;
    int x, y, d;
    int M, X;
    int answer = 0;

    scanf("%d %d %d ", &N, &M, &X);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            map[i][j] = INF;

            if (i == j)
                map[i][j] = 0;
        }
    }

    for (i = 0; i < M; i++) {
        scanf("%d %d %d ", &x, &y, &d);
        map[x][y] = d;
    }

    dijkstra(X);

    for (i = 1; i <= N; i++) {
        goback[i] = dis[i];
    }

    for (i = 1; i <= N; i++) {
        dijkstra(i);
        answer = MAX(answer, dis[X] + goback[i]);
    }

    printf("%d\n", answer);

    return 0;
}
