#include <cstdio>
#include <algorithm>
using namespace std;

int graph[101][101];
int main() {

	int n, i, j, k;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (graph[i][k] == 1 && graph[k][j] == 1) {
					graph[i][j] = 1;
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	return 0;
}
