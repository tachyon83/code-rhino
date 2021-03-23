#include <iostream>
#include <vector>
using namespace std;

char map[5][9];
vector<pair<int, int>> v;
bool used[12];

bool check() { // 6줄 모두 합이 26이 되는지 확인
	if ((map[0][4] - 64) + (map[1][3] - 64) + (map[2][2] - 64) + (map[3][1] - 64) != 26) return false;
	if ((map[0][4] - 64) + (map[1][5] - 64) + (map[2][6] - 64) + (map[3][7] - 64) != 26) return false;
	if ((map[4][4] - 64) + (map[3][3] - 64) + (map[2][2] - 64) + (map[1][1] - 64) != 26) return false;
	if ((map[4][4] - 64) + (map[3][5] - 64) + (map[2][6] - 64) + (map[1][7] - 64) != 26) return false;
	if ((map[1][1] - 64) + (map[1][3] - 64) + (map[1][5] - 64) + (map[1][7] - 64) != 26) return false;
	if ((map[3][1] - 64) + (map[3][3] - 64) + (map[3][5] - 64) + (map[3][7] - 64) != 26) return false;

	return true;
}

void DFS(int index) {
	if (index == v.size()) { // 빈칸을 다 채웠을시에
		if (check()) { // 매직 스타가 되는지 확인한다
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					cout << map[i][j];
				}
				cout << '\n';
			}
			exit(0); // 처음 발견하면 바로 종료 
		}

		return;
	}
	int y = v[index].first;
	int x = v[index].second;

	for (int i = 0; i < 12; i++) { // 빠른 알파벳부터 사용하지 않았다면 넣어본다
		if (!used[i]) {
			map[y][x] = i + 'A';
			used[i] = true;
			DFS(index + 1);
			map[y][x] = 'x';
			used[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'x') // 빈칸 좌표 저장
				v.push_back({ i,j });
			else if (map[i][j] != '.') { 
				used[map[i][j] - 65] = true; // 알파벳 사용여부 아스키코드 값 이용
			}
		}
	}

	DFS(0);
	return 0;
}
