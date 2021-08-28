#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
int memory[101];
int cost[101];
int cache[101][10001];

int main() {
	scanf("%d %d", &N, &M);
	int i;
	int sum = 0;
	for (i = 1; i <= N; i++) {
		scanf("%d", &memory[i]);
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
		sum += cost[i];
	}

	memset(cache, 0, sizeof(cache));

	for (i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j >= cost[i]) { // j 이하의 비용으로 가능한 경우에
				cache[i][j] = max(cache[i][j],cache[i - 1][j - cost[i]] + memory[i]); // i 번째 앱을 비활성화 했을 경우와 비교
			}
			cache[i][j] = max(cache[i][j],cache[i - 1][j]); // i 번째 앱을 나두었을 경우와 비교
		}
	}

	for (i = 0; i <= sum; i++) {
		if (cache[N][i] >= M) { 
			printf("%d", i);
			break;
		}
	}

	return 0;
}
