#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[61][61][61];

int solution(int first, int second, int third)
{
	if (first < 0) return solution(0, second, third);
	if (second < 0) return solution(first, 0, third);
	if (third < 0) return solution(first, second, 0);
	if (first == 0 && second == 0 && third == 0)
		return 0;
	int& ret = dp[first][second][third];
	if (ret != -1) return ret;
	ret = 10000000;
	vector<int> attack = { 1,3,9 };
	do {
		int temp = solution(first - attack[0], second - attack[1], third - attack[2]);
		if (ret > temp)
			ret = temp;
	} while (next_permutation(attack.begin(), attack.end()));
	ret += 1;
	return ret;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int arr[3] = { 0 };
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << solution(arr[0], arr[1], arr[2]);
	return 0;
}