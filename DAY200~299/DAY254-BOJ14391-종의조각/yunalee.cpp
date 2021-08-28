#include <iostream>
#include <algorithm>

using namespace std;

int arr[4][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	int answer = 0;
	for (int i = 0; i < (1 << (N * M)); i++) {
		int tmp_j = 0;

		// 가로
		for (int j = 0; j < N; j++) {
			int tmp_k = 0;
			for (int k = 0; k < M; k++) {
				int cell = j * M + k;	//(j, k)칸의 번호 구하기
				if ((i & (1 << cell)) == 0) {
					tmp_k = tmp_k * 10 + arr[j][k];	//가로로 묶이는 수 누적 구하기
				}
				else {	//세로인 경우
					tmp_j += tmp_k;	//현재까지의 가로 누적을 더하기
					tmp_k = 0;	//다음 가로의 누적을 구하기 위해 초기화
				}
			}
			tmp_j += tmp_k;
		}

		// 세로
		for (int j = 0; j < M; j++) {
			int tmp_k = 0;
			for (int k = 0; k < N; k++) {
				int cell = k * M + j;
				if ((i & (1 << cell)) != 0) {
					tmp_k = tmp_k * 10 + arr[k][j];
				}
				else {
					tmp_j += tmp_k;
					tmp_k = 0;
				}
			}
			tmp_j += tmp_k;
		}
		answer = max(answer, tmp_j);
	}

	cout << answer << '\n';
}
