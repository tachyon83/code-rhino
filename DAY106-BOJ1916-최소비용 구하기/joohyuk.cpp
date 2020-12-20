#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#define endl '\n'
typedef long long ll;
using namespace std;
const int nMAX = 1000 + 1;
const int BIG = 100000 + 1;
vector<vector<int>> graph(nMAX, vector<int>(nMAX, BIG));
queue<int> q;
int n, m, s, e, w, temp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> pos(n + 1, BIG * nMAX);
    while (m--)
    {
        cin >> s >> e >> w;
        if (w < graph[s][e])
            graph[s][e] = w;
    }
    cin >> s >> e;
    q.emplace(s);
    pos[s] = 0;
    while (q.size())
    {
        s = q.front();
        q.pop();
        for (int j = 1; j < n + 1; j++)
        {
            temp = graph[s][j];
            if (temp < BIG)
                temp += pos[s];
            else
                continue;
            if (temp < pos[j])
            {
                pos[j] = temp;
                q.emplace(j);
                continue;
            }
        }
    }
    cout << pos[e] << endl;
    return 0;
}
