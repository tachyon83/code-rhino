#include <vector>
#include <queue>
using namespace std;
int solution(int n, vector<vector<int>> edge) {
    int edgeSize = edge.size(), answer = 0;
    vector<int> visited(n + 1, -1);
    vector<vector<int>> adj(n + 1);

    int u, v;
    for (int i = 0; i < edgeSize; i++) {
        u = edge[i][0];
        v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(1, cnt));
    while (!q.empty()) {
        int u = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (visited[u] == -1) {
            visited[u] = cnt;
            cnt++;
            int size = adj[u].size();
            for (int i = 0; i < size; i++)
                q.push(make_pair(adj[u][i], cnt));
        }
    }

    int maximum = -1;
    for (int i = 1; i <= n; i++) {
        if (maximum < visited[i]) {
            maximum = visited[i];
            answer = 1;
        }
        else if (maximum == visited[i]) {
            answer++;
        }
    }

    return answer;
}