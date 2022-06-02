#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int maxhappy = -1;
int N;
int dp[22][101];
int happy[21];
int power1[21];

int go(int number,int power) {
	int& cache = dp[number][power];
	if (power < 1) return -1e8;
	if (number >= N) return 0;
	if (cache != -1) return cache;
	return cache = max(go(number + 1, power), happy[number] + go(number + 1, power - power1[number]));
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 101; j++) dp[i][j] = -1;
	for (int i = 0; i < N; i++) cin >> power1[i];
	for (int i = 0; i < N; i++) cin >> happy[i];
	cout << go(0, 100);
}
