#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

vector<pair<int, int>> v[221];
int main() {
	int D, P, C, F, S, i;
	scanf("%d %d %d %d %d", &D, &P, &C, &F, &S);
	for (i = 0; i < P; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		v[from].push_back({ to,D });
	}

	for (i = 0; i < F; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back({ to, D - cost }); // 버는 돈에 가는 비용을 빼줌
	}

	//벨만 포드
	vector<long long> dist(C + 1, LONG_MIN);
	dist[S] = D; // 시작 지역에서  D달러를 벌고 시작함
	for (i = 1; i <= C; i++) {
		for (int j = 1; j <= C; j++) {
			if (dist[j] == LONG_MIN) continue; // 갈수 없는 경우는 스킵
			for (auto &p : v[j]) {
				long long cost = dist[j] + p.second;
				long long next = p.first;
				if (cost > dist[next]) { // 더 많은 돈을 벌수 있다면 갱신
					dist[next] = cost;
					if (i == C) { // V번째 순환에 거리에 변형이 있다면 사이클이 있다
						printf("-1");
						return 0;
					}
				}
			}
		}
	}

	sort(dist.begin(), dist.end());
	printf("%lld", dist[C]); // 정렬하여 제일 큰 값을 출력

	return 0;
}
