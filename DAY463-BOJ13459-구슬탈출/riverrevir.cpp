#include<iostream>
 
#define endl "\n"
#define MAX 10
using namespace std;
 
int N, M, Answer = 987654321;
char MAP[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
pair<int, int> Red, Blue;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'R')
            {
                Red.first = i;
                Red.second = j;
                MAP[i][j] = '.';
            }
            else if (MAP[i][j] == 'B')
            {
                Blue.first = i;
                Blue.second = j;
                MAP[i][j] = '.';
            }
        }
    }
}
 
int Move_Dist(int x, int y, int xx, int yy)
{
    return abs(x - xx) + abs(y - yy);
}
 
int Inverse_Direction(int Cur_D)
{
    if (Cur_D == 0) return 1;
    else if (Cur_D == 1) return 0;
    else if (Cur_D == 2) return 3;
    else if (Cur_D == 3) return 2;
}
 
void Move(int Rx, int Ry, int Bx, int By, int Cnt, int dir)
{
    if (Cnt >= Answer) return;
    if (Cnt > 10) return;
 
    bool Red_Flag = false;
    bool Blue_Flag = false;
 
    int nRx = Rx + dx[dir];
    int nRy = Ry + dy[dir];
    while (1)
    {
        if (MAP[nRx][nRy] == '#') break;
        if (MAP[nRx][nRy] == 'O')
        {
            Red_Flag = true;
            break;
        }
        nRx = nRx + dx[dir];
        nRy = nRy + dy[dir];
    }
    nRx = nRx - dx[dir];
    nRy = nRy - dy[dir];
 
    int nBx = Bx + dx[dir];
    int nBy = By + dy[dir];
    while (1)
    {
        if (MAP[nBx][nBy] == '#') break;
        if (MAP[nBx][nBy] == 'O')
        {
            Blue_Flag = true;
            break;
        }
        nBx = nBx + dx[dir];
        nBy = nBy + dy[dir];
    }
    nBx = nBx - dx[dir];
    nBy = nBy - dy[dir];
 
    if (Blue_Flag == true) return;
    else
    {
        if (Red_Flag == true)
        {
            Answer = Min(Answer, Cnt);
            return;
        }
    }
 
    if (nRx == nBx && nRy == nBy)
    {
        int Red_Dist = Move_Dist(Rx, Ry, nRx, nRy);
        int Blue_Dist = Move_Dist(Bx, By, nBx, nBy);
 
        if (Red_Dist > Blue_Dist)
        {
            nRx = nRx - dx[dir];
            nRy = nRy - dy[dir];
        }
        else
        {
            nBx = nBx - dx[dir];
            nBy = nBy - dy[dir];
        }
    }
 
 
    for (int i = 0; i < 4; i++)
    {
        if (i == dir) continue;
        if (i == Inverse_Direction(dir)) continue;
 
        Move(nRx, nRy, nBx, nBy, Cnt + 1, i);
    }
}
 
void Solution()
{
    for (int i = 0; i < 4; i++)
    {
        int x = Red.first;
        int y = Red.second;
        int xx = Blue.first;
        int yy = Blue.second;
 
        Move(x, y, xx, yy, 1, i);
    }
 
    if (Answer > 10 || Answer == 987654321) Answer = -1;
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

// 
