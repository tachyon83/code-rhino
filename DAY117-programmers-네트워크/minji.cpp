#include <string>
#include <vector>

using namespace std;

bool check[201];

void dfs(int cur, int cnt, int n, vector<vector<int>> computers){
    check[cur] = true;
    for (int next = 0; next < n; next++){
        if (!check[next] && computers[cur][next] == 1){
            dfs(next, cnt, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        if (check[i]) continue;
        dfs(i, ++answer, n, computers);
    }
    return answer;
}
