#include <stdio.h>

int main() {
    register int i;
    int N, M;
    int cur = 1;
    int map[1000];
    int dice[1000];

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++) {
        scanf("%d ", &map[i]);
    }
    for (i = 0; i < M; i++) {
        scanf("%d ", &dice[i]);
    }

    i = 0;
    do {
        if (cur >= N) {
            printf("%d\n", i);
            return 0;
        }

        cur += dice[i];
        cur += map[cur - 1];
    } while (i++ < M);

    return 0;
}
