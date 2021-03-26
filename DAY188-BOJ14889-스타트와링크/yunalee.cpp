#include <iostream>
#include <algorithm>

using namespace std;

int N, answer = 987987987;
int map[21][21];
bool checked[21];

void solution(int cnt, int pos) {
	if (cnt == N / 2) { //N명중 1/2가 팀으로 묶인경우 탐색 종료
		int start, link;
		start = link = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (checked[i] && checked[j]) {
					start += map[i][j];
				}
				if (!checked[i] && !checked[j]) {
					link += map[i][j];
				}
			}
		}

		int tmp = abs(start - link);
		if (tmp < answer) { //스타트팀과 링크팀의 차이가 적은 경우
			answer = tmp;
		}
		return;
	}

	for (int i = pos; i <= N; i++) {
		checked[i] = true;  //스타트팀
		solution(cnt + 1, i + 1);
		checked[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	solution(0, 1);

	cout << answer << '\n';
	
	return 0;
}
