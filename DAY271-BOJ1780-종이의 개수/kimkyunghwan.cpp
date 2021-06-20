#include <iostream>
using namespace std;
 
int ans[3];  // -1 0 1
int mat[2500][2500];
void cut_paper(int y, int x, int k) {
    if (k == 0) {
        ans[mat[y][x] + 1] += 1;
        return;
    }
    int check = 1;
    int squad = 1;
    for (int i = 0; i < k - 1; i++) { //n/3 구하기
        squad *= 3;
    }
    int t = 3 * squad;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (mat[y][x] != mat[y+i][x+j]) check = 0;
        }
    }
    if (check == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cut_paper(y + i * squad, x + j * squad, k - 1);
            }
        }
    }
    else {
        ans[mat[y][x] + 1] += 1;
    }
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int k = 0; //n이 3의 몇 제곱인지?
    int temp_n = n;
    while (temp_n != 1) {
        temp_n /= 3;
        k++;
    }
    cut_paper(0, 0, k);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
