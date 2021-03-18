#include <stdio.h>

#define INF 10000000
#define MIN(A,B) (A > B ? B : A)

int N;
int map[801][801];
int visit[801];
int dis[801];

int get_close_index() {
    int min = INF;
    int i, ret = 0;
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
    int E, v1, v2;
    int answer = INF;
    int StoV1, StoV2, V1toV2, V1toN, V2toN;

    scanf("%d %d ", &N, &E);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            map[i][j] = INF;

            if (i == j)
                map[i][j] = 0;
        }
    }

    for (i = 0; i < E; i++) {
        scanf("%d %d %d ", &x, &y, &d);
        map[x][y] = map[y][x] = d;
    }

    scanf("%d %d ", &v1, &v2);

    //required path (1->v1->v2->N or 1->v2->v1->N)
    //1->v1, 1->v2
    dijkstra(1);
    StoV1 = dis[v1];
    StoV2 = dis[v2];
    if (StoV1 == INF || StoV2 == INF) {
        goto out;
    }
    //v1<->v2, v1->N
    dijkstra(v1);
    V1toV2 = dis[v2];
    V1toN = dis[N];
    if (V1toV2 == INF || V1toN == INF) {
        goto out;
    }
    //v2->N
    dijkstra(v2);
    V2toN = dis[N];
    if (V2toN == INF) {
        goto out;
    }
    
    answer = MIN(answer, StoV1 + V1toV2 + V2toN);
    answer = MIN(answer, StoV2 + V1toV2 + V1toN);

    printf("%d\n", answer);
    return 0;

out:
    printf("-1\n");
    return 0;
}
