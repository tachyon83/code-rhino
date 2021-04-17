#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#define INF 9999
using namespace std;

int n;
int relation[51][51];
vector<int> cand;
int score[51];
int cnt = 0;

void init() {
	int i, j;
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			relation[i][j] = INF;
		}
	}

	for (i = 1; i <= n; i++) {
		relation[i][i] = 1;
	}
}
void floyd_warshall() {
	int i, j, k;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j)
				continue;
			for (k = 1; k <= n; k++) {
				if (relation[j][k] > relation[j][i] + relation[i][k]) {
					relation[j][k] = relation[j][i] + relation[i][k];
				}
			}
		}
	}
}
void getScore() {
	int i, j;

	for (i = 1; i <= n; i++) {
		int m = relation[i][1];
		for (j = 2; j <= n; j++) {
			m = max(m, relation[i][j]);
		}
		score[i] = m;
	}
}
int getCandi() {
	int i, j;
	int minScore = score[1];
	for (i = 2; i <= n; i++) {
		minScore = min(minScore, score[i]);
	}

	for (i = 1; i <= n; i++) {
		if (score[i] == minScore) {
			++cnt;
			cand.push_back(i);
		}
	}

	return minScore;
}
int main() {
	scanf("%d", &n);

	init();

	while (1) {
		int m1, m2;
		scanf("%d %d", &m1, &m2);
		if (m1 == -1 && m2 == -1)
			break;
		relation[m1][m2] = 1;
		relation[m2][m1] = 1;
	}

	floyd_warshall();
	getScore();
	int minScore = getCandi();

	printf("%d %d\n",minScore, cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", cand[i]);
	
	return 0;
}
