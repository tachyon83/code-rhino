#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long int s, N, K;

int solve(int y, int x, long long int len) {
	if (len == 1) return 0; // 변의 길이가 1이 되면 하얀색
	long long int sub = len / N; // N * N개의 부분 정사각형의 변 길이는 => 현재 변 길이 / N 
	if (y >= sub * (N - K) / 2 && y < sub * (N + K) / 2 && x >= sub * (N - K) / 2 && x < sub * (N + K) / 2) // 정사각형의 가운데 K*K범위에 있다면 검은색 
		return 1;
	return solve(y % sub, x % sub, sub); // 현재 좌표에 해당하는 부분 정사각형으로
}

int main() {
	int r1, r2, c1, c2;
	scanf("%lld %lld %lld %d %d %d %d", &s, &N, &K, &r1, &r2, &c1, &c2);
	long long int len = pow(N, s); // 시간이 s일때 변의 길이 = N의 s제곱
	for (int i = r1; i <= r2; i++) { 
		for (int j = c1; j <= c2; j++) {
			printf("%d", solve(i, j, len));
		}
		printf("\n");
	}

	return 0;
}
