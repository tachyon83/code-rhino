#include <cstdio>
#include <memory.h>
using namespace std;

int city[20][20];
int dist[20][20];

int main() {

	int i, j, k, n;
	scanf("%d", &n);
	memset(city, 0, sizeof(city));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &dist[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (i == j)
					break;
				if (i == k || k == j)
					continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					printf("-1");
					return 0;
				}

				if (dist[i][j] == dist[i][k] + dist[k][j]){
					city[i][j] = -1;
					break;
				}
			}
		}
	}

	int sum = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (city[i][j] == 0)
				sum += dist[i][j];
		}
	}

	printf("%d", sum / 2);
	return 0;
}
