#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int city[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> s;
int ans = 999999;

int getDist() {
	// 고른 치킨집과 집들 사이에 치킨거리를 더한 결과를 반환
	int ret = 0;
	for (int i = 0; i < home.size(); i++) {
		int dist = 999999;
		for (int j = 0; j < M; j++) {
			dist = min(dist, abs(home[i].first - s[j].first) + abs(home[i].second - s[j].second));
		}

		ret += dist;
	}

	return ret;
}

void solve(int idx, int cnt) {
	if (cnt == M) { // 치킨집을 다 골랐다면
		ans = min(ans, getDist());
		return;
	}

	// 치킨집을 M개 고르는 모든 조합을 구한다
	for (int i = idx; i < chicken.size(); i++) {
		s.push_back(chicken[i]);
		solve(i + 1, cnt + 1);
		s.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &city[i][j]);
			if (city[i][j] == 2) {
				chicken.push_back({ i,j });
			}
			else if (city[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}

	solve(0, 0);
	printf("%d", ans);

	return 0;
}
