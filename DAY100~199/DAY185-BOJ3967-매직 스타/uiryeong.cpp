#include<iostream>
#include<vector>
 
using namespace std;
 
char MAP[5][9];
bool Select[13];
int X_cnt;
 
vector<pair<int, int>> V;
 
void Input()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> MAP[i][j];
            if ('A' <= MAP[i][j] && MAP[i][j] <= 'L')
            {
                Select[MAP[i][j] - 'A'] = true;
            }
            else if (MAP[i][j] == 'x')
            {
                V.push_back(make_pair(i, j));
                X_cnt++;
            }
        }
    }
}
 
bool CheckMAP()
{
    if ((MAP[0][4] - 'A' + 1) + (MAP[1][3] - 'A' + 1) + (MAP[2][2] - 'A' + 1) + (MAP[3][1] - 'A' + 1) != 26) return false;
    if ((MAP[0][4] - 'A' + 1) + (MAP[1][5] - 'A' + 1) + (MAP[2][6] - 'A' + 1) + (MAP[3][7] - 'A' + 1) != 26) return false;
    if ((MAP[1][1] - 'A' + 1) + (MAP[1][3] - 'A' + 1) + (MAP[1][5] - 'A' + 1) + (MAP[1][7] - 'A' + 1) != 26) return false;
    if ((MAP[3][1] - 'A' + 1) + (MAP[3][3] - 'A' + 1) + (MAP[3][5] - 'A' + 1) + (MAP[3][7] - 'A' + 1) != 26) return false;
    if ((MAP[4][4] - 'A' + 1) + (MAP[3][3] - 'A' + 1) + (MAP[2][2] - 'A' + 1) + (MAP[1][1] - 'A' + 1) != 26) return false;
    if ((MAP[4][4] - 'A' + 1) + (MAP[3][5] - 'A' + 1) + (MAP[2][6] - 'A' + 1) + (MAP[1][7] - 'A' + 1) != 26) return false;
 
    return true;
}
 
void Print_MAP()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
    }
}
 
void DFS(int Idx, int Cnt)
{
    if (Cnt == X_cnt)
    {
        if (CheckMAP() == true)
        {
            Print_MAP();
            exit(0);
        }
        return;
    }
 
    for (int i = 0; i < 12; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        MAP[V[Idx].first][V[Idx].second] = i + 'A';
        DFS(Idx + 1, Cnt + 1);
        MAP[V[Idx].first][V[Idx].second] = 'x';
        Select[i] = false;
    }
}
 
void Solution()
{
    DFS(0, 0);
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
 
    Solve();
 
    return 0;
}
