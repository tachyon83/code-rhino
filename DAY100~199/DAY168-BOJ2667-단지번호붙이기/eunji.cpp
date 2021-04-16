#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int N;
char map[25][25];
bool visited[25][25] = { 0, };
int doBFS(int i, int j);

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	vector<int> group;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] == '1') {
				int danji = doBFS(i, j);
				group.push_back(danji);
			}
		}
	}
	cout << group.size() << "\n";
	sort(group.begin(), group.end());
	for (int i = 0; i < group.size(); i++) {
		cout << group[i] << "\n";
	}

}

int doBFS(int i, int j) {
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
			if (nextR >= 0 && nextR < N && nextC >= 0 & nextC < N && !visited[nextR][nextC] && map[nextR][nextC] == '1') {
				visited[nextR][nextC] = true;
				num++;
				q.push({ nextR,nextC });
			}
		}
	}
	return num;
}
