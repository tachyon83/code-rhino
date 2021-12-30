#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto p : puddles) { // 물에 잠긴 지역
        dp[p[1]][p[0]] = -1;
    }
    
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] == -1) continue; // 물에 잠긴 지역일시
            // 아닐시 이전지역까지의 경로 개수 더함
            if(dp[i-1][j] > 0) dp[i][j] += dp[i-1][j] % MOD; 
            if(dp[i][j-1] > 0) dp[i][j] += dp[i][j-1] % MOD;
        }
    }
    
    answer = dp[n][m] % MOD;
    return answer;
}
