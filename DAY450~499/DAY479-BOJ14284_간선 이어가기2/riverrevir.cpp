#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
int dist[5001];
vector<pair<int, int>> v[5001];
const int INF = 987654321;
void bfs(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    dist[start] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int nCost = v[cur][i].second;
            int next = v[cur][i].first;
            if (dist[next] > nCost + cost) {
                dist[next] = nCost + cost;
                pq.push({ -dist[next],next });
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    cin >> s >> t;
    bfs(s);
    cout << dist[t];
}
