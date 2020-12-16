#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int N, K, ans, sub = 0;
	vector<int> arr;
	cin >> N >> K;

	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < K; i++)
		sub += arr[i];

	ans = sub;
	for (int i = 0; i < N - K; i++)
	{
		sub += arr[i + K];
		sub -= arr[i];
		ans = max(ans, sub);
	}
	cout << ans;
}