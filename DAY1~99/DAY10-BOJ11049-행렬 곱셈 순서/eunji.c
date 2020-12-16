#include <stdio.h>

int main() {
	int N;
	int i,j,k;
	int arr[501][2] = {0,};
	int count[501][501] = { 0, };
	int tmp;
	scanf("%d",&N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	
	for (i = 1; i<N; i++) {
		count[i][i+1] = arr[i][0] * arr[i+1][0] * arr[i+1][1];
	}

	for (i=2; i < N; i++) {
		for (j = 1; j <= N-i; j++) {
			int end = j + i;
			for (k = j; k <end; k++) {
				tmp = count[j][k] + count[k + 1][end] + arr[j][0] * arr[k][1] * arr[end][1];
				if (count[j][end] == 0) {
					count[j][end] = tmp;
				}
				else {
					if (tmp < count[j][end]) {
						count[j][end] = tmp;
					}
				}
			}
		}
	}
	printf("%d", count[1][N]);

}
