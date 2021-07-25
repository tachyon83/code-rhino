#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { 1,-1,0,0 };

int n, m;
int map[8][8];
int temp_map[8][8];
int mx = 0;

void cpy_map(int (*a)[8], int (*b)[8]) { // temp map 만들기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}
void BFS() {
    int virus_map[8][8];
    int i, j;

    cpy_map(virus_map, temp_map);
    
    queue<pair<int, int>> q;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (virus_map[i][j] == 2) { // 바이러스 위치 
                q.push(make_pair(i, j));
            }
        }
    }

   // 바이러스 퍼뜨린다
    while (!q.empty()) {
        
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (i = 0; i < 4; i++) {
            if (0 <= x + dirX[i] && x + dirX[i] < n && 0 <= y + dirY[i] && y + dirY[i] < m) {
                if (virus_map[x + dirX[i]][y + dirY[i]] == 0) {
                    virus_map[x + dirX[i]][y + dirY[i]] = 2;
                    q.push(make_pair(x + dirX[i], y + dirY[i]));
                }
            }
        }
    }

    int cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (virus_map[i][j] == 0) cnt++;
        }
    }

    mx = mx > cnt ? mx : cnt;
 }
void makeWall(int cnt) { // 임의로 벽 3개 생성
    if (cnt == 3) {
        BFS();
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp_map[i][j] == 0) 
            {
                temp_map[i][j] = 1;
                makeWall(cnt + 1);
                temp_map[i][j] = 0;
            }
        }
    }
    
}
int main() {

    int i, j;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                cpy_map(temp_map, map);
                temp_map[i][j] = 1;
                makeWall(1);
                temp_map[i][j] = 0;
            }
        }
    }

    printf("%d", mx);

	return 0;
}
