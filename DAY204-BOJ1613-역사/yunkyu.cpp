#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

bool map[401][401];

void floyd(int n) {
	int i, j, k;

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (map[i][k] && map[k][j]) map[i][j] = true;
			}
		}
	}
}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		map[i][i] = true;
	}
}
int main() {
	int n, k, s;
	scanf("%d %d", &n, &k);
	init(n);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = true;
	}
	floyd(n);
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!map[a][b] && !map[b][a]) printf("0\n");
		else if (map[a][b]) printf("-1\n");
		else if (map[b][a]) printf("1\n");
	}

	return 0;
}
