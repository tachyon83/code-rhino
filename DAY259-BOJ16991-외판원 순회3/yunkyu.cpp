#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#define MAX 987654321
using namespace std;

vector<pair<int, int>> v;
double dp[1 << 16][16];
double dist[16][16];

double DFS(int visit, int here , int n) {
	if (visit == ((1 << n) - 1)) { // 모든 도시를 방문했다면
		if (dist[here][0] == 0) { // 출발한 지점으로 돌아갈수 없다면
			return MAX; // 불가능하므로 가장 큰 수
		}
		return dist[here][0];
	}

	int i;
	double& ret = dp[visit][here];
	if (ret) return ret; 

	double res = MAX;
	for (i = 1; i < n; i++) {
		if ((visit & (1 << i)) == 0 && dist[here][i] != 0) { // 방문하지 않은 도시이고 갈수 있는곳이면
			res = min(res, DFS(visit | (1 << i), i, n) + dist[here][i]); // 가장 최소의 거리를 구함
		}
	}
	
	return ret = res;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({ x,y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dist[i][j] = dist[j][i] = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
		}
	}

	printf("%lf", DFS(1, 0, n));

	return 0;
}
