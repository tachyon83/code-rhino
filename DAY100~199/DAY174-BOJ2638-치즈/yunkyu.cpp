#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 100
using namespace std;

int n, m;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int paper[MAX][MAX];
bool air[MAX][MAX];
queue<pair<int, int>> cheese;
int time = 0;

void BFS(int y, int x) {
	queue<pair<int, int>> q;
	int i;
	q.push({ y, x });
	air[y][x] = true;

	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m) {
				if (!air[ny][nx] && paper[ny][nx] == 0) {
					q.push({ ny,nx });
					air[ny][nx] = true; //외부공기 표시
				}
			}
		}
	}
}

bool melt(int y, int x) {
	int i;
	int cnt = 0;
	//주변에 공기가 있는 칸이 2칸 이상일경우 녹음
	for (i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (air[ny][nx])
			cnt++;
		if (cnt == 2) return true;
	}

	return false;
}

void contact_air(int s) {
	time++;
	int y, x, i;
	queue<pair<int, int>> check; 
	for (i = 0; i < s; i++) {
		y = cheese.front().first;
		x = cheese.front().second;
		cheese.pop();

		if (melt(y, x)) { //녹을 치즈 저장
			check.push({ y,x });
		}
		else //치즈가 녹지 않았다면 다시 큐에 푸시
			cheese.push({ y,x });
	}

	//하나씩 녹으면 다음치즈가 녹을때 같이 영향이 가므로 큐에 저장해놓고 한번에 녹임
	while (!check.empty()) {
		y = check.front().first;
		x = check.front().second;
		check.pop();
		paper[y][x] = 0; 
		//치즈가 녹고 외부공기가 유입되니 주변공간도 확인
		BFS(y, x);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &paper[i][j]);
			if (paper[i][j] == 1) { //치즈의 위치를 미리 저장
				cheese.push({ i, j });
			}
		}
	}

	BFS(0, 0); //외부 공기 체크
	while (!cheese.empty()) { //치즈가 다녹을때까지
		contact_air(cheese.size());
	}

	printf("%d", time);
	return 0;
}
