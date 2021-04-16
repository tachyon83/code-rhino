#include <iostream>
#define INF 9999999
using namespace std;
int arr[101][101] = { 0, };
int lessNum(int n);
int main() {

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			arr[i][j] = arr[j][i] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	cout << lessNum(N);
}

int lessNum(int n) {
	for (int k = 1; k <= n; k++) {
		for (int start = 1; start <= n; start++) {
			for (int end = start + 1; end <= n; end++) {
				int tmp = arr[start][k] + arr[k][end];
				if (tmp < arr[start][end]) {
					arr[start][end] = tmp;
					arr[end][start] = tmp;
				}
			}
		}
	}
	int min = 999;
	int answer;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += arr[i][j];
		}
		if (sum < min) {
			answer = i;
			min = sum;
		}
	}
	return answer;
}
