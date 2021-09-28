#include <iostream>
using namespace std;
char arr[4000][7000];

void drawStar(int y, int x, int n)
{
	if (n==3)
	{
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		for (int i = x-2; i < x+3; i++)
			arr[y + 2][i] = '*';
		return;
	}

	int half_n = n / 2;
	drawStar(y, x, half_n);
	drawStar(y + half_n, x - half_n, half_n);
	drawStar(y + half_n, x + half_n, half_n);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2*N; j++)
			arr[i][j] = ' ';
	
	drawStar(0, N - 1, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
			cout << arr[i][j];
		cout << '\n';
	}
	return 0;
}