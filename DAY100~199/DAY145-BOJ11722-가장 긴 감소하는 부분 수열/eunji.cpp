#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int arr[1000];
	int dp[1000];
	int N;
	cin >> N;
	int max = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
		}
		if (dp[i] > max)max = dp[i];
	}

	cout << max;
}
