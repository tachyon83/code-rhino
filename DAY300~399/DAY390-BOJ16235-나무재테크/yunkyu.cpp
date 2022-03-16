#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int fert[11][11];
int arr[11][11];
vector<int> tr[11][11];
int dy[] = { -1,1,-1,1,0,0,1,-1 };
int dx[] = { -1,1,1,-1,1,-1,0,0 };

void springSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tr[i][j].size() == 0) continue;

			// 나이 순으로 오름차순 정렬
			sort(tr[i][j].begin(), tr[i][j].end());
			vector<int> temp;
			int dead = 0;

			for (int k = 0; k < tr[i][j].size(); k++) {
				int age = tr[i][j][k];
				if (arr[i][j] < age) { // 양분이 모자라다면 죽는다
					dead += age / 2;
				}
				else { // 양분이 있다면 나이만큼 양분 먹고 나이 1증가 
					arr[i][j] -= age;
					temp.push_back(age + 1);
				}
			}
			tr[i][j].clear(); 
			for (int k = 0; k < temp.size(); k++) tr[i][j].push_back(temp[k]); // 결과로 남은 나무를 다시 넣는다
			arr[i][j] += dead; // 죽은 나무들의 나이/2 만큼 양분 추가
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tr[i][j].size() == 0) continue;

			for (int k = 0; k < tr[i][j].size(); k++) {
				int age = tr[i][j][k];
				if (age % 5 == 0) { // 나이가 5의 배수라면 주변에 나이 1인 나무 추가
					for (int l = 0; l < 8; l++) {
						int ny = i + dx[l];
						int nx = j + dy[l];
						if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
							tr[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	// 땅에 양분 추가
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) arr[i][j] += fert[i][j];
}

void solve(int year) {
	if (year == K) return;
	springSummer();
	fall();
	winter();
	solve(year + 1);
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d",&fert[i][j]);
			arr[i][j] = 5;
		}
	}

	for (i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		tr[x][y].push_back(z); // {x,y}에 나이가 z인 나무 추가
	}

	solve(0);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += tr[i][j].size();
		}
	}
	printf("%d", cnt);
}
