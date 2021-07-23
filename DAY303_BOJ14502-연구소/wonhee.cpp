#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<pair<int, int>> v;
int board[8][8];
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void initialize(int checkingBoard[8][8])
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			checkingBoard[i][j] = board[i][j];
}

int countSafeArea(int checkingBoard[8][8])
{
	int count = 0;
	for (int a = 0; a < N; ++a)
	{
		for (int b = 0; b < M; ++b)
		{
			if (checkingBoard[a][b] == 0)
				++count;
		}
	}
	return count;
}

void fillBirus(int y, int x, int checkingBoard[8][8])
{
	checkingBoard[y][x] = 3;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + direction[i][0], nx = x + direction[i][1];
		if (isRange(ny, nx) && checkingBoard[ny][nx] == 0)
			fillBirus(ny, nx, checkingBoard);
	}
}

void buildWall()
{
	int checkingBoard[8][8];
	int max_count = 0;
	int size = v.size();
	for (int i = 0; i < size - 2; ++i)
	{
		for (int j = i + 1; j < size - 1; ++j)
		{
			for (int k = j + 1; k < size; ++k)
			{
				initialize(checkingBoard);
				checkingBoard[v[i].first][v[i].second] = 1;
				checkingBoard[v[j].first][v[j].second] = 1;
				checkingBoard[v[k].first][v[k].second] = 1;
				for (int a = 0; a < N; ++a)
				{
					for (int b = 0; b < M; ++b)
					{
						if (checkingBoard[a][b] == 2)
							fillBirus(a, b, checkingBoard);
					}
				}
				int count = countSafeArea(checkingBoard);
				max_count = (max_count > count) ? max_count : count;
			}
		}
	}
	cout << max_count;
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				v.push_back({ i,j });
		}
	}
	buildWall();
	return 0;
}