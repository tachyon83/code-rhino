#include<iostream>
using namespace std;
#define MAXINT 100000

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int N, M; cin >> N >> M;
	int comp[501][501] = { 0 };
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i != j)
				comp[i][j] = MAXINT;

	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		comp[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				comp[i][j] = min(comp[i][k] + comp[k][j], comp[i][j]);

	int answer = N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (comp[i][j] == MAXINT && comp[j][i] == MAXINT)
			{
				--answer;
				break;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}