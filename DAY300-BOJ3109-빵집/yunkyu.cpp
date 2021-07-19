#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int ans = 0;
int r, c;
string map[10001];
int dy[] = { -1, 0 ,1 };
int dx[] = { 1,1,1 };

bool DFS(int y, int x) {
	map[y][x] = 'p'; // 파이프를 생성
	if (x == c - 1) { // 빵집에 도착했다면 성공
		ans++;
		return true;
	}

	int i;

	for (i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 <= ny && ny < r && 0 <= nx && nx < c) {
			if (map[ny][nx] == '.') { // 빈 칸일때
				if (DFS(ny, nx)) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);

	cin >> r >> c;

	int i, j;
	for (i = 0; i < r; i++) {
		cin >> map[i];
	}

	for (i = 0; i < r; i++) {
		if (map[i][0] == '.') // 첫째열의 집이 아닌 공간부터 시작
			DFS(i, 0);
	}


	cout << ans;
	return 0;
}
