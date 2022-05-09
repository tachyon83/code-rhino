#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, u, v, cnt;
bool check[500001];
vector<int> tree[500001];
queue<int> q;

void dfs(int x, int depth)
{
	if (x != 1 && tree[x].size() == 1) // leaf node 일 때
	{
		if (depth % 2 == 1) cnt++;
		return;
	}

	for (int i = 0; i < tree[x].size(); i++)
	{
		if (check[x] == false)
		{
			check[x] = true;
			dfs(tree[x][i], depth + 1);
			check[x] = false;
		}
		
	}

}

int main() 
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	
	dfs(1, 0);

	if (cnt % 2 == 1) cout << "Yes";
	else cout << "No";

}
