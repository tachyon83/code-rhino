#include <iostream>
#define endl '\n'
using namespace std;

const int rsz=1e4+1,csz=5e2+1;
bool vis[rsz][csz],flag;
char board[rsz][csz];
int r,c,cnt,dr[3]={-1,0,1};

void solve(int cr,int cc){
    if(cc==c-1){
        flag=1;
        return;
    }
    for(int i=0;i<3;++i){
        int nr=cr+dr[i];
        if(!flag&&0<=nr&&nr<r&&board[nr][cc+1]=='.'&&!vis[nr][cc+1]){
            vis[nr][cc+1]=1;
            solve(nr,cc+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>r>>c;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<r;++i){
        flag=0;
        solve(i,0);
        if(flag)cnt++;
    }
    cout<<cnt;
    return 0;
}
