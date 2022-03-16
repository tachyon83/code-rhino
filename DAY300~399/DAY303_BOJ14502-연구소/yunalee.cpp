#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10][10];
int virusArr[10][10];
int answer = 0;
vector<pair<int, int>> virusXY;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int virusCnt = 0;
int wallCnt = 0;

void spreadVirus() {
	queue<pair<int, int>> Queue;
	for (int i = 0; i < virusXY.size(); i++) {	//최초 존재하는 바이러수 수만큼 큐에 저장
		Queue.push(virusXY[i]);
	}
	virusCnt = virusXY.size();
	while (!Queue.empty()) {
		int cx = Queue.front().first;
		int cy = Queue.front().second;
		Queue.pop();
		
		for (int i = 0; i < 4; i++) {
			//다음 이동좌표 구하기
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {	//맵 범위 안에 포함되는 경우
				if (virusArr[nx][ny] == 0) {	//이동지역이 빈칸인 경우
					virusArr[nx][ny] = 2;	//바이러스 확산
					Queue.push({ nx, ny });	//다음 바이러스 확산을 위해 큐에 넣어준다
					virusCnt++;
				}
			}
		}
	}
}

void solution(int x, int y, int cnt) {
	if (cnt > 3) {	//벽을 3개 세운 뒤
		//바이러스 퍼트리기

		copy(&arr[0][0], &arr[0][0] + 100, &virusArr[0][0]);	//바이러스 퍼트릴 맵 복사
		spreadVirus();

		//안전영역 체크
		int safetyAreaCnt = (N * M) - wallCnt - virusCnt;
		answer = max(answer, safetyAreaCnt);

		return;
	}


	//벽 설치하기
	for (int i = x; i < N; i++) {
		for (int j = y; j < M; j++) {
			if (arr[i][j] == 0) {	// (i, j)가 0(빈칸)이라면
				arr[i][j] = 1;	//벽세우기
				solution(i, j + 1, cnt + 1);	//cnt+1번째 벽 세우는 경우의 수를 구하기 위해 재귀적 함수 호출
				arr[i][j] = 0;	//cnt번째 세운 벽 초기화
			}
		}
		y = 0;	//i행에서 세울수 있는 경우의 수 찾기가 끝나 i+1행의 0번째 열부터 탐색해야므로 0으로 초기화
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {	//바이러스가 있는 칸 저장
				virusXY.push_back({ i, j });
			}
			else if (arr[i][j] == 1) {
				wallCnt++;
			}
		}
	}
	wallCnt += 3;
	solution(0, 0, 1);

	cout << answer << '\n';

	return 0;
}
