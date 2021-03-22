#include <stdio.h>

#define ABS(A,B) (((A - B) > 0) ? (A - B) : (B - A))

int N, answer;
int map[15];//1~14

int check(int x) {
    int i;

    for (i = 0; i < x; i++) {
        if (map[x] == map[i]) {//check column
            return 0;
        }
        if ((x - i) == ABS(map[x], map[i])) { // check diagonal
            return 0;
        }
    }

    return 1;
}

void solve(int x) {
    int y;
   
    if (x == N) {
        answer++;
    } else {
        for (y = 0; y < N; y++)
        {
            map[x] = y; //(x,y)
            if (check(x)) {
                solve(x + 1);
            }
        }
    }
}
int main() {
    scanf("%d ", &N);
    solve(0);

    printf("%d\n", answer);
    return 0;
}
