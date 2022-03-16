
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector <vector<int>> adj(n + 1,vector<int>(n+1,0));
    bool visit[20001] = { false,};
    vector<pair<int,int>> hubo;
    queue <pair<int,int>>q;
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]][edge[i][1]] = 1;
        adj[edge[i][1]][edge[i][0]] = 1;
    }
    q.push({ 1,0 });
    visit[1] = true;
    while (!q.empty()) {
        pair<int,int> tmp = q.front();
        q.pop();
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (visit[i]==false && adj[tmp.first][i] == 1) {
                q.push({ i,tmp.second + 1 });
                visit[i] = true;
                count++;
            }
        }
        if (count == 0) {
            hubo.push_back(tmp);
        }
    }
    int max = hubo.back().second;
    for (int i = 0; i < hubo.size(); i++) {
        if (hubo[i].second == max) {
            answer++;
        }
    }
    return answer;
}
