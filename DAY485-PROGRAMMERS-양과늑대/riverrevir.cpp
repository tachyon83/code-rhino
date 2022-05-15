#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int sheep;  
    int wolf;  
    int route; 

    Node(int _sheep, int _wolf, int _route) : sheep(_sheep), wolf(_wolf), route(_route) {}
};

bool visit[132000];

int solution(vector<int> info, vector<vector<int>> edges) {
    int S = info.size();
    vector<vector<int>> g(S);
    for(auto edge: edges) {
        g[edge[0]].push_back(edge[1]);
    }

    queue<Node*> q;
    
    q.push(new Node(1, 0, (1 << 0)));  
    visit[(1<<0)] = true;
    int answer = 1;

    while(!q.empty()) {
        Node *cur = q.front(); q.pop();

        int sheep = cur->sheep;
        int wolf = cur->wolf;
        int route = cur->route;

        for(int i=0; i<S; ++i) {
            if(route & (1 << i)) {  
                for(auto next: g[i]) { 
               	    int next_route = route | (1 << next);
                    if(info[next] == 0) {  
                        if(visit[next_route]) continue; 

                        answer = max(answer, sheep+1);
                        visit[next_route] = true;
                        q.push(new Node(sheep+1, wolf, next_route));
                    }
                    else { // 늑대
                        if(sheep > wolf+1) {
                            if(visit[next_route]) continue;

                            visit[next_route] = true;
                            q.push(new Node(sheep, wolf+1, next_route));
                        }
                    }
                }
            }
        }
    }

    return answer;
}
