#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int mapArr[110][110];

//           우  하  좌  상
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, l;
	cin >> n >> k;

	//사과좌표 입력
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		mapArr[x][y] = 1;
	}

	cin >> l;
	vector<pair<int, char>> vc;

	//뱀이동 경로 입력
	for (int i = 0; i < l; i++) {
		pair<int, char> p;
		cin >> p.first >> p.second;
		vc.push_back(p);
	}

	deque<pair<int, int>> Deque;
	pair<int, int> dPair;
	dPair.first = dPair.second = 1;	//처음 시작 뱀의 위치 입력
	mapArr[1][1] = 2;
	Deque.push_back(dPair);

	int len = vc.size();
	int vec = 0;
	int result = 0;
	//입력된 이동만큼 반복
	int i = 0;
	int move = vc[i].first;
	while (1) {
		//뱀이 이동할 곳
		int next_x = Deque.front().first + dx[vec];
		int next_y = Deque.front().second + dy[vec];

		result++;	//이동횟수 증가

		
		if (next_x < 1 || next_x > n || next_y < 1 || next_y > n) {	//벽밖인 경우 종료
			cout << result << '\n';
			return 0;
		}		
		else if (mapArr[next_x][next_y] == 2) {	//뱀 몸통에 부딪힌 경우
			cout << result << '\n';
			return 0;
		}
		else if (mapArr[next_x][next_y] == 1) {	//사과가 있다면 사과위치를 뱀의 머리로
			dPair.first = next_x;
			dPair.second = next_y;
			Deque.push_front(dPair);
			mapArr[next_x][next_y] = 2;
		}
		else {
			//뱀한칸 이동
			dPair.first = next_x;
			dPair.second = next_y;
			Deque.push_front(dPair);
			mapArr[next_x][next_y] = 2;
			mapArr[Deque.back().first][Deque.back().second] = 0;
			Deque.pop_back();
		}

		if ((result == move && vc.size() > i)) {
			//뱀의 방향성 변경
			if (vc[i].second == 'D') {
				vec++;
				if (vec > 3) {
					vec = 0;
				}
			}
			else if (vc[i].second == 'L') {
				vec--;
				if (vec < 0) {
					vec = 3;
				}
			}
			if (i < vc.size() - 1) {
				move = vc[++i].first;
			}
		}
	}

	cout << result << '\n';

	return 0;

}
