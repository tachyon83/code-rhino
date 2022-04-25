#include <string>
#include <vector>
#include <iostream>
int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};
int visited[30][30]={0,};
int cost[30][30]={0,};
using namespace std;
vector<vector<int>> tboard;
int n;
int st=0; int co=0;
int sum=0;
int minv=2100000000;
int tsum;
void dfs(int r,int c,int d,int tsum) {
    
    if(cost[r][c]!=0 && (tsum>cost[r][c]) ) return;
    if(tsum<=cost[r][c]) cost[r][c]=tsum;
    
    if(r==n-1 && c==n-1)
    {
        if(minv>tsum) 
            minv=tsum;
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];
        if((nr>=0 && nr <=n-1) && (nc>=0 && nc<=n-1))
        if(tboard[nr][nc]!=1 && visited[nr][nc]==0)
        {
            visited[nr][nc]=1;
           if(d==i) {
            dfs(nr,nc,d,tsum+100);
           }
            else {
                if(!(r==0 && c==0))
                 tsum+=500;
                dfs(nr,nc,i,tsum+100);
                if(!(r==0 && c==0))
                    tsum-=500;
            }
            visited[nr][nc]=0;
           
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    tboard=board;
    n=board.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j]=2100000000;
    visited[0][0]=1;
    dfs(0,0,0,0);
   
    answer=minv;
    return answer;
}
