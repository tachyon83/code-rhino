#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {
	int N, K, L;
	cin >> N >> K;
	vector <pair<int, int>> snake;
	snake.push_back(make_pair(0, 0));
	vector <pair<int, int>> apple(K);
	for (int i = 0; i < K; i++) {
		cin >> apple[i].first >> apple[i].second;
		apple[i].first--;
		apple[i].second--;
	}

	cin >> L;
	vector<pair<int, char>> rotate(L);
	for (int i = 0; i < L; i++) {
		int num;
		char rot;
		cin >> num >> rot;
		rotate[i] = make_pair(num, rot);
	}

	int dirIndex = 0;
	int result = 0;

	vector<pair<int, int>>::iterator it;

	while (1) {
		result++;
		int trow = snake.back().first + dir[dirIndex][0];
		int tcol = snake.back().second + dir[dirIndex][1];

		//벽에 부딪히면 끝냄
		if (trow < 0 || trow >= N || tcol < 0 || tcol >= N) {
			break;
		}
		else {
			//뱀이 자기몸에 닿이면 끝냄
			if (snake.end() != find(snake.begin(), snake.end(), make_pair(trow, tcol))) {
				break;
			}
			//일단 이동
			snake.push_back(make_pair(trow, tcol));
			it = find(apple.begin(), apple.end(), make_pair(trow, tcol));
			//사과가 없으면 꼬리 pop 
			if (it == apple.end()) {
				snake.erase(snake.begin());
			}
			//-->와 이것때문에 케이스 몇개가 틀렸어요. 사과 먹은후엔 사과 없어져서 다시 못먹게 해야한다는 것을 늦게 알아차림...재밌네용
			else {
				apple.erase(it);
			}
			//회전해야되면 방향틀기
			if (rotate.empty()) {
				continue;
			}
			else if (rotate[0].first == result) {
				if (rotate[0].second == 'D') {
					dirIndex++;
				}
				else {
					dirIndex--;
				}
				if (dirIndex == -1) {
					dirIndex = 3;
				}
				else if (dirIndex == 4) {
					dirIndex = 0;
				}
				//시간 오름차순으로 써있으므로 이용한 맨처음원소 삭제
				rotate.erase(rotate.begin());
			}
		}
	}
	cout << result;

}
