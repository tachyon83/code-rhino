#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> oneDir(n+1, 0);
    vector<bool> visited(n+1, false);
    vector<int> vc[20001];
    
    for(int i = 0; i < edge.size(); i++){
        //연결된 노드 상태 저장
        vc[edge[i][0]].push_back(edge[i][1]);
        vc[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> Queue;
    Queue.push(1);  //1번 노드에서 출발
    oneDir[1] = 0;
    visited[1] = true;
    int maxCnt = 0;
    while(!Queue.empty()){
        int cur = Queue.front();    //현재 노드번호
        Queue.pop();
        int curDir = oneDir[cur];   //현재 노드에서 1까지 가는 거리
        
        if(curDir > maxCnt){    //현재노드에서 1까지 가는 거리가 최대보다 큰 경우
            maxCnt = curDir;    //최대값 갱신
            answer = 1;         //coning 1로 초기화
        }else if(curDir == maxCnt){ //현재노드에서 1까지 가는 거리가 최대와 같은 경우
            answer++;   //counting
        }
        
        for(int i = 0; i < vc[cur].size(); i++){
            //인접논드 중 방문하지 않은 노드들 처리
            if(!visited[vc[cur][i]]){  
                Queue.push(vc[cur][i]);
                oneDir[vc[cur][i]] = curDir+1;  //현재 노드에서 +1한 거리가 1까지 도달하는데 필요한 최단거리
                visited[vc[cur][i]] = true;
            }
        }
    }
    
    return answer;
}
