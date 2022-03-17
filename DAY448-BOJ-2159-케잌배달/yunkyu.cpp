#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#define MAX 100000
using namespace std;

typedef long long ll;
int dy[] = { 0, 0,0,-1,1 };
int dx[] = { 0, 1,-1,0,0 };
vector<pair<ll, ll>> v;
ll dp[MAX + 1][5]; // dp[n][i] => n번째 고객 좌표(x,y)를 기준으로 (x+dx[i],y+dy[i])까지의 최단거리

ll getDist(ll fromX, ll fromY, ll toX, ll toY) { // from => to의 맨해튼 거리를 구한다
	return abs(toX - fromX) + abs(toY - fromY);
}

int main() {
	int N;
	int startX, startY;
	cin >> N;
	cin >> startX >> startY;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
		for (int j = 0; j < 5; j++) dp[i][j] = LLONG_MAX;
	}

	for (int i = 0; i < 5; i++) { // 빵집부터 첫번째 고객의 위치 또는 상하좌우 인접 격자점에 대해 최단거리 계산
		int toX = v[0].first + dx[i];
		int toY = v[0].second + dy[i];
		if (toX < 0 || toY < 0 || toX >= MAX || toY >= MAX) continue; 
		dp[0][i] = getDist(startX, startY, toX, toY);
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			// i번째 고객의 위치와 인접 상하좌우 격자점에 대하여
			int toX = v[i].first + dx[j];
			int toY = v[i].second + dy[j];
			if (toX < 0 || toY < 0 || toX >= MAX || toY >= MAX) continue;
			for (int k = 0; k < 5; k++) {
				// 이전 고객의 위치 또는 인접 상하좌우 격자점으로부터 왔을때의 최단거리 모두를 계산
				int fromX = v[i - 1].first + dx[k];
				int fromY = v[i - 1].second + dy[k];
				if (fromX < 0 || fromY < 0 || fromX >= MAX || fromY >= MAX) continue;
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + getDist(fromX, fromY, toX, toY));
			}
		}
	}

	long long ret = dp[N - 1][0];
	// 모든 고객에 배달을 마쳤을때 최단거리를 찾는다.
	for (int i = 1; i < 5; i++) {
		ret = min(dp[N - 1][i], ret);
	}
	cout << ret;

	return 0;
}
