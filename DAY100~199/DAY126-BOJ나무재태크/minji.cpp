#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10+1

int n, m, k;
int x, y, z;
int food;
vector<int> A[MAX][MAX]; //age
int foods[MAX][MAX]; //현재 양분
int AddFoods[MAX][MAX]; //추가양분

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


void SS()
{
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (A[i][j].size() == 0) continue;

			vector<int> tmp;
			int die_tree = 0;
			//나이가 어린 나무부터 양분을 먹음
			sort(A[i][j].begin(), A[i][j].end());
			for (int k = 0; k < A[i][j].size(); k++)
			{
				int age = A[i][j][k];
				if (foods[i][j] >= age)
				{
					//자신의 나이 만큼 양분을 먹고, 나이 += 1
					foods[i][j] = foods[i][j] - age;
					tmp.push_back(age + 1);
				}
				else
				{
					//먹지 못하면 죽어 양분이됨
					//죽은 나무 int(나이/2)가 해당칸에 양분으로 추가
					die_tree = die_tree + (age / 2);
				}
			}
			A[i][j].clear();
			for (int k = 0; k < tmp.size(); k++)
			{
				A[i][j].push_back(tmp[k]);
			}
			foods[i][j] = foods[i][j] + die_tree;

		}
}


// 번식하는 나무는 (age//5 == 0) 이면 8곳으로 나이가 1인 나무 번식
// 땅을 벗어나지 않아야함
void Fall()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{ 
			if (A[i][j].size() == 0) continue;

			for (int k = 0; k < A[i][j].size(); k++)
			{
				if (A[i][j][k] % 5 == 0)
				{
					for (int l = 0; l < 8; l++)
					{
						int nx = i + dx[l];
						int ny = j + dy[l];

						if (nx >= 1 && ny >= 1 && nx <= n && ny <= n)
						{
							A[nx][ny].push_back(1);
						}

					}
				}
			}
		}
}

//땅에 양분 추가됨 addfoods
void Winter()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			foods[i][j] = foods[i][j] + AddFoods[i][j];
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= n; c++)
		{
			
			cin >> AddFoods[r][c]; //겨울에 추가될 양분
			foods[r][c] = 5; //초기양분

		}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		A[x][y].push_back(z);
	}

	for (int i = 0; i < k; i++)
	{
		SS();
		Fall();
		Winter();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			ans = ans + A[i][j].size();
		}

	cout << ans << endl;

	return 0;

}
