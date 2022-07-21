#include <string>
#include <vector>

using namespace std;
vector<int> answer(1,-1);
int maxDiff = 0;

bool cmp(vector<int> ryan) {
    
    for(int i = 10; i >= 0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
    }
}

void calcScore(vector<int> ryan, vector<int> apeach) {
    int ryanScore = 0;
    int apeachScore = 0;
    
    for(int i = 0; i < 11; i++) {
        if(ryan[i] > apeach[i]) ryanScore += 10 - i;
        else if(apeach[i] > 0) apeachScore += 10 - i;
    }
    
    int diff = ryanScore - apeachScore;
    if(diff > 0 && maxDiff <= diff) {
        if(maxDiff == diff && !cmp(ryan)) return;
        maxDiff = diff;
        answer = ryan;
    }
}


void solve(int idx, int arrows, vector<int> ryan, vector<int> apeach) {
    if(idx==11 || arrows == 0) { //분배 끝 
        ryan[10] += arrows;
        calcScore(ryan, apeach);
        ryan[10] -= arrows;
        return;
    }
    if(apeach[idx] < arrows) {
        ryan[idx] += apeach[idx] +1;
        solve(idx+1, arrows-apeach[idx]-1, ryan,apeach);
        ryan[idx] -= apeach[idx] +1;
    }
    solve(idx+1, arrows, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11,0);
    
    solve(0,n, ryan, info);

    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}
