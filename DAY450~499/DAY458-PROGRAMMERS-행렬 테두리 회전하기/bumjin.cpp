#include <string>
#include <vector>
 
using namespace std;
 
int MAP[110][110];
 
int Min(int A, int B) { return A < B ? A : B; }
 
 
int Turning(int x, int y, int xx, int yy)
{
    int Min_Num;
    int Temp = MAP[x][y];
    Min_Num = Temp;
    for (int i = x; i < xx; i++)
    {
        Min_Num = Min(Min_Num, MAP[i][y]);
        MAP[i][y] = MAP[i + 1][y];
    }
    for (int i = y; i < yy; i++)
    {
        Min_Num = Min(Min_Num, MAP[xx][i]);
        MAP[xx][i] = MAP[xx][i + 1];
    }
    for (int i = xx; i > x; i--)
    {
        Min_Num = Min(Min_Num, MAP[i][yy]);
        MAP[i][yy] = MAP[i - 1][yy];
    }
    for (int i = yy; i > y; i--)
    {
        Min_Num = Min(Min_Num, MAP[x][i]);
        MAP[x][i] = MAP[x][i - 1];
    }
    MAP[x][y + 1] = Temp;
    return Min_Num;
}
 
vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    int Num = 1;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            MAP[i][j] = Num++;
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int x = queries[i][0]; x--;
        int y = queries[i][1]; y--;
        int xx = queries[i][2]; xx--;
        int yy = queries[i][3]; yy--;
 
        answer.push_back(Turning(x, y, xx, yy));
    }
    
    return answer;
}
