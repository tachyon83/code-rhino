#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int N, ans = 2e9 + 1, a1, a2, sub;
	vector<int> arr;
	cin >> N;

	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	int start = 0, end = N - 1;
	while (start < end)
	{
		sub = arr[start] + arr[end];
		if (abs(sub) < ans)
		{
			a1 = arr[start];
			a2 = arr[end];
			ans = abs(sub);
		}

		if (sub < 0)
			start++;
		else
			end--;
	}

	cout << a1 << ' ' << a2;
}