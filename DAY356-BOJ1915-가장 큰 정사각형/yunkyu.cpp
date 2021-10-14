#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 1000
using namespace std;

int n, m;
int arr[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];
int maxSize = 0;

bool check(int i, int j) {
	return arr[i][j] && arr[i - 1][j] && arr[i][j - 1] && arr[i - 1][j - 1];
}

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1) { 
				dp[i][j] = 1;
				maxSize = 1; // 배열에 1이 하나라도 있으면 가장 큰 정사각형의 크기는 최소 1이다
			}
		}
	}

	if (n == 1 || m == 1) { // 행이나 열이 한줄이라면
		printf("%d", maxSize * maxSize);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) continue;
			if (check(i, j)) { // 왼쪽,위쪽,왼쪽 위 대각에 대해 값이 존재한다면
				int minValue = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
				dp[i][j] = minValue + 1; // 3값 중 가장작은값 + 1이 현재 값이 가질수있는지 정사각형의 최대 길이
				maxSize = max(maxSize, dp[i][j]); // 정사각형의 가장 큰 길이를 구한다
			}
		}
	}

	printf("%d", maxSize * maxSize);

	return 0;
}
