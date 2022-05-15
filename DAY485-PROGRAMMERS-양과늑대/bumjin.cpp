#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 1;
int s = 0;
int w = 0;

void dfs(int curr_idx, int w, int s, vector<int> nextNode, vector<int> info, vector<vector<int>> v) {
    int animal = info[curr_idx];
    if(!animal) s++;
    else w++;
    
    answer = max(answer, s);
    
    if(w >= s) return;
    
    for(int i = 0; i < nextNode.size(); i++) {
        vector<int> next = nextNode;
        next.erase(next.begin()+i);
        for(int j = 0; j < v[nextNode[i]].size(); j++) 
            next.push_back(v[nextNode[i]][j]);
        dfs(nextNode[i],w,s, next, info, v);
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
   vector<vector<int>> v(info.size());

    for(int i = 0; i < edges.size(); i++) 
        v[edges[i][0]].push_back(edges[i][1]);
    
    vector<int> nextNode; //0번 노드와 연결된 값부터 시작하기 위해서
    for(int i = 0; i < v[0].size(); i++)
        nextNode.push_back(v[0][i]);
    
    dfs(0,0,0,nextNode, info, v);
    
    
    return answer;
}
