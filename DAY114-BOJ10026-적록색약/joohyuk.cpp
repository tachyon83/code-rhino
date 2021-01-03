#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
const int sz=100;
int n,normal,abnormal;
int nr,nc,cr,cc,dr[4]={0,1,0,-1},dc[4]={1,0,-1,0};
bool vis[sz][sz];
char color,board[sz][sz];
queue<pair<int,int> >q;

void bfs(bool cond,int i,int j){
    vis[i][j]=1;
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto cp=q.front();q.pop();
        cr=cp.first;
        cc=cp.second;
        color=board[cr][cc];

        for(int i=0;i<4;++i){
            nr=cr+dr[i];
            nc=cc+dc[i];

            if(0<=nr && nr<n && 0<=nc && nc<n && !vis[nr][nc]){
                if(cond){
                    if(board[nr][nc]==color){
                        vis[nr][nc]=1;
                        q.push(make_pair(nr,nc));
                    }
                }else{
                    if(color=='R'||color=='G'){
                        if(board[nr][nc]=='R'||board[nr][nc]=='G'){
                            vis[nr][nc]=1;
                            q.push(make_pair(nr,nc));
                        }
                    }else{
                        if(board[nr][nc]==color){
                            vis[nr][nc]=1;
                            q.push(make_pair(nr,nc));
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!vis[i][j]){
                normal++;
                bfs(1,i,j);
            }
        }
    }

    for(int i=0;i<n;++i)fill(vis[i],vis[i]+n,0);

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!vis[i][j]){
                abnormal++;
                bfs(0,i,j);
            }
        }
    }

    cout<<normal<<' '<<abnormal;

    return 0;
}
