#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

bool visited[100001];
int walk[] = { -1,1 };

void BFS(int n, int k) {
	memset(visited, false, sizeof(visited));
	int i,j;
	queue<int> q;
	q.push(n);
	visited[n] = true;
	int sec = 0;

	while (!q.empty()) {
		int size = q.size();

		for (i = 0; i < size; i++) {
			n = q.front();
			q.pop();

			if (n == k) { // 도착
				printf("%d", sec);
				return;
			}

      // 걸어갈 경우
			for (j = 0; j < 2; j++) {
				int nn = n + walk[j];
				if (0 <= nn && nn <= 100000 && visited[nn] == false) { 
					visited[nn] = true;
					q.push(nn);
				}
			}

      // 순간이동으로 갈 경우
			if ((n * 2) <= 100000 && visited[n * 2] == false) {
				visited[n * 2] = true;
				q.push(n * 2);
			}
		}
		sec++;
	}
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	BFS(n, k);
	return 0;
}
