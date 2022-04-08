#include <string>
#include <vector>
 
using namespace std;
 
vector<vector<int>> MAP;
 
void DFS(int x, int y, int Size, vector<int> &answer)
{
    bool Zero, One;
    Zero = One = true;
    for (int i = x; i < x + Size; i++)
    {
        for (int j = y; j < y + Size; j++)
        {
            if (MAP[i][j] == 0) One = false;
            if (MAP[i][j] == 1) Zero = false;
        }
    }
 
    if (Zero == true)
    {
        answer[0]++;
        return;
    }
    if (One == true)
    {
        answer[1]++;
        return;
    }
 
    DFS(x, y, Size / 2, answer);
    DFS(x, y + Size / 2, Size / 2, answer);
    DFS(x + Size / 2, y, Size / 2, answer);
    DFS(x + Size / 2, y + Size / 2, Size / 2, answer);
}
 
vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer(2, 0);
    MAP = arr;
    DFS(0, 0, arr.size(), answer);
    return answer;
}
