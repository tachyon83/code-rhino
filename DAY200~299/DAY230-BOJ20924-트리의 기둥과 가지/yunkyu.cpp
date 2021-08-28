#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 200000
using namespace std;

vector<pair<int,int>> tree[MAX + 1];
int dp[MAX + 1];
bool visited[MAX + 1];
int pole = -1;
int maxLength = 0;
bool flag = false;

void DFS(int curr, int N, int R ) {
	visited[curr] = true;
	int i;
	if (dp[curr] > maxLength) maxLength = dp[curr]; // 루트에서부터 가장 긴 길이 구함
	if (!flag) { // 기둥길이가 정해졌는지 체크
		pole = dp[curr];
		if (curr == R) { // 루트일 경우 child가 2개 이상일 경우 기가노드
			if (tree[curr].size() > 1) flag = true;
		}
		else { // 루트가 아닐 경우 이전의 노드를 빼주어야함
			if (tree[curr].size() - 1 > 1) flag = true;
		}
	}

	for (i = 0; i < tree[curr].size(); i++) {
		int child = tree[curr][i].first;
		int length = tree[curr][i].second;
		if (!visited[child]) {
			dp[child] = dp[curr] + length; // 다음 노드까지의 길이는 현재노드까지의 길이 + 현재노드에서 다음노드의 길이
			DFS(child, N, R);
		}
	}
}
int main() {
	int N, R, i;
	scanf("%d %d", &N, &R);
	if (N == 1) { // 노드가 한개일경우 기둥길이와 가지길이 전부 0
		printf("0 0");
		return 0;
	}
	for (i = 0; i < N - 1; i++) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		tree[a].push_back({ b,d });
		tree[b].push_back({ a,d });
	}

	DFS(R, N, R);
	printf("%d %d", pole, maxLength - pole); // 기둥길이와 가장 긴 가지길이 = (루트에서부터 가장 먼 가지의 길이 - 기둥길이)
	return 0;
}
