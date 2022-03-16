#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
long long int dp[100001][3]; // xx xo ox 

void solve(int idx) {
	if (idx == N) {
		return;
	}

	dp[idx][0] = (dp[idx - 1][0] + dp[idx - 1][1] + dp[idx - 1][2]) % 9901; // 현재 row에 아무 동물도 없다면 이전 row에 3가지 경우 모두 가능
	dp[idx][1] = (dp[idx - 1][0] + dp[idx - 1][2]) % 9901; // 현재 row에 오른쪽 칸에 사자가 있다면 이전 row에 아무 동물도 없는 경우와 사자가 왼쪽에 있는 경우
	dp[idx][2] = (dp[idx - 1][0] + dp[idx - 1][1]) % 9901; // 위와 반대로

	solve(idx + 1);
}

int main() {
	scanf("%d", &N);
	dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 1; 
	solve(1);

	long long int ans = dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]; 
	printf("%lld", ans % 9901);
	return 0;
}
