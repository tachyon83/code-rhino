#include <iostream>

#define MAX 500

using namespace std;

int N, M, answer;
int map[MAX][MAX];
int arr[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int solution(int x, int y){
    if(x == N - 1 && y == M - 1){
        return 1;
    }
    if(arr[x][y] != -1){
        return arr[x][y];
    }
    
    arr[x][y] = 0;
    
    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){
            if(map[next_x][next_y] < map[x][y]){
                arr[x][y] = arr[x][y] + solution(next_x, next_y);
            }
        }
    }
    
    return arr[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            arr[i][j] = -1;
        }
    }
    
    answer = solution(0, 0);
    cout << answer << '\n';
}
