#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int N; cin >> N;

	long long arr[101];
	for (int i = 0; i <= 5; i++)
		arr[i] = i;

	for (int i = 6; i <= N; i++)
		arr[i] = max(max(arr[i - 1] + 1, arr[i - 3] * 2), max(arr[i - 4] * 3, arr[i - 5] * 4));

	cout << arr[N];

	return 0;
}