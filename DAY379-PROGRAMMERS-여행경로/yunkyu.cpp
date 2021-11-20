#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[10001];

bool DFS(string current, int cnt, vector<vector<string>> tickets, vector<string> &answer){
    if(cnt == tickets.size()) return true; // 모든 항공권을 다 사용 했을시
    
    for(int i = 0; i < tickets.size(); i++ ){
        if(visited[i] == 0 && tickets[i][0] == current) { // 사용하지 않았고 현재 공항에서 사용할수 있는 항공권일시
            visited[i] = 1;
            answer.push_back(tickets[i][1]);
            if(DFS(tickets[i][1], cnt + 1, tickets,answer)) return true; // 경로를 찾았을시에 바로 반환
            visited[i] = 0;
            answer.pop_back();
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(),tickets.end()); // 항공권 알파벳 오름차순으로 정렬
    answer.push_back("ICN");
    DFS("ICN",0,tickets,answer);
    
    return answer;
}
