#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int k, tSize, ans;
vector<int> tree;
int dfs(int cur)
{
	if (cur * 2 >= tSize)
	{
		ans += tree[cur];
		return tree[cur];
	}
	else
	{
		int left = dfs(cur * 2), right = dfs(cur * 2 + 1);
		ans += tree[cur] + abs(left - right);
		return tree[cur] + max(left, right);
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> k;

	tSize = 1 << (k + 1);
	tree.resize(tSize);
	for (int i = 2; i < tSize; i++)
		cin >> tree[i];

	dfs(1);
	cout << ans;
}