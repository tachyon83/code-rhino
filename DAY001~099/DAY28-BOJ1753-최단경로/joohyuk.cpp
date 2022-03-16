#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
const int nMax = 20000 + 1;
const int Big = 300000 * 10 + 1;
vector<vector<pair<int, int>>> g(nMax);
int values[nMax];
int n, e, s, u, v, w, qs;
struct cmp
{
    int operator()(const int &a, const int &b)
    {
        return values[a] > values[b];
    }
};
priority_queue<int, vector<int>, cmp> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(values, values + nMax, Big);
    cin >> n >> e >> s;
    values[s] = 0;
    pq.emplace(s);
    while (e--)
    {
        cin >> u >> v >> w;
        g[u].emplace_back(make_pair(v, w));
    }
    while (pq.size())
    {
        qs = pq.size();
        for (int i = 0; i < qs; ++i)
        {
            u = pq.top();
            pq.pop();
            for (auto vec : g[u])
            {
                v = vec.first;
                w = values[u] + vec.second;
                if (w < values[v])
                {
                    values[v] = w;
                    pq.emplace(v);
                }
            }
        }
    }
    for (int i = 1; i < n + 1; ++i)
    {
        if (values[i] >= Big)
            cout << "INF" << endl;
        else
            cout << values[i] << endl;
    }
    return 0;
}
