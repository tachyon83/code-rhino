#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[9][9];

int check_row(int x) {
    int i, check[10];
    memset(check, 0, 10 * sizeof(int));

    for (i = 0; i < 9; i++) {
        if (map[x][i] == 0)
            continue;
        check[map[x][i]]++;
        if (check[map[x][i]] > 1) {    
            return 0;
        }
    }

    return 1;
}

int check_column(int y) {
    int i, check[10];
    memset(check, 0, 10 * sizeof(int));

    for (i = 0; i < 9; i++) {
        if (map[i][y] == 0)
            continue;
        check[map[i][y]]++;
        if (check[map[i][y]] > 1) {
            return 0;
        }
    }

    return 1;
}

int check_square(int x, int y) {
    int i, j, check[10];
    int firstx = (x / 3) * 3;
    int firsty = (y / 3) * 3;
    memset(check, 0, 10 * sizeof(int));

    for (i = firstx; i < firstx + 3; i++) {
        for (j = firsty; j < firsty + 3; j++) {
            if (map[i][j] == 0)
                continue;
            check[map[i][j]]++;
            if (check[map[i][j]] > 1) {
                return 0;
            }
        }
    } 

    return 1;
}

void print_map() {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void solve(int x, int y) {
    int i, j, k;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (map[i][j])
                continue;

            for (k = 1; k <= 9; k++) {
                map[i][j] = k;

                if (check_row(i) && check_column(j) && check_square(i, j)) {
                    if (i == 8 && j == 8) {
                        print_map();
                        exit(0);
                    }
                    solve(i, j);
                }

                map[i][j] = 0;
            }
            return;
        }
    }

    print_map();
}

int main() {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d ", &map[i][j]);
        }
    }   

    solve(0, 0);

    return 0;
}
