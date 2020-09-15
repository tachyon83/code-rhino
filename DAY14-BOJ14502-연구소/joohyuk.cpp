#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
int nr,nc,dr[4]={0,1,0,-1},dc[4]={1,0,-1,0};
int ans,zeros,n,m,lab[8][8];
bool visited[8][8];
queue<pair<int,int>>q;

int bfs(int r,int c){
    int virus=0;
    visited[r][c]=1;
    q.emplace(r,c);
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            nr=curr.first+dr[i];
            nc=curr.second+dc[i];
            if(0<=nr && nr<n && 0<=nc && nc<m && !lab[nr][nc] && !visited[nr][nc]){
                virus++;
                visited[nr][nc]=1;
                q.emplace(nr,nc);
            }
        }
    }
    return virus;
}

int run(){
    memset(visited,0,sizeof(visited));
    int virus=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(lab[i][j]==2 && !visited[i][j]){
                virus+=bfs(i,j);
            }
        }
    }
    return virus;
}

void dfs(int cnt,int num){
    if(cnt==3){
        ans=max(ans,zeros-3-run());
        return;
    }
    for(int i=num;i<n*m-(3-cnt-1);++i){
        int r=i/m,c=i%m;
        if(!lab[r][c]){
            lab[r][c]=1;
            dfs(cnt+1,i+1);
            lab[r][c]=0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>lab[i][j];
            if(!lab[i][j])zeros++;
        }
    }
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
