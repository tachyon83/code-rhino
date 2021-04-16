#include <iostream>

#define MAX 20

using namespace std;

int N, S, result;
int arr[MAX];

void solution(int idx, int sum, int cnt) {
	if (idx == N) {
		if (sum == S && cnt != 0) {
			result++;
		}
		return;
	}

	solution(idx + 1, sum + arr[idx], cnt + 1);
	solution(idx + 1, sum, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	solution(0, 0, 0);
	
	cout << result << '\n';

	return 0;
}
