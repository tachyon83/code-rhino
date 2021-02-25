#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int sz=1e2+1;
int cnt,m,n,nr,nc,p1,p2,dr[4]={0,1,0,-1},dc[4]={1,0,-1,0};
char board[sz][sz];
bool vis[sz][sz];

void dfs(int r,int c,char sol){
    for(int i=0;i<4;++i){
        nr=r+dr[i],nc=c+dc[i];
        if(0<=nr&&nr<n&&0<=nc&&nc<m&&!vis[nr][nc]&&board[nr][nc]==sol){
            vis[nr][nc]=1;
            cnt++;
            dfs(nr,nc,sol);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>m>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j]){
                vis[i][j]=1;
                cnt=1;
                dfs(i,j,board[i][j]);
                cnt*=cnt;
                if(board[i][j]=='W')p1+=cnt;
                else p2+=cnt;
            }
        }
    }
    cout<<p1<<' '<<p2;
    return 0;
}
