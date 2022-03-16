#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int type;
    int x;
    int y;
    int direction;
};

int n = 0; 
int m = 0;
int answer = 65;
int cnt = 0;
int map[10][10];

int dfs(vector <Data> cctv, int depth){

    if (depth == cnt) {
        int simul[10][10];
        for (int i = 0; i <= n + 1; i++){
            for (int j = 0; j <= m + 1; j++){
                simul[i][j] = map[i][j];
            }
        }
        for (int i = 0; i < cnt; i++){
            if (cctv[i].type == 1){
                int to[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
                int x = cctv[i].x;
                int y = cctv[i].y;
                while(true){
                    x += to[0][cctv[i].direction - 1];
                    y += to[1][cctv[i].direction - 1];
                    if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                    simul[x][y] = 7;
                }
            } else if (cctv[i].type == 2){
                int to[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
                switch(cctv[i].direction) {
                    case 1 : {
                        int x = cctv[i].x;
                        int y = cctv[i].y;
                        while(true){
                            x += to[0][0];
                            y += to[1][0];
                            if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                            simul[x][y] = 7;
                        }
                        x = cctv[i].x;
                        y = cctv[i].y;
                        while(true){
                            x += to[0][1];
                            y += to[1][1];
                            if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                            simul[x][y] = 7;
                        }
                        break;
                    }
                    case 2 : {
                        int x = cctv[i].x;
                        int y = cctv[i].y;
                        while(true){
                            x += to[0][2];
                            y += to[1][2];
                            if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                            simul[x][y] = 7;
                        }
                        x = cctv[i].x;
                        y = cctv[i].y;
                        while(true){
                            x += to[0][3];
                            y += to[1][3];
                            if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                            simul[x][y] = 7;
                        }
                        break;
                    }
                }
            } else if (cctv[i].type == 3){
                int to[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};
                int to_set[4][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
                for (int j = 0; j < 2; j++) {
                    int to_target = to_set[cctv[i].direction - 1][j];
                    int x = cctv[i].x;
                    int y = cctv[i].y;
                    while(true){
                        x += to[0][to_target];
                        y += to[1][to_target];
                        if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                        simul[x][y] = 7;
                    }
                }
            } else if (cctv[i].type == 4){
                int to[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};
                int to_set[4][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};
                for (int j = 0; j < 3; j++) {
                    int to_target = to_set[cctv[i].direction - 1][j];
                    int x = cctv[i].x;
                    int y = cctv[i].y;
                    while(true){
                        x += to[0][to_target];
                        y += to[1][to_target];
                        if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                        simul[x][y] = 7;
                    }
                }
            } else if (cctv[i].type == 5){
                int to[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
                for (int j = 0; j < 4; j++) {
                    int x = cctv[i].x;
                    int y = cctv[i].y;
                    while(true){
                        x += to[0][j];
                        y += to[1][j];
                        if (x == 0 || x == n + 1 || y == 0 || y == m + 1 || map[x][y] == 6) break;
                        simul[x][y] = 7;
                    }
                }
            }
        }

        int temp = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (simul[i][j] == 0) temp++;
            }
        }
        if (temp < answer) answer = temp;
        return 0;
    }

        switch(cctv[depth].type){
            case 1 :
                for (int j = 1; j <= 4; j++){
                    cctv[depth].direction = j;
                    dfs(cctv, depth + 1);
                }
                break;
            case 2 :
                for (int j = 1; j <= 2; j++){
                    cctv[depth].direction = j;
                    dfs(cctv, depth + 1);
                }
                break;
            case 3 :
                for (int j = 1; j <= 4; j++){
                    cctv[depth].direction = j;
                    dfs(cctv, depth + 1);
                }
                break;
            case 4 :
                for (int j = 1; j <= 4; j++){
                    cctv[depth].direction = j;
                    dfs(cctv, depth + 1);
                }
                break;
            case 5 :
                cctv[depth].direction = 1;
                dfs(cctv, depth + 1);
                break;
        }
    
    return 0;
}

int main(){
    cin >> n >> m;

    vector <Data> cctv;

    for (int i = 0; i <= n + 1; i++){
        map[i][0] = 0;
        map[i][m + 1] = 0;
    }
    for (int i = 0; i <= m + 1; i++){
        map[0][i] = 0;
        map[n + 1][i] = 0;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i + 1][j + 1];
            if (map[i + 1][j + 1] >= 1 && map[i + 1][j + 1] <= 5) {
                cctv.push_back({map[i + 1][j + 1], i + 1, j + 1, 0});
                cnt ++;
            }
        }
    }
    dfs(cctv, 0);
    cout << answer << endl;
}