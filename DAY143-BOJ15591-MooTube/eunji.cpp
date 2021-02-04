//문제 이해한게 맞는지 모르겟어요..
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;
	vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N - 1; i++) {
		int x, y, val;
		cin >> x >> y >> val;
		arr[x][y] = val;
		arr[y][x] = val;
		if (arr[x][x] == 0 || val < arr[x][x]) {
			arr[x][x] = val;
		}
		if (arr[y][y] == 0 || val < arr[y][y]) {
			arr[y][y] = val;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (arr[i][j] != 0) continue;
			arr[i][j] = arr[i][i] < arr[j][j] ? arr[i][i] : arr[j][j];
			arr[j][i] = arr[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		int num, movie;
		cin >> num >> movie;
		int answer = 0;
		for (int j = 1; j <= N; j++) {
			if (j != movie && arr[movie][j] >= num) answer++;
		}
		cout << answer << endl;
	}

}
