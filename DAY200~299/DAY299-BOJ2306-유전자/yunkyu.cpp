#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

string dna;
int ans = 0;
int dp[501][501];

int dfs(int l, int r) {
	int& ret = dp[l][r];

	if (ret != -1) 
		return ret;

	ret = 0;
	if ((dna[l] == 'a' && dna[r] == 't') || (dna[l] == 'g' && dna[r] == 'c')) { // KOI 유전자 일때
		ret = dfs(l + 1, r - 1) + 2;
	}

	for (int i = l; i < r; i++) { // 부분 서열에 대해서 더한값중 가장 긴 길이 구함
		ret = max(ret, dfs(l, i) + dfs(i + 1, r));
	}

	return dp[l][r] = ret;
}

int main() {
	cin >> dna;

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, dna.length() - 1);
	return 0;
}
