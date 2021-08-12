#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mat[1001][1001];
vector<int> v[1001];

void bfs(int x,int y) {
    bool visit[1001] = { 0 };
    queue<pair<int,int>> q;
    q.push({ x, 0 });
    visit[x] = 1;

    while (!q.empty()) {
        int t = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (t == y) {
            cout << cost << '\n';
            break;
        }

        for (unsigned int i = 0; i < v[t].size(); i++) {
            if (!visit[v[t][i]]) {
                q.push({ v[t][i], cost + mat[t][v[t][i]] });
                visit[v[t][i]] = 1;
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        mat[a][b] = c;
        mat[b][a] = c;
    }

    int x, y;
    for (int j = 0; j < M; j++) {
        cin >> x >> y;
        bfs(x, y);
    }

    return 0;
}