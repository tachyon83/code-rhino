#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987987897

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int arr[101][101];
	fill(&arr[0][0], &arr[N][N], INF);	//전체 배열을 INF로 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp != 0) {	// i->j로 연결된 경우만 데이터 입력
				arr[i][j] = tmp;
			}
		}
	}

	//i->j / i->k->j 두 경우를 비교에 j로 도착의 최단거리 구하기
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] < INF) {	//INF보다 작으면 i->j로 가는 경우가 있으므로 1출력
				cout << "1 ";
			}
			else {	//INF보다 크다면 i->j로 가는 경우가 없으므로 0출력
				cout << "0 ";
			}
		}
		cout << '\n';
	}

}
