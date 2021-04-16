#include <stdio.h>
#include <string.h>
 
#define mN 0
#define mS 1
 
int magnet[4][8];
int p_mag[4];
 
int get_l(int i) {
    return magnet[i][(p_mag[i] + 6) % 8];
}
 
int get_r(int i) {
    return magnet[i][(p_mag[i] + 2) % 8];
}
 
void roll(int i, int dir) {
    int temp;
 
    if (dir == 1)
        temp = 7;
    if (dir == -1)
        temp = 1;
 
    p_mag[i] = (p_mag[i] + temp) % 8;
}
 
void spin(int mag_n, int mag_dir) {
    int need[4];
 
    memset(need, 0, sizeof(int) * 4);
     
    if (mag_n == 0) {
        need[0] = 1;
 
        if (get_r(0) != get_l(1)) {
            need[1] = 1;
 
            if (get_r(1) != get_l(2)) {
                need[2] = 1;
 
                if (get_r(2) != get_l(3))
                    need[3] = 1;
            }
        }
 
        roll(0, mag_dir);
 
        if (need[1])
            roll(1, mag_dir * -1);
        if (need[2])
            roll(2, mag_dir);
        if (need[3])
            roll(3, mag_dir * -1);
    }
    else if (mag_n == 1) {
        need[1] = 1;
 
        if (get_r(0) != get_l(1))
            need[0] = 1;
 
        if (get_r(1) != get_l(2)) {
            need[2] = 1;
 
            if (get_r(2) != get_l(3))
                need[3] = 1;
        }
 
        roll(1, mag_dir);
 
        if(need[0])
            roll(0, mag_dir * -1);
        if (need[2])
            roll(2, mag_dir * -1);
        if (need[3])
            roll(3, mag_dir);
 
    }
    else if (mag_n == 2) {
        need[2] = 1;
 
        if (get_r(2) != get_l(3))
            need[3] = 1;
 
        if (get_r(1) != get_l(2)) {
            need[1] = 1;
 
            if (get_r(0) != get_l(1))
                need[0] = 1;
        }
 
        roll(2, mag_dir);
        if (need[3])
            roll(3, mag_dir * -1);
        if (need[1])
            roll(1, mag_dir * -1);
        if (need[0])
            roll(0, mag_dir);
    }
    else if (mag_n == 3) {
        need[3] = 1;
 
        if (get_r(2) != get_l(3)) {
            need[2] = 1;
 
            if (get_r(1) != get_l(2)) {
                need[1] = 1;
 
                if (get_r(0) != get_l(1))
                    need[0] = 1;
            }
        }
 
        roll(3, mag_dir);
 
        if (need[2])
            roll(2, mag_dir * -1);
        if (need[1])
            roll(1, mag_dir);
        if (need[0])
            roll(0, mag_dir * -1);
    }
}
 
int main() {
    register int i, j;
    int N;

    char temp;
    int ans = 0;
    int mag_n, mag_dir;
 
    int a, b;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            scanf("%c ", &temp);
            magnet[i][j] = temp - '0';
        }
    }
    
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &mag_n, &mag_dir);
 
        spin(mag_n - 1, mag_dir);
    }
 
    for (i = 0; i < 4; i++) {
        if (magnet[i][p_mag[i]] == mS) {
            if (i == 0)
                ans += 1;
            else if (i == 1)
                ans += 2;
            else if (i == 2)
                ans += 4;
            else if (i == 3)
                ans += 8;
        }
    }
 
    printf("%d\n", ans);
 
    return 0;
}
