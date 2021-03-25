#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int stats[20][20];
int members[20]; // 0 => 스타트팀 1 => 링크팀
int minScore = 987654321;

int getScore(int which) {
	vector<int> v; 
	// 팀 생성
	for (int i = 0; i < n; i++) {
		if(members[i] == which) 
			v.push_back(i);
	}

	int score = 0;

	// 모든 쌍을 구해서 능력치를 더해준다
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			score += stats[v[i]][v[j]] + stats[v[j]][v[i]];
		}
	}

	return score;
}
int getDiff() { // 능력치 차이 계산
	return abs(getScore(0) - getScore(1));
}

void DFS(int index, int cnt) {
	if (cnt == n / 2) { // 두팀으로 나눴다면
		minScore = min(minScore,getDiff());
		return;
	}

	// n/2명을 링크팀으로 배정한다
	for (int i = index; i < n; i++) {
		members[i] = 1;
		DFS(i + 1, cnt + 1);
		members[i] = 0;
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &stats[i][j]);
		}
	}

	DFS(0, 0);
	printf("%d", minScore);
	return 0;
}
