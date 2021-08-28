#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1000000
using namespace std;

int par[MAX + 1];
int d[MAX + 1];
int arr[1001];

int main() {
	int n, k, i;
	while (true) {
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0) break; // 종료

		queue<pair<int,int>> q;
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		q.push({ arr[0],0 }); // 루트와 깊이 0 삽입 
		int parent = arr[0];
		int depth = 0;
		for (i = 1; i < n; i++) {
			if (arr[i - 1] + 1 < arr[i]) { // 연속되는 수가 아니라면 다음 노드의 자식이 되어야한다
				parent = q.front().first;
				depth = q.front().second;
				q.pop();
			}
			q.push({ arr[i],depth + 1 }); // 자식 노드의 깊이 = 부모노드의 깊이 + 1
			par[arr[i]] = parent; // 부모 노드 저장
			d[arr[i]] = depth + 1; // 깊이 저장
		}
		
		int cnt = 0;
		for (i = 0; i < n; i++) {
			if (d[arr[i]] == d[k]) { // 깊이가 같고
				int a = par[arr[i]];
				int b = par[k];
				if (a != b) { // 부모가 같지않다면
					if (par[a] == par[b]) // 부모의 부모가 같을때 사촌
						cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
