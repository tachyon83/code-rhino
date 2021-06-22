#include <iostream>
#include <queue>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int sz=500;
int board[sz][sz],dp[sz][sz];
bool vis[sz][sz];
int m,n,dr[4]={-1,0,1,0},dc[4]={0,1,0,-1};
priority_queue<pair<int,pii> >pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>m>>n;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>board[i][j];
        }
    }

    dp[0][0]=1;
    pq.push(mp(board[0][0],mp(0,0)));
    while(!pq.empty()){
        auto cp=pq.top();pq.pop();
        int cr=cp.second.first,cc=cp.second.second;
        if(vis[cr][cc])continue;
        vis[cr][cc]=1;
        for(int i=0;i<4;++i){
            int nr=cr+dr[i];
            int nc=cc+dc[i];
            if(0<=nr&&nr<m&&0<=nc&&nc<n&&board[cr][cc]>board[nr][nc]){
                dp[nr][nc]+=dp[cr][cc];
                if(nr!=m||nc!=n)pq.push(mp(board[nr][nc],mp(nr,nc)));
            }
        }
    }
    cout<<dp[m-1][n-1];
    return 0;
}
