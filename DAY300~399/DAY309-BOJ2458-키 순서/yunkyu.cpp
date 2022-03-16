#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

int arr[501][501];
int arr2[501][501];

void floyd(int n) { // 모든 노드에 대해 경로가 존재한다면 갱신
	int i, j, k;

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i != j) {
					if (arr[i][j] > arr[i][k] + arr[k][j]) {
						arr[i][j] = arr[i][k] + arr[k][j];
					}
					if (arr2[i][j] > arr2[i][k] + arr2[k][j]) {
						arr2[i][j] = arr2[i][k] + arr2[k][j];
					}
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;

    // 정방향과 역방향 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j) {
				arr[i][j] = INF;
				arr2[i][j] = INF;
			}
			
		}
	}
	
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr2[b][a] = 1;
	}

	floyd(n);

	int cnt = 0;
	for (i = 1; i <= n; i++) {
		bool check = true;
		for (j = 1; j <= n; j++) {
			if (arr[i][j] == INF && arr2[i][j] == INF) { // 정방향과 역방향 둘다 경로가 존재하지 않는다면 
				check = false;
				break;
			}
		}

		if (check) cnt++; // 모든 노드에 대해 경로가 있다면 순서를 알 수 있다
	}

	printf("%d", cnt);

	return 0;
}
