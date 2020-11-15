#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, ans = 0;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (ans + 1 < arr[i])
			break;
		ans += arr[i];
	}
	cout << ans + 1;
}