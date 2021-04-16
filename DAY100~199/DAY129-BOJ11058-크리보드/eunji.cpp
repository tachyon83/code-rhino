#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	long dp[101]={ 0, };
	for(int i = 1; i <= N; i++) {
		dp[i] = dp[i-1]+1;
		for (int j = 1; j <= i - 3;j++) {
			dp[i] = max(dp[i], dp[j] * (i - j - 1));
		}
	}


	cout << dp[N];
}
