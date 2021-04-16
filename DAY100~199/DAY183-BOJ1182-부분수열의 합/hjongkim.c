#include <stdio.h>

int main() {
    int i, j, sum, answer = 0;
    int N, S;
    int num[20];

    scanf("%d %d ", &N, &S);
    for (i = 0; i < N; i++) {
        scanf("%d ", &num[i]);
    }

    for (i = 1; i < (1 << N); i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sum += num[j];
            }
        }
        if (sum == S) {
            answer++;
        }
    }

    printf("%d\n", answer);

    return 0;
}
