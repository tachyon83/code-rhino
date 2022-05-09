#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> tree[500001];
bool visitnode[500001];
int totalheight = 0;

void dfs(int s, int cnt) {
	if (tree[s].size() == 1 && s!=1) { 
		totalheight += cnt;
		return;
	}
	for (int i = 0; i < tree[s].size(); i++) {
		if (!visitnode[tree[s][i]]) {
			visitnode[tree[s][i]] = true;
			dfs(tree[s][i], cnt + 1);
			visitnode[tree[s][i]] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}
	visitnode[1] = true;
	dfs(1, 0);
	if (totalheight % 2 == 1) 
  {
    cout << "Yes" << "\n";
  }
   
	else { 
    cout << "No" << "\n"; 
  }
	
	return 0;
}
