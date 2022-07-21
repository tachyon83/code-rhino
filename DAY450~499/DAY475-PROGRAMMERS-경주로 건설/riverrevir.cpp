#include <bits/stdc++.h>
 
using namespace std;
 
class Car{
    public:
    int x,y,cost, dir;
};
 
int solution(vector<vector<int>> board) {
    int answer = 999999999, mx[] = {0,1,0,-1}, my[] = {1,0,-1,0}, N = board.size();
    queue<Car> q;    
    Car c;
    c.x = 0, c.y = 0, c.cost = 0, c.dir = 10;
    q.push(c);
    board[0][0] = 1;
    
    while(!q.empty())
    {
        Car a = q.front();
        q.pop();
        if(a.x == N - 1 && a.y == N - 1)
        {
            if(answer > a.cost) answer = a.cost;
            continue;
        }
        for(int i=0;i<4;i++)
        {
            int nx = a.x + mx[i];
            int ny = a.y + my[i];
            
            if( nx<0 || ny<0 || nx>=N || ny>=N || board[nx][ny] == 1) continue;
            
            int nc = 0;
            
            if(a.dir == 10 || a.dir == i)
                nc = a.cost + 100;
            else if(a.dir != i)
                nc = a.cost + 600;
            
            if(board[nx][ny] == 0 || board[nx][ny] >= nc)
            {
                board[nx][ny] = nc;
                Car p;
                p.x = nx, p.y = ny, p.cost = nc, p.dir = i;
                q.push(p);
            }
        }
        
    }
    return answer;
}
