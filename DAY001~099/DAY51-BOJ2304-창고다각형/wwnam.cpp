#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	const int MAX_SIZE = 1000;
	int start, end, N, L, H, area = 0, height = 0, maxH = 0, maxCur = 0;
	vector<int> arr(MAX_SIZE + 1, 0);

	cin >> N;

	start = MAX_SIZE + 1;
	end = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> L >> H;
		arr[L] = H;
		start = min(start, L);
		end = max(end, L);

		if (maxH < H)
			maxH = H, maxCur = L;
	}

	area = height = arr[start];
	for (int i = start + 1; i <= maxCur; i++)
	{
		height = max(height, arr[i]);
		area += height;
	}
	if (start != end && maxCur != end)
	{
		height = arr[end];
		area += height;
		for (int i = end - 1; i > maxCur; i--)
		{
			height = max(height, arr[i]);
			area += height;
		}
	}

	cout << area;
}