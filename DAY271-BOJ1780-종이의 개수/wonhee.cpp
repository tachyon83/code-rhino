#include<iostream>
using namespace std;
int number[2187][2187];
int ret[3] = { 0 };
void solve(int leftTop_y, int leftTop_x, int rightBottom_y, int rightBottom_x)
{
	int firstNum = number[leftTop_y][leftTop_x];
	bool isChange = false;
	for (int i = leftTop_y; i < rightBottom_y; i++)
	{
		for (int j = leftTop_x; j < rightBottom_x; j++)
			if (firstNum != number[i][j])
			{
				isChange = true; break;
			}
		if (isChange) break;
	}
	if (!isChange)
	{
		if (firstNum == -1) ++ret[0];
		else if (firstNum == 0)++ret[1];
		else ++ret[2];
		return;
	}

	int partialLen_y = (rightBottom_y - leftTop_y) / 3;
	int partialLen_x = (rightBottom_x - leftTop_x) / 3;
	solve(leftTop_y, leftTop_x, leftTop_y + partialLen_y, leftTop_x + partialLen_x);
	solve(leftTop_y, leftTop_x + partialLen_x, leftTop_y + partialLen_y, leftTop_x + partialLen_x * 2);
	solve(leftTop_y, leftTop_x + partialLen_x * 2, leftTop_y + partialLen_y, leftTop_x + partialLen_x * 3);
	solve(leftTop_y + partialLen_y, leftTop_x, leftTop_y + partialLen_y * 2, leftTop_x + partialLen_x);
	solve(leftTop_y + partialLen_y, leftTop_x + partialLen_x, leftTop_y + partialLen_y * 2, leftTop_x + partialLen_x * 2);
	solve(leftTop_y + partialLen_y, leftTop_x + partialLen_x * 2, leftTop_y + partialLen_y * 2, leftTop_x + partialLen_x * 3);
	solve(leftTop_y + partialLen_y * 2, leftTop_x, leftTop_y + partialLen_y * 3, leftTop_x + partialLen_x);
	solve(leftTop_y + partialLen_y * 2, leftTop_x + partialLen_x, leftTop_y + partialLen_y * 3, leftTop_x + partialLen_x * 2);
	solve(leftTop_y + partialLen_y * 2, leftTop_x + partialLen_x * 2, leftTop_y + partialLen_y * 3, leftTop_x + partialLen_x * 3);
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> number[i][j];
	solve(0, 0, N, N);
	cout << ret[0] << '\n' << ret[1] << '\n' << ret[2];
	return 0;
}