#include <iostream>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

void join(int n1, int n2, vector<vector<int>> &tree);
void bfs(int num, vector<vector<int>> tree, vector<vector<int>> &dp, vector<bool> &visit);

int main() {
	int N;
	cin >> N;
	vector<vector<int>> tree(N + 1, vector<int>());
	vector<vector<int>> dp(N + 1, vector<int>(2, -1));
	vector<bool> visit(N + 1, false);
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		join(n1, n2, tree);

	}
	int total = 0;
	for (int i = 1; i < visit.size();i++) {
		if (visit[i] == false) {
			bfs(i, tree, dp, visit);
			total += (dp[1][0] < dp[1][1] ? dp[1][0] : dp[1][1]);
		}
	}
	cout << total;

}

void join(int n1, int n2, vector<vector<int>> &tree) {
	tree[n1].push_back(n2);
	tree[n2].push_back(n1);

}

void bfs(int num, vector<vector<int>> tree, vector<vector<int>> &dp, vector<bool> &visit) {
	visit[num] = true;
	if (tree[num].size() == 1) {
		dp[num][0] = 0;
		dp[num][1] = 1;
		return;
	}
	int use = 0;
	int unuse = 0;
	for (int i = 0; i < tree[num].size(); i++) {
		if (visit[tree[num][i]] == true) {
			continue;
		}
		if (dp[tree[num][i]][0] == -1) {
			bfs(tree[num][i], tree, dp, visit);
		}
		int childuse = dp[tree[num][i]][1];
		int childunuse = dp[tree[num][i]][0];
		unuse += dp[tree[num][i]][1];
		use += (childuse > childunuse ? childunuse : childuse);
	}
	dp[num][0] = unuse;
	dp[num][1] = use + 1;

}
