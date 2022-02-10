#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 유니온 파인드
int findParent(int x, vector<int> parents) { // 부모노드를 찾는다
    if(x == parents[x]) return x;
    else return parents[x] = findParent(parents[x],parents);
}

bool Union(int a, int b, vector<int> &parents) {
    a = findParent(a,parents);
    b = findParent(b,parents);
    if(a == b) return false; 
    parents[a] = b; // 부모 노드가 같지 않다면 연결
    return true;
}

bool compare(vector<int> a, vector<int> b) { // 비용 오름차순으로 정렬
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parents(n + 1);
    for(int i = 1; i <= n; i++) parents[i] = i; // 부모 노드를 가르킴
    sort(costs.begin(),costs.end(),compare);
    
    for(auto cost : costs){ 
        if(Union(cost[0],cost[1],parents)) answer += cost[2]; // 연결되지 않은 섬이면 cost 추가
    }
    
    return answer;
}
