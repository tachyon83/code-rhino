#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[1001];
int dp[1001];
int dp2[1001];

int main() {
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = dp2[i] = 1;
	}
	
	// 앞에서부터 i번째 인덱스까지의 가장 긴 오름차순 부분수열을 구한다 
	for (i = 2; i <= N; i++) {
		for (j = 1; j < i; j++) {
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// 뒤에서부터 i번째 인덱스까지의 가장 긴 내림차순 부분수열을 구한다 
	for (i = N - 1; i >= 1; i--) {
		for (j = N; j >= i + 1; j--) {
			if (arr[i] > arr[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	int ans = 0;
	for (i = 1; i <= N; i++) {
		ans = max(ans, dp[i] + dp2[i] - 1); // i번째 인덱스의 오름차순 수열과 내림차순 수열의 길이에 중복되는 값 -1 빼줌
	}

	printf("%d", ans);
	return 0;
}
