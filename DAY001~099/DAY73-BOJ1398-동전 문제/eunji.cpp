#include <iostream>
using namespace std;
int minCoin(long long num);

int DP[100] = { 0, };
void main2() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 1; i < 100; i++) {
		DP[i] = i;
		if(i>=10) DP[i] = min(DP[i], DP[i - 10] + 1);
		if(i>=25) DP[i] = min(DP[i], DP[i - 25] + 1);
	}
	for (int i = 0; i < T; i++) {
		long long  num;
		cin >> num;
		cout <<minCoin(num)<<endl;
	}

}

int minCoin(long long num) {
	int total = 0;
	while (num >0) {
		total += DP[num % 100];
		num /= 100;
	}
	return total;

}
