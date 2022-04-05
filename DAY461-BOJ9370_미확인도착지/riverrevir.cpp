#include <bits/stdc++.h>
using namespace std;
int n, m, t; //교차로, 도로, 목적지 후보의 개수
int s, g, h;
int dist[2001];
vector<pair<int, int>> doro[2001];
const int INF = 987654321;
int arr[101];
int dist_copy[2001];
void dijakstra(int start) {
    for (int i = 0; i < 2001; i++) {
        dist[i] = INF;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    dist[start] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (int i = 0; i < doro[cur].size(); i++) {
            int next = doro[cur][i].first;
            int nCost = doro[cur][i].second;
            if (dist[next] > nCost + cost) {
                dist[next] = nCost + cost;
                pq.push({ -dist[next],next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        vector<int> ans;
        int plusdoro=0;
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            if ((a == g && b == h) || (a == h && b == g)) plusdoro = d;
            doro[a].push_back({ b,d });
            doro[b].push_back({ a,d });
        }
        for (int i = 0; i < t; i++) cin >> arr[i];
        int stog, stoh;
        int ret = INF;
        dijakstra(s);
        memcpy(dist_copy, dist, sizeof(dist));
        stog = dist[g];
        stoh = dist[h];
        for (int i = 0; i < t; i++) {
            int htot, gtot, temp;
            if (stog < stoh) {
                dijakstra(h);
                if (dist[arr[i]] == INF) continue;
                temp = stog + plusdoro + dist[arr[i]];
            }
            else {
                dijakstra(g);
                if (dist[arr[i]] == INF) continue;
                temp = stoh + plusdoro + dist[arr[i]];
            }
            if (dist_copy[arr[i]] == temp) {
                ans.push_back(arr[i]);
            }
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < 2001; i++) {
            doro[i].clear();
        }
    }

}
