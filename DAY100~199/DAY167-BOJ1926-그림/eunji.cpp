#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int n, m;
int numMax = 0;
int map[500][500] = { 0, };
bool visited[500][500] = { 0, };
void doBFS(int i, int j);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j]) {
				num++;
				doBFS(i, j);
			}
		}
	}
	cout << num << "\n" << numMax;

}

void doBFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;
	int num = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextR = r + dirR[i];
			int nextC = c + dirC[i];
			if (nextR >= 0 && nextR < n && nextC >= 0 & nextC < m && !visited[nextR][nextC] && map[nextR][nextC]) {
				visited[nextR][nextC] = true;
				num++;
				q.push({ nextR,nextC });
			}
		}
	}
	if (num > numMax) numMax = num;
	return;
}
