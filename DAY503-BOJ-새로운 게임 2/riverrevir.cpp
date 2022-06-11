include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 18
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Y, X, Dir;
};
int N, K;
int MAP[MAX][MAX]; // 격자의 색깔
vector<int> MAP_Mal[MAX][MAX]; // 격자에 놓인 말들
vector<INFO> Mal; // K개의 말들의 정보
int moveY[5] = { 0,0,0,-1,1 };
int moveX[5] = { 0,1,-1,0,0 };
int answer = 0; // 턴

void Mal_Move(int I, int J) {
	int Y = Mal[I].Y;
	int X = Mal[I].X;
	int Dir = Mal[I].Dir;
	int nextY = Y + moveY[Dir];
	int nextX = X + moveX[Dir];
	if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N)) { // 이동할 칸이 격자를 벗어나지 않는 경우
		if (MAP[nextY][nextX] == 0) { // 다음 칸이 흰색인 경우 I번째 말부터 현재 칸에 있는 모든 말들을 다음 칸으로 이동시킨다.
			for (int i = J; i < MAP_Mal[Y][X].size(); i++) {
				MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
				Mal[MAP_Mal[Y][X][i]].Y = nextY;
				Mal[MAP_Mal[Y][X][i]].X = nextX;
				MAP_Mal[Y][X].erase(MAP_Mal[Y][X].begin() + i);
				i--;
			}
		}
		else if (MAP[nextY][nextX] == 1) { // 다음 칸이 빨간색일 경우 I번째 말부터 현재 칸에 있는 모든 말들을 순서를 거꾸로 해서 다음 칸으로 이동시킨다.
			for (int i = (MAP_Mal[Y][X].size() - 1); i >= J; i--) {
				MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
				Mal[MAP_Mal[Y][X][i]].Y = nextY;
				Mal[MAP_Mal[Y][X][i]].X = nextX;
				MAP_Mal[Y][X].pop_back();
			}
		}
		else if (MAP[nextY][nextX] == 2) { // 다음 칸이 빨간색일 경우
			// 방향을 반대로 한다.
			if (Mal[I].Dir == 1) {
				Mal[I].Dir = 2;
			}
			else if (Mal[I].Dir == 2) {
				Mal[I].Dir = 1;
			}
			else if (Mal[I].Dir == 3) {
				Mal[I].Dir = 4;
			}
			else if (Mal[I].Dir == 4) {
				Mal[I].Dir = 3;
			}
			Dir = Mal[I].Dir;
			nextY = Y + moveY[Dir];
			nextX = X + moveX[Dir];
			// 이후 바꾼 방향대로 이동할 칸이 격자를 벗어나지 않고 파란색이 아닌 경우 칸을 이동시키고, 격자를 벗어나거나 파란색이면 놔둔다.
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N) && (MAP[nextY][nextX] != 2)) {
				if (MAP[nextY][nextX] == 0) {
					for (int i = J; i < MAP_Mal[Y][X].size(); i++) {
						MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
						Mal[MAP_Mal[Y][X][i]].Y = nextY;
						Mal[MAP_Mal[Y][X][i]].X = nextX;
						MAP_Mal[Y][X].erase(MAP_Mal[Y][X].begin() + i);
						i--;
					}
				}
				else if (MAP[nextY][nextX] == 1) {
					for (int i = (MAP_Mal[Y][X].size() - 1); i >= J; i--) {
						MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
						Mal[MAP_Mal[Y][X][i]].Y = nextY;
						Mal[MAP_Mal[Y][X][i]].X = nextX;
						MAP_Mal[Y][X].pop_back();
					}
				}
			}
		}
	}
	else { // 다음 칸이 격자를 벗어나는 경우, 파란색으로 이동하는 경우와 똑같다.
		if (Mal[I].Dir == 1) {
			Mal[I].Dir = 2;
		}
		else if (Mal[I].Dir == 2) {
			Mal[I].Dir = 1;
		}
		else if (Mal[I].Dir == 3) {
			Mal[I].Dir = 4;
		}
		else if (Mal[I].Dir == 4) {
			Mal[I].Dir = 3;
		}
		Dir = Mal[I].Dir;
		nextY = Y + moveY[Dir];
		nextX = X + moveX[Dir];
		if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N) && (MAP[nextY][nextX] != 2)) {
			if (MAP[nextY][nextX] == 0) {
				for (int i = J; i < MAP_Mal[Y][X].size(); i++) {
					MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
					Mal[MAP_Mal[Y][X][i]].Y = nextY;
					Mal[MAP_Mal[Y][X][i]].X = nextX;
					MAP_Mal[Y][X].erase(MAP_Mal[Y][X].begin() + i);
					i--;
				}
			}
			else if (MAP[nextY][nextX] == 1) {
				for (int i = (MAP_Mal[Y][X].size() - 1); i >= J; i--) {
					MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
					Mal[MAP_Mal[Y][X][i]].Y = nextY;
					Mal[MAP_Mal[Y][X][i]].X = nextX;
					MAP_Mal[Y][X].pop_back();
				}
			}
		}
	}
}

bool isGameEnd() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP_Mal[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	FIRST
		cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	Mal.resize(K + 1);
	for (int i = 1; i <= K; i++) {
		cin >> Mal[i].Y >> Mal[i].X >> Mal[i].Dir;
		MAP_Mal[Mal[i].Y][Mal[i].X].push_back(i);
	}
	while (1) {
		bool Flag = false;
		answer++;
		if (answer > 1000) { // 턴이 1000이 넘으면 게임을 종료시키고 -1을 출력한다.
			answer = -1;
			break;
		}
		for (int i = 1; i <= K; i++) {
			for (int j = 0; j < MAP_Mal[Mal[i].Y][Mal[i].X].size(); j++) {
				if (MAP_Mal[Mal[i].Y][Mal[i].X][j] == i) {
					Mal_Move(i, j);
					break;
				}
			}
			if (isGameEnd()) { // 말들을 움직이는 도중에 칸 하나에 말이 4개 이상 존재하는 경우 게임이 끝난다.
				Flag = true;
				break;
			}
		}
		if (Flag) {
			break;
		}
	};
	cout << answer << "\n";

	return 0;
}
