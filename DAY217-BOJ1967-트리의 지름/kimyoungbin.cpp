#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> tree[10001];
int n;
int dist[10001] = { 0, };
int visit[10001] = { 0, };
int ans_dist = 0;
int ans_node = 0;

void dfs(int start, int d) {
    dist[start] = d;
    visit[start] = 1;
    if (d > ans_dist) {
        ans_dist = d;
        ans_node = start;
    }
    for (auto& p : tree[start]) {
        if (visit[p.first] == 0) {
            dfs(p.first, d + p.second);
        }
    }
}

int main() {
    cin >> n;
    int p, c, w;
    for (int i = 0; i < n - 1; ++i) {
        cin >> p >> c >> w;
        tree[p].push_back(make_pair(c, w));
        tree[c].push_back(make_pair(p, w));
    }
    dfs(1, 0);

    fill_n(dist, n+1, 0);
    fill_n(visit, n+1, 0);
    dfs(ans_node, 0);
    cout << ans_dist;
    return 0;
}
