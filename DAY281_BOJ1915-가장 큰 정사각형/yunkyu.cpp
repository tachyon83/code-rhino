#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m;
int mSize = -1;
int cache[1001][1001];

int main() {
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%1d", &cache[i][j]);

	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {

			if (cache[i][j] == 1) 
				cache[i][j] = min(cache[i - 1][j], min(cache[i - 1][j - 1], cache[i][j - 1])) + 1; // 가장 작은값이 0 일 경우 정사각형이 아님
			
			mSize = max(mSize, cache[i][j]); // 가장 큰 길이 구함
		}
	}

	printf("%d", mSize * mSize);
	return 0;
}
