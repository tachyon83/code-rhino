#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2000 + 1;
vector<int> rel[maxN];
bool check[maxN];
bool res = false;

void dfs(int n, int cnt) 
{
	if ( cnt == 5) 
	{
		res = true;
		return;
	}
	check[n] = true;
	for (int i = 0; i < rel[n].size(); i++)
	{
		int next = rel[n][i];
		if (!check[next])
		{
			dfs(next, cnt + 1);
		}
		if (res) return;
	}
	check[n] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, a, b;
	cin >> n >> m;
	for(int i =0; i < m; i++){
		cin >> a >> b;
		rel[a].push_back(b);
		rel[b].push_back(a);
	}

	for (int i = 0; i <n; i++){
		memset(check, false, sizeof(check));
		dfs(i, 1);
	}
	if (!res)
		cout << 0 << '\n';
}
