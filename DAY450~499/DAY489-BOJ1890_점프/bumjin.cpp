#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;

int board[100][100];
long long int dp[100][100];
int n;


int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num; scanf("%d", &num);
			board[i][j] = num;
		}
	}

	dp[0][0] = 1;

	for (int col = 0; col < n; col++)
	{
		for (int row = 0; row < n; row++)
		{
			if (board[col][row] == 0) continue;

			if (dp[col][row] != 0)
			{
				int next_row = row + board[col][row];
				int next_col = col + board[col][row];

				if(next_col < n) dp[next_col][row] += dp[col][row];
				if(next_row < n) dp[col][next_row] += dp[col][row];
			}
		}
	}

	printf("%lld", dp[n - 1][n - 1]);


	return 0;
}
