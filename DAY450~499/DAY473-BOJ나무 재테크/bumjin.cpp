#include<iostream>
#include<algorithm>
#include<vector>
 
#define endl "\n"
#define MAX 11
using namespace std;
 
int N, M, K;
int Energy[MAX][MAX];
int Insert_Energy[MAX][MAX];
 
vector<int> MAP[MAX][MAX];
 
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
void Input()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> Insert_Energy[i][j];
            Energy[i][j] = 5;
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        MAP[a][b].push_back(c);
    }
}
 
void SpringAndSummer()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (MAP[i][j].size() == 0) continue;
            
            int Die_Tree_Energy = 0;
            vector<int> Temp;
 
            sort(MAP[i][j].begin(), MAP[i][j].end());
            for (int k = 0; k < MAP[i][j].size(); k++)
            {
                int Age = MAP[i][j][k];
 
                if (Energy[i][j] >= Age)
                {
                    Energy[i][j] = Energy[i][j] - Age;
                    Temp.push_back(Age + 1);
                }
                else
                {
                    Die_Tree_Energy = Die_Tree_Energy + (Age / 2);
                }
            }
 
            MAP[i][j].clear();
            for (int k = 0; k < Temp.size(); k++)
            {
                MAP[i][j].push_back(Temp[k]);
            }
            Energy[i][j] = Energy[i][j] + Die_Tree_Energy;
        }
    }    
}
 
void Fall()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (MAP[i][j].size() == 0) continue;
 
            for (int k = 0; k < MAP[i][j].size(); k++)
            {
                int Age = MAP[i][j][k];
 
                if (Age % 5 == 0)
                {
                    for (int a = 0; a < 8; a++)
                    {
                        int nx = i + dx[a];
                        int ny = j + dy[a];
 
                        if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
                        {
                            MAP[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
 
void Winter()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Energy[i][j] = Energy[i][j] + Insert_Energy[i][j];
        }
    }
}
 
void Solution()
{
    for (int i = 0; i < K; i++)
    {
        SpringAndSummer();
        Fall();
        Winter();
    }
 
    int Answer = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Answer = Answer + MAP[i][j].size();
        }
    }
 
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

