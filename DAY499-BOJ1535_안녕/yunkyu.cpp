#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int lost[21];
int happy[21];
int maxHappy = 0;

void DFS(int idx, int accHappy, int hp) {
	if (idx == N) { // N명의 사람까지 모두 고려했다면
		maxHappy = max(maxHappy, accHappy);
		return;
	}

	if (hp - lost[idx] > 0) { // 체력이 남는다면
		DFS(idx + 1, accHappy + happy[idx], hp - lost[idx]);
	}
	DFS(idx + 1, accHappy, hp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int sumLost = 0, sumHappy = 0;
	for (int i = 0; i < N; i++) {
		cin >> lost[i];
		sumLost += lost[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> happy[i];
		sumHappy += happy[i];
	}

	if (sumLost < 100) { // 전체 잃는 체력이 100을 넘지 않는다면 
		cout << sumHappy;
	}
	else {
		DFS(0, 0, 100);
		cout << maxHappy;
	}

	return 0;
}
