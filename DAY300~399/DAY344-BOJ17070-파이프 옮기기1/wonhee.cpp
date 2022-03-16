#include <iostream>
using namespace std;
int dir[3][2] = { {0, 1}, {1, 1}, {1, 0} };
int N, result = 0;
int arr[16][16];

void func(int y, int x, int pipe)
{
	if (y == N - 1 && x == N - 1)
	{
		result++;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if ((i == 0 && pipe == 2) || (i == 2 && pipe == 0))
			continue;

		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny >= N || nx >= N || arr[ny][nx] == 1 || (i == 1 && (arr[y][x + 1] == 1 || arr[y + 1][x] == 1)))
			continue;
		func(ny, nx, i);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	func(0, 1, 0);
	cout << result << "\n";
	return 0;
}