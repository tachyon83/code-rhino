#include <stdio.h>

int N, M;

struct data {
    int x;
    int y;
};

struct data ladder[15];
struct data snake[15];

struct data queue[100];
int visited[101];

int q_head, q_tail;

void push(int location, int count) {
    struct data temp;
    temp.x = location;
    temp.y = count;
    queue[q_tail++] = temp;
}

struct data pop() {
    return queue[q_head++];
}

int empty() {
    if (q_head >= q_tail)
        return 1;
    return 0;
}

void jump(int location, int count) {
    int i;

    visited[location] = 1;

    for (i = 0; i < N; i++) {
        if (ladder[i].x == location) {
            if (visited[ladder[i].y])
                continue;

            visited[ladder[i].y] = 1;
            push(ladder[i].y, count + 1);
            return;
        }
    }

    for (i = 0; i < M; i++) {
        if (snake[i].x == location) {
            if (visited[snake[i].y])
                continue;

            visited[snake[i].y] = 1;
            push(snake[i].y, count + 1);
            return;
        }
    }

    push(location, count + 1);
}

int bfs() {
    int i, j;
    struct data temp;
    push(1, 0);
    visited[1] = 1;

    while(!empty()) {
        temp = pop();

        for (i = 1; i <= 6; i++) {
            if (temp.x + i == 100) {
                return temp.y + 1;
            }

            if (temp.x + i > 100)
                continue;

            if (visited[temp.x + i])
                continue;

            jump(temp.x + i, temp.y);
        }

    }

}

int main() {
    int i;
    struct data t;

    freopen("day170.txt", "r", stdin);

    scanf("%d %d ", &N, &M);

    for (i = 0; i < N; i++) {
        scanf("%d %d ", &t.x, &t.y);
        ladder[i] = t;
    }

    for (i = 0; i < M; i++) {
        scanf("%d %d ", &t.x, &t.y);
        snake[i] = t;
    }

    printf("%d\n", bfs());
    
    return 0;
}
