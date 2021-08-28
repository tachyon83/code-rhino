#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std; 

int paper[4][4];
int ans = 0;

void getSum(int n , int m) {
	int bit = 1 << (n * m); // 총 n * m 개의 칸이 있으니 n*m자리인 비트셋으로 모든 조합을 표현
	int i, j, k;
	int total;
	for (i = 0; i < bit; i++) {
		total = 0;
		// 가로줄 확인
		for (j = 0; j < n; j++) {
			int sum = 0;
			for (k = 0; k < m; k++) {
				int a = j * m + k; 
				if ((i & (1 << a)) != 0) { // 비트가 1이면 가로
					sum = sum * 10 + paper[j][k]; // 가로로 이어졌다면 자릿수만큼 10 곱해줌
				}
				else { // 가로에서 세로로 바꼈을때
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}

		// 세로줄 확인
		for (j = 0; j < m; j++) {
			int sum = 0;
			for (k = 0; k < n; k++) {
				int a = k * m + j;
				if ((i & (1 << a)) == 0) { // 비트가 0이면 세로
					sum = sum * 10 + paper[k][j];
				}
				else { // 세로에서 가로로 바꼈을때
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}

		ans = max(ans, total); // 최댓값 갱신
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &paper[i][j]);
		}
	}

	getSum(n, m);
	printf("%d", ans);

	return 0;
}
