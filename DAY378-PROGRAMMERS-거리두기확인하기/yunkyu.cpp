#include <string>
#include <vector>
#include <memory.h>
#include <cmath>
#include <queue>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
bool visited[5][5];

bool BFS(int y, int x, vector<string> place) {
    visited[y][x] = true;
    int i;
    queue<pair<int, pair<int, int>>> q; 
    q.push({ 0,{y,x} });

    while (!q.empty()) {
        int dist = q.front().first; // 현재까지 맨해튼 거리
        y = q.front().second.first;
        x = q.front().second.second;
        q.pop();

        if (place[y][x] == 'P' && dist != 0 && dist <= 2) return false; // 본인이 아닌 다른 응시자와의 거리가 2 이하라면

        for (i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < 5 && 0 <= nx && nx < 5 && !visited[ny][nx]) {
                if (place[ny][nx] == 'X') continue; // 파티션일시 통과하지 못함
                visited[ny][nx] = true;
                q.push({ dist + abs(ny - y) + abs(nx - x) ,{ny,nx} }); // 다음 위치까지의 맨해튼 거리를 현재까지 거리에 더한다
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        vector<string> place = places[i];
        bool flag = false;

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (place[j][k] == 'P') { // 응시자일시
                    if (!BFS(j, k, place)) { 
                        flag = true;
                        j = 5;
                        break;
                    }
                    memset(visited, false, sizeof(visited));
                }
            }
        }

        if (flag) answer.push_back(0); // 거리두기를 위반하였다면
        else answer.push_back(1);
    }

    return answer;
}
