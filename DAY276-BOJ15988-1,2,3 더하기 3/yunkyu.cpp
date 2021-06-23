#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#define DIV 1000000009
using namespace std;

long long dp[1000001];
vector<int> v;

long long func(int n) {
	if (dp[n] != -1) 
		return dp[n];
	return dp[n] = (func(n - 1) + func(n - 2) + func(n - 3)) % DIV; // 마지막에 1,2,3을 더한 경우를 더해준다
}

int main() {
	int T;
	scanf("%d", &T);
	
	memset(dp, -1, sizeof(dp));
	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
	int m = 0;
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		v.push_back(n);
		m = max(m, n); // 테스트 케이스 중 가장 큰 수
	}

	func(m);
	for (int i = 0; i < T; i++) {
		printf("%lld\n", dp[v[i]] % DIV);
	}
	return 0;
}
