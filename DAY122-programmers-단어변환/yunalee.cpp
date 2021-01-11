#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 987987987;
vector<bool> visited;
void dfs(string target, string begin, int changeCnt, int len, vector<string> words){
    if(target == begin){
        if(answer > changeCnt){
            answer = changeCnt;
        }
        return;
    }
    
    if(changeCnt >= len){
        return;
    }
    
    for(int i = 0; i < len; i++){
        if(!visited[i]){
            int chnCnt = 0;
            for(int j = 0; j < target.size(); j++){
                if(begin[j] != words[i][j]){
                    chnCnt++;
                }
            }
            if(chnCnt > 1){
                continue;
            }
            visited[i] = true;
            dfs(target, words[i], changeCnt+1, len, words);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<string>::iterator iter;
    iter = find(words.begin(), words.end(), target);
    if(iter == words.end()){
        return 0;
    }
    
    visited.resize(words.size(), false);
    dfs(target, begin, 0, words.size(), words);
    
    return answer;
}
