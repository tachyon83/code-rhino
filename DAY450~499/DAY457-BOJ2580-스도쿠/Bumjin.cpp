#include<iostream>
 
#define endl "\n"
#define MAX 9
using namespace std;
 
int MAP[MAX][MAX];
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];
 
void Input()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] != 0)
            {
                Row[i][MAP[i][j]] = true;
                Col[j][MAP[i][j]] = true;
                Square[(i / 3) * 3 + (j / 3)][MAP[i][j]] = true;
            }
        }
    }
}
 
void Print()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}
 
void DFS(int Cnt)
{
    int x = Cnt / MAX;    // x 좌표
    int y = Cnt % MAX;    // y 좌표
    
    if (Cnt == 81)
    {
        Print();
        exit(0);
    }
 
    if (MAP[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (Row[x][i] == false && Col[y][i] == false && Square[(x / 3) * 3 + (y / 3)][i] == false)
            {
                Row[x][i] = true;
                Col[y][i] = true;
                Square[(x / 3) * 3 + (y / 3)][i] = true;
                MAP[x][y] = i;
                DFS(Cnt + 1);
                MAP[x][y] = 0;
                Row[x][i] = false;
                Col[y][i] = false;
                Square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else DFS(Cnt + 1);
}
 
void Solution()
{
    DFS(0);
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
