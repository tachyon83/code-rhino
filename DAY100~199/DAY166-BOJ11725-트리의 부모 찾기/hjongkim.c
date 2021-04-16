#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int node_parent[MAX];
char visited[MAX];

struct node {
    int n;
    struct node *next;
};

struct node *graph[MAX];

void add(struct node *target, int n) {
    struct node *temp;

    temp = (struct node*) malloc(sizeof (struct node));

    temp->n = n;
    temp->next = 0;

    while (target->next != 0) {
        target = target->next;
    }

    target->next = temp;
}

int search(int i, int j) {
    struct node *temp = &graph[i];

    while (temp->next != 0) {
        temp = temp->next;

        if (temp->n == j)
            return 1;
    }

    return 0;
}

void graph_free(int size) {
    int i;
    struct node *delete, *temp;

    delete = 0;

    for (i = 1; i <= size; i++) {
        temp = &graph[i];

        while (temp->next != 0) {
            temp = temp->next;
            if (delete)
                free(delete);
            delete = temp;
        }
    }
}

int head, tail;
int q[MAX];

void push(int n) {
    q[tail++] = n;
}

int pop() {
    return q[head++];
}

int empty() {
    if (tail > head)
        return 0;
    return 1;
}

void bfs(int size) {
    int i, temp;

    while(!empty()) {
        temp = pop();

        for (i = 1; i <= size; i++) {
            if (visited[i])
                continue;

            if (search(temp, i)) {
                node_parent[i] = temp;
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, N, x, y;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        add(&graph[x], y);
        add(&graph[y], x);
    }

    push(1);
    visited[1] = 1;
    bfs(N);

    for (i = 2; i <= N; i++) {
        printf("%d\n", node_parent[i]);
    }

    //graph_free(N);
    
    return 0;
}
