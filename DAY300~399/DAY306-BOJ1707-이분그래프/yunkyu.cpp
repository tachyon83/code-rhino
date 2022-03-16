#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> graph[20001];
int check[20001];
bool flag;

void DFS(int v, int c) {
	check[v] = c; // c 집합으로 설정
	int i;
	for (i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if (check[nv] == 0) { // 아직 구분안했다면 반대 집합으로 정함
			DFS(nv, c * -1);
		}
		else if (check[nv] && c == check[nv]) { // 구분돼있는데 현재와 같은 집합이라면 실패
			flag = false;
			return;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T > 0) {
		int v, e;
		scanf("%d %d", &v, &e);
		for (int i = 0; i < e; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			// 양방향 연결
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		flag = true;
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) { // 검사하지 않은 정점이라면
				DFS(i, 1);
			}
		}

		if (!flag) 
			printf("NO\n");

		else 
			printf("YES\n");

		// 초기화
		for (int i = 1; i <= v; i++)
			graph[i].clear();

		memset(check, 0, sizeof(check));
		T--;
	}
	return 0;
}
