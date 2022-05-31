#include <vector>
#include <queue>
#include<iostream>
using namespace std;
 
int Max_Size;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool Visit[100][100];
 
int BFS(int a, int b, int m, int n, vector<vector<int>> MAP)
{
    int Color = MAP[a][b];
    int Size = 1;
    queue<pair<int,int>> Q;
    Q.push(make_pair(a,b));
    Visit[a][b] = true;
    
    while(Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0 ; i < 4; i++)
        {
            int nx = x +dx[i];
            int ny = y+ dy[i];
            if(nx>=0 && ny>=0 && nx < m && ny < n)
            {
                if(MAP[nx][ny] == Color && Visit[nx][ny] == false)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(nx,ny));
                    Size++;
                }
            }
        }
    }
    return Size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
    for(int i = 0 ; i <m;i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            Visit[i][j] = false;
        }
    }
    int number_of_area = 0;
    int max_size_of_one_area = 0;  
    for(int i = 0; i < m; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(picture[i][j] != 0 && Visit[i][j] == false)
            {
                int Size = BFS(i, j, m, n, picture);
                if(Size > max_size_of_one_area) max_size_of_one_area = Size;
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
