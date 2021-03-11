//빙산
//https://www.acmicpc.net/problem/2573

#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <vector>
#define MAX 300
using namespace std;

typedef struct iceberg{
	int y;
	int x;
	int height;
}iceberg;

int n, m;
int field[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int year = 0;
vector<iceberg> v; 

void push_ice(int y, int x) { //빙하의 좌표와 높이를 저장한다
	iceberg ice;
	ice.y = y;
	ice.x = x;
	ice.height = field[y][x];
	v.push_back(ice);
}
void melt() {
	year++;
	int i, j, y, x;
	//빙하의 동서남북 방향중 바다칸 개수만큼 높이 감소
	for (i = 0; i < v.size(); i++) {
		y = v[i].y;
		x = v[i].x;
		for (j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (field[ny][nx] == 0 && v[i].height > 0) //높이가 0 이하로 가지않게 처리
				v[i].height--;
		}
	}

	//field를 바뀐 높이로 갱신 
	for (i = 0; i < v.size(); i++)
		field[v[i].y][v[i].x] = v[i].height;
}
void BFS(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y,x });
	push_ice(y, x);
	int i;

	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) { 
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!visited[ny][nx] && field[ny][nx] != 0) { //방문하지 않았고 바다가 아닐시 
				push_ice(ny,nx);
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &field[i][j]);
		}
	}

	int cnt = 0;
	while (1) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		v.clear();
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (!visited[i][j] && field[i][j]!= 0) { //바다가 아니고 방문하지 않은 index일시
					BFS(i, j); 
					cnt++; //BFS한번 수행될때마다 빙하 한 덩어리임
				}
			}
		}
		if (cnt == 0) { //빙하가 다녹았다면 0출력
			year = 0;
			break;
		}
		else if (cnt >= 2) { //빙하가 두덩어리 이상으로 나뉘어졌을때
			break;
		}
		melt();
	}
	printf("%d", year);
	return 0;
}
