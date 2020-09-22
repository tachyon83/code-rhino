#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int product[101][2];
int DP[101][100001];
int main() {
	int N, K;
	int small = 100000;
	memset(DP, 0, sizeof(DP));

	cin >> N >> K;

	for (int i = 1; i <=N; i++) {
		cin >> product[i][0] >> product[i][1];

		if (product[i][0] < small) {
			small = product[i][0];
		}
	}
	//처음엔 for문 위치를 서로 바꿔서 짰는데.. 그렇게 할려면 무엇을 넣고 무엇을 뺄지 관리하기 힘들더라구요..
	//물건 하나씩을 골라 넣을지 말지로 dp배열에 값을 다 넣습니다.
	for (int i = 1; i <= N; i++) {

		for (int j = small; j <= K; j++) {

			//넣을수 있다면, 
			if (j - product[i][0] >= 0) {
				//안넣는거랑 넣는거중에 큰거
				DP[i][j] = max(DP[i - 1][j], DP[i - 1 ][j - (product[i][0])]+product[i][1]);
				//넣으면 무게더하기전 최대값에서 지금가치 더한거
			}
			//안넣으면,
			else { 
				//넣기전단계 그대로.
				DP[i][j] = DP[i - 1][j];
			}


		}
	}

	cout << DP[N][K];
}
