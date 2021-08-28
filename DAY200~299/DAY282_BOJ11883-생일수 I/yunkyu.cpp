#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

int cache[1000001];
int num[] = { 3,5,8 };

void BFS() {
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++) { // 3, 5, 8 각각 더한 값의 자릿수는 현재 값의 자릿수 + 1
			int next = here + num[i];
			if (next <= 1000000 && cache[next] == -1) {
				q.push({ next, cnt + 1 });
				cache[next] = cnt + 1;
			}
		}
	}

}

void print(int N , int cnt) {
	if (N == 0) return; 

	int i;
	for (i = 0; i < 3; i++) { 
		int next = N - num[i];
		if (next < 0) continue; // 음수는 불가능
		if (cache[next] == cnt - 1) { // 현재 값의 자릿수보다 1 적은 값이여야함
			printf("%d", num[i]);
			print(next, cnt - 1);
			return;
		}
	}
}
int main() {
	int T, N;
	scanf("%d", &T);
	memset(cache, -1, sizeof(cache));
	cache[0] = 0;

	BFS();

	while (T > 0) {
		scanf("%d", &N);
		if (cache[N] == -1) { // 생일수가 존재하지 않는다
			printf("-1\n");
		}
		else {
			print(N, cache[N]);
			printf("\n");
		}
		T--;
	}
	return 0;
}
