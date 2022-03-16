//처음에 메모리초과 났는데 2차원벡터에서 배여롤 바꾸니 해결됏어용 ㅎㅎ

#include <iostream>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

void join(int n1, int n2);
void bfs(int num, int parent);

vector<int> tree[1000001];
int dp[1000001][2] = { 0, };
int main() {
	int N;
	cin >> N;

	//vector<vector<int>> tree(N + 1, vector<int>());
	//vector<vector<int>> dp(N + 1, vector<int>(2, -1));
	//	vector<bool> visit(N + 1, false);
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		join(n1, n2);

	}

	bfs(1, 0);
	int total = (dp[1][0] < dp[1][1] ? dp[1][0] : dp[1][1]);

	cout << total;

}

void join(int n1, int n2) {
	tree[n1].push_back(n2);
	tree[n2].push_back(n1);

}

void bfs(int num, int parent) {
	//visit[num] = true;

	if (num != 1 && (tree[num].size() == 1)) {
		dp[num][0] = 0;
		dp[num][1] = 1;
		return;
	}

	int use = 0;
	int unuse = 0;
	for (int i = 0; i < tree[num].size(); i++) {
		if (parent == tree[num][i]) {
			continue;
		}
		if (dp[tree[num][i]][0] == 0) {
			bfs(tree[num][i], num);
		}
		int childuse = dp[tree[num][i]][1];
		int childunuse = dp[tree[num][i]][0];

		unuse += childuse;
		use += (childuse > childunuse ? childunuse : childuse);


	}
	dp[num][0] = unuse;
	dp[num][1] = use + 1;

}
