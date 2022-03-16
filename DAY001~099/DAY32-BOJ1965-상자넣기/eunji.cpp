#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int>arr;
	vector<int>dp;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	arr.push_back(1001);

	for (int i = 0; i <= n; i++) {
		dp.push_back(1);
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j]>max) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;

	}

	cout << dp[n]-1;

}
