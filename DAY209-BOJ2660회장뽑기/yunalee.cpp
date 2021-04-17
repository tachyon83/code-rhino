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

	int arr[51][51];
	fill(&arr[0][0], &arr[N][N], INF);	//모든 값을 최대값으로 초기화

	for (int i = 1; i <= N; i++) {
		arr[i][i] = 0;	//자기자신은 관계가 없으므로 0 셋팅
	}

	int a = 0, b = 0;
	while (1) {
		cin >> a >> b;

		if (a == -1 && b == -1) {	//두 수가 -1이면 입력 종료
			break;
		}

		//입력받은 a와 b사이는 1(친구사이) 이다
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int minNum = INF;
	vector<int> vc;
	for (int i = 1; i <= N; i++) {
		int maxNum = 0;
		for (int j = 1; j <= N; j++) {
			maxNum = max(maxNum, arr[i][j]);	//i와 j의 관계중 최댓값 찾기
		}

		if (minNum > maxNum) {	//최소값보다 최대값이 작은경우
			minNum = maxNum;	//최소값 교체
			vc.clear();			//회장교체
			vc.push_back(i);
		}
		else if (minNum == maxNum) {	//최소값과 최대값이 같으면 회장으로 간주호가 벡터에 추가
			vc.push_back(i);
		}
	}

	cout << minNum << ' ' << vc.size() << '\n';
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << ' ';
	}
}
