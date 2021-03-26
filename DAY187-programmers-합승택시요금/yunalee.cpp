#include <string>
#include <vector>
#include <algorithm>

#define INF 987987987

using namespace std;

// 모든정점에서 모든정점으로 가는 최소비용
void floydWarshall(int n, vector<vector<int>> &dist_arr){
    
    // k:중간노드 i:출발노드 j:도착노드
    for(int k = 0; k <= n; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                /* i(출발) -> k(중간) -> j(도착) 거치는 비용과 *
                 * i(출발) -> j(도착) 거치는 비용의 크기 비교   */
                if(dist_arr[i][k] + dist_arr[k][j] < dist_arr[i][j]){
                    dist_arr[i][j] = dist_arr[i][k] + dist_arr[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>> dist_arr(n + 1, vector<int>(n + 1, INF));
    
    for(int i = 0; i < fares.size(); i++){
        dist_arr[fares[i][0]][fares[i][1]] = fares[i][2]; // a->b로 가는 비용
        dist_arr[fares[i][1]][fares[i][0]] = fares[i][2]; // b->a로 가는 비용
    }
    for(int i = 1; i <= n; i++){
        dist_arr[i][i] = 0; // a->a 로 가는 비용은 0
    }
    
    floydWarshall(n, dist_arr);
    
    answer = dist_arr[s][a] + dist_arr[s][b];   //시작점에서 각자 도착장소를 갈때의 비용
    
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        //시작점에서 i지점까지 합승 후 각자 도착장소를 갈때의 비용과 비교
        if(dist_arr[s][i] != INF){
            answer = min(answer, dist_arr[s][i] + dist_arr[i][a] + dist_arr[i][b]);
        }
    }
    
    return answer;
}
