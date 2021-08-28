#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[101];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i <= 5; i++) {
		dp[i] = i;
}
	for (int i = 6; i <= N; i++) 
	{
		for (int j = 3; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}

	}

	printf("%lld", dp[N]);
	return 0;
}
