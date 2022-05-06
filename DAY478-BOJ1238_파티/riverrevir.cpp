#include <bits/stdc++.h>
using namespace std;
int n, m, x;
const int INF = 987654321;
vector<pair<int, int>> v[1001];
int dist[1001];
int bfs(int s,int e) {
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    pq.push({ 0,s });
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
    return dist[e];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
    int ret = -1;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        int go = bfs(i, x);
        int back = bfs(x, i);
        ret = max(ret, go + back);
    }
    cout << ret;
}
