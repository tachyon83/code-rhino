#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int edge[500001];
int cnt = 0;

int main() {
	double total;
	int n;
	scanf("%d %lf", &n, &total);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u] ++;
		edge[v] ++;
	}

	for (int i = 1; i <= n; i++) 
		if (edge[i] == 1) cnt++; // 엣지가 1개인 노드가 리프노드

	printf("%lf", total / cnt); // 리프노드에서 물이 멈추기때문에 물의양에 리프노드의 총갯수를 나눠준다
	return 0;
}
