#include <stdio.h>

#define MAX 1001

int start, end;
unsigned short graph[MAX][MAX];
int visited[MAX];

struct v {
    int node, dist;
};

struct v queue[MAX];
int q_head, q_tail;

void init() {
    int i;

    for (i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    q_head = q_tail = 0;
}

void q_push(struct v a) {
    queue[q_tail++] = a;
}

struct v* q_pop() {
    return &queue[q_head++];
}

int q_empty() {
    if (q_tail > q_head)
        return 0;

    return 1;
}

int bfs(int size) {
    int i;
    struct v temp, *pv;
    temp.node = start;
    temp.dist = 0;

    init();
    q_push(temp);
    visited[start] = 1;

    while(!q_empty()) {
        pv = q_pop();
        
        if(pv->node == end) {
            return pv->dist;
        }

        for (i = 1; i <= size; i++) {
            if (visited[i] || graph[pv->node][i] == 0)
                continue;

            temp.node = i;
            temp.dist = pv->dist + graph[pv->node][i];
            q_push(temp);
            visited[i] = 1;
        }
    }


    return 0;
}

int main() {
    int N, M;
    int i, x, y, d;
    int answer;

    scanf("%d %d ", &N, &M);

    for (i = 0; i < N - 1; i++) {
        scanf("%d %d %d ", &x, &y, &d);
        graph[x][y] = graph[y][x] = d;
    }

    for (i = 0; i < M; i++) {
        scanf("%d %d ", &start, &end);
        printf("%d\n", bfs(N));
    }


    return 0;
}
