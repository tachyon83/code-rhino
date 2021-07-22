#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

string maze[51];
vector<pair<int, int>> pm;
bool check[51][51][51][51];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
char dir[] = { 'N','S','W','E' };

void BFS(int M ,int N) {
	queue < pair<pair<pair<int, int>, pair<int, int>>, string>> q;
	q.push({ { {pm[0].first,pm[0].second},{pm[1].first,pm[1].second} },"" }); // 팩맨 위치와 현재까지의 조작 방향
	check[pm[0].first][pm[0].second][pm[1].first][pm[1].second] = true; 
	int i;

	while (!q.empty()) {
		pair<int, int> a = q.front().first.first;
		pair<int, int> b = q.front().first.second;
		string s = q.front().second;
		q.pop();

		if (a == b) { // 팩맨이 같은 자리에 모였을때
			cout << s.length() << " " << s << "\n";
			return;
		}

		for (i = 0; i < 4; i++) {
			int ny1 = a.first + dy[i];
			int nx1 = a.second + dx[i];
			int ny2 = b.first + dy[i];
			int nx2 = b.second + dx[i];

			// 화면 끝으로 나가면 반대편으로 이동
			if (ny1 < 0 || ny1 >= M || nx1 < 0 || nx1 >= N) {
				if (dir[i] == 'N') {
					ny1 = M - 1;
				}
				else if (dir[i] == 'S') {
					ny1 = 0;
				}
				else if (dir[i] == 'W') {
					nx1 = N - 1;
				}
				else {
					nx1 = 0;

				}
			}

			if (ny2 < 0 || ny2 >= M || nx2 < 0 || nx2 >= N) {
				if (dir[i] == 'N') {
					ny2 = M - 1;
				}
				else if (dir[i] == 'S') {
					ny2 = 0;
				}
				else if (dir[i] == 'W') {
					nx2 = N - 1;
				}
				else {
					nx2 = 0;

				}
			}

			// 고스트를 만나면 더 이상 진행 x
			if (maze[ny1][nx1] == 'G' || maze[ny2][nx2] == 'G') continue;

			// 벽을 만났다면 이전 자리로 
			if (maze[ny1][nx1] == 'X') {
				ny1 = a.first;
				nx1 = a.second;
			}
			
			if (maze[ny2][nx2] == 'X') {
				ny2 = b.first;
				nx2 = b.second;
			}
			
			// 두 팩맨이 현재 위치에 동시에 있었던적이 없다면
			if (!check[ny1][nx1][ny2][nx2]) {
				check[ny1][nx1][ny2][nx2] = true;
				s.push_back(dir[i]); // 조작 방향 저장
				q.push({ {{ny1,nx1},{ny2,nx2}},s });
				s.pop_back();
			}

		}
	}

	cout << "IMPOSSIBLE\n";
}

int main() {
	int T;
	cin >> T;
	int i;
	while (T > 0) {
		int M, N;
		cin >> M >> N;
		for (i = 0; i < M; i++) {
			cin >> maze[i];
			for (int j = 0; j < N; j++) {
				if (maze[i][j] == 'P') { // 팩맨 위치 저장
					pm.push_back({ i,j });
				}
			}
		}

		BFS(M,N);
		// 초기화
		pm.clear();
		memset(check, false, sizeof(check));

		T--;
	}
	return 0;
}
