//처음에 그려봤지만, DP말곤 다른 규칙이 안떠올라서 DP로 풀었다.
//처음에는 상근 차례이므로, 상근이가 돌을 1 또는 3 또는 4 가져가는 세경우중 하나라도 이기는 경우가 있으면 상근이는 자기에게 유리하게 가지고 가므로 이긴다.

#include <iostream>
#include <memory.h>

using namespace std;

int main() {
	int N;
	bool DP[1001] = { false, };
	DP[2] = DP[4] = true;
	cin >> N;

	//1이면 먼저가져가는 사람이 이기는것, 0이면 지는것
	for (int i = 5; i <= N; i++) {
		if (!DP[i - 1] || !DP[i - 3] || !DP[i - 4]) {
			DP[i] = true;
		}
		else {
			DP[i] = false;
		}
	}

	if (DP[N] == true) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
}
