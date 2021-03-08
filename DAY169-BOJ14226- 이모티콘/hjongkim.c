#include <stdio.h>

struct data {
    int screen;
    int clipboard;
    int time;
};

int visited[1000][1000];

struct data queue[1000];

int q_head, q_tail;

void push(int t, int s, int c) {
    struct data temp;
    temp.time = t;
    temp.screen = s;
    temp.clipboard = c;
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

int bfs(int input) {
    struct data temp;
    
    push(0, 1, 0);

    while (!empty()) {
        temp = pop();

        if (temp.screen == input) {
            return temp.time;
        }

        if (temp.screen <= 0 || temp.screen > 1000)
            continue;

        if (!visited[temp.screen][temp.screen]) {
            visited[temp.screen][temp.screen] = 1;
            push(temp.time + 1, temp.screen, temp.screen);
        }
        if (temp.clipboard > 0 && temp.screen + temp.clipboard <= 1000 &&
            !visited[temp.screen + temp.clipboard][temp.clipboard]) {
            visited[temp.screen + temp.clipboard][temp.clipboard] = 1;
            push(temp.time + 1, temp.screen + temp.clipboard, temp.clipboard);
        }
        if (!visited[temp.screen - 1][temp.clipboard]) {
            visited[temp.screen - 1][temp.clipboard] = 1;
            push(temp.time + 1, temp.screen - 1, temp.clipboard);
        }
    }
}

int main() {
    int input;

    scanf("%d", &input);

    printf("%d\n", bfs(input));
    
    return 0;
}
