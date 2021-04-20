#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int cnt[100001];
int compliment[100001];

void DFS(int start, int w) {
	int i;

	cnt[start] += w; // 칭찬의 수치를 더한다

	for (i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		DFS(next, w); // 직속 후배로 
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int super;
		scanf("%d", &super);
		if (i == 1) continue;
		v[super].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int num, w;
		scanf("%d %d", &num, &w);
		compliment[num] += w; // 똑같은 직원에 대한 칭찬 수치를 누적
	}

	for (int i = 1; i <= n; i++) {
		if (compliment[i] != 0) // 칭찬 받은 직원에 대해 DFS
			DFS(i, compliment[i]);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", cnt[i]);
	}

	return 0;
}
