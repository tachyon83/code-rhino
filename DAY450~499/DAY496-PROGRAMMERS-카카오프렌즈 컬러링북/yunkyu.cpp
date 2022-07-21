#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
bool visited[101][101];

int BFS(int y, int x, int color, vector<vector<int>>& picture, int m, int n) {
    visited[y][x] = true;
    queue<pair<int,int>> q;
    q.push({y, x});
    
    int cnt = 0;
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        cnt++;
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue; // 범위를 넘어가면 스킵
            if(!visited[ny][nx] && picture[ny][nx] == color) { // 방문하지 않았고 색깔이 동일할 때
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    memset(visited,false,sizeof(visited));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && picture[i][j]){ // 방문하지 않았고 색칠된 영역일 때
                number_of_area++; // 영역의 수 + 1
                max_size_of_one_area = max(max_size_of_one_area, BFS(i, j, picture[i][j], picture, m, n)); // 가장 큰 영역의 넓이로 갱신
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
