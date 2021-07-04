#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>
using namespace std;

int N, M;
string v[51];
int visited[51][51];
int visit[51][51];
int arr[51][51];
int dy[] = { 2,-2,2,-2,1,-1,1,-1 };
int dx[] = { 1,-1,-1,1,2,-2,-2,2 };

void sumArr() { // 모든 마알로부터의 이동횟수를 더함
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			arr[i][j] += visited[i][j];
		}
	}
}

void BFS(int y, int x, int num) {
	int i;
	queue<pair<pair<int, int>,pair<int,int>>> q;
	visited[y][x] = 0; // 처음은 이동하지 않아도 도달하므로 0
	visit[y][x]++;
	q.push({ { y,x }, {0,1} });
	
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		int maal = q.front().second.first; // 마알 횟수
		int n = q.front().second.second; // 이동 횟수
		q.pop();

		for (i = 0; i < 8; i++) { 
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx] == -1) { // 방문하지 않았고 가능한 구간이라면
				visit[ny][nx] ++;
				if (maal >= num) { // 한번에 가능한 마알 횟수를 넘었다면 이동횟수 증가
					maal = 0;
					n++;
				}
				visited[ny][nx] = n; // ny,nx까지의 이동횟수
				q.push({ {ny,nx},{maal + 1,n} }); // 1마알 이동
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	int i, j;
	for (i = 0; i < N; i++) {
		cin >> v[i];
	}
	int maal = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int num = v[i][j] - '0'; 
			if (num >= 1 && num <= 9) { // 마알이라면
				maal++; // 마알 총 갯수 구함
				memset(visited, -1, sizeof(visited));
				BFS(i, j, num);
				sumArr();
			}
		}
	}

	bool check = false;
	int ans = 987654321;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (visit[i][j] == maal && arr[i][j] >= 0) { // 모든 마알에서 모일수 있다면
				ans = min(ans, arr[i][j]);
				check = true;
			}
		}
	}

	if (!check) // 모일방법이 없음
		cout << -1;
	else
		cout << ans;
	return 0;
}
