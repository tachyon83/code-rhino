#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

class Tree
{
public:
    int N;
    vector<int> parent;
    vector<vector<int>> children;
    vector<vector<int>> adj;

    Tree() : N(0) {}
    Tree(int n) : N(n)
    {
        parent.resize(N, -1);
        children.resize(N);
        adj.resize(N);
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void print()
    {
        for (int i = 1; i < N; ++i)
        {
            cout << "Node " << i << ": parent(";
            if (parent[i] == -1)
                cout << "-";
            else
                cout << parent[i];
            cout << "), children(";
            for (auto i : children[i])
            {
                cout << i << " ";
            }
            cout << ")" << endl;
        }
    }
    int getHeight(int root)
    {
        int height = 0;
        for (int child : children[root])
            height = max(height, getHeight(child) + 1);
        return height;
    }
    void sortAdj()
    {
        for (auto &v : adj)
            sort(v.begin(), v.end());
    }
    Tree makeTree(int root)
    {
        Tree T(N);
        vector<bool> visited(N, false);
        queue<int> Q;

        visited[root] = true;
        Q.push(root);
        while (!Q.empty())
        {
            int &curr = Q.front();
            Q.pop();
            for (int &next : adj[curr])
            {
                if (visited[next] != true)
                {
                    visited[next] = true;
                    Q.push(next);
                    T.parent[next] = curr;
                    T.children[curr].push_back(next);
                }
            }
        }
        return T;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b,m;
    cin >> n;
    m=n;
    Tree T(n+1);
    n--;
    while (n--)
    {
        cin >> a >> b;
        T.addEdge(a, b);
    }
    Tree nT = T.makeTree(1);
    for(int i=2;i<m+1;++i){
        cout<<nT.parent[i]<<endl;
    }
    return 0;
}
