#include <string>
#include <vector>

using namespace std;

int check(int n, int i, vector<vector<int>>& computers) { 
    if (!computers[i][i])
        return 0;
    
    computers[i][i] = 0;
    
    for (int j = 0; j < n; j++) {
        if (computers[i][j]) {
            check(n, j, computers);
        }
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {        
        answer += check(n, i, computers);
    }
    
    return answer;
}
