#include <iostream>
using namespace std;

int n;
int dp[1001];

int main(){
	dp[1] = 1;
	dp[2] = 3;
	cin >> n;
	
	for ( int i = 3; i <= n; i++){
		dp[i] = dp[i - 2] * 2 + dp[i - 1];
		dp[i] = dp[i] % 10007;
	}
	
	cout << dp[n] ;
}