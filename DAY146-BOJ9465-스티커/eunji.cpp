#include <stdio.h>
#include <stdlib.h>

int **n;
int **P;
int find3max(int N);
void findP(int N);
int findmax(int a, int b);

int main() {
	int N;
	int i,j,k;
	int loop;

	scanf("%d", &loop);
	for (k = 0; k < loop; k++) {
		scanf("%d", &N);

		n = (int**)malloc(sizeof(int*)*(N + 1));
		P = (int**)malloc(sizeof(int*)*(N + 1));

		for (i = 1; i <= N; i++) {
			n[i] = (int*)malloc(sizeof(int) * 2);
			P[i] = (int*)malloc(sizeof(int) * 3);
		}
		for (i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &n[j][i]);
			}
		}

		P[1][0] = n[1][0];
		P[1][1] = n[1][1];
		P[1][2] = 0;

		findP(N);
		printf("%d\n", find3max(N));

		for (i = 1; i <= N; i++) {
			free(n[i]);
			free(P[i]);
		}
		free(n);
		free(P);
	}
}

int find3max(int N) {
	int max = 0;
	for (int i = 0; i < 3; i++) {
		if (P[N][i] > max) {
			max = P[N][i];
		}
	}
	return max;
}
void findP(int N) {
	int i;
	for (i = 2; i <= N; i++) {
		P[i][0] = findmax(P[i - 1][1], P[i - 1][2]) + n[i][0];
		P[i][1] = findmax(P[i - 1][0], P[i - 1][2]) + n[i][1];
		P[i][2] = findmax(findmax(P[i - 1][0], P[i - 1][1]), P[i - 1][2]);
	}
}

int findmax(int a, int b) {
	return (a >= b ? a : b);
}
