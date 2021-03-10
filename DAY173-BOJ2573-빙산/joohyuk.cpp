#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=3e2+1;
int board[sz][sz],nb[sz][sz],n,m,t,cnt,curr;
int dr[4]={1,0,-1,0},dc[4]={0,-1,0,1};
bool vis[sz][sz];
vector<pair<int,int> >v;

void resetVis(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            vis[i][j]=0;
        }
    }
}

void counter(pair<int,int>p){
    for(int i=0;i<4;++i){
        int ni=p.first+dr[i];
        int nj=p.second+dc[i];
        if(0<=ni&&ni<n&&0<=nj&&nj<m){
            if(board[ni][nj]&&!vis[ni][nj]){
                vis[ni][nj]=1;
                cnt++;
                counter(make_pair(ni,nj));
            }
        }
    }
}

bool sep(){
    vis[v[0].first][v[0].second]=1;
    cnt=1;
    counter(v[0]);
    resetVis();
    if(curr==cnt)return false;
    return true;
}

void copy(){
    vector<pair<int,int> >nv;
    for(auto& p:v){
        board[p.first][p.second]=nb[p.first][p.second];
        if(nb[p.first][p.second])nv.push_back(p);
    }
    v=nv;
    curr=(int)v.size();
}

void melt(pair<int,int> p){
    int sea=0;
    for(int i=0;i<4;++i){
        int ni=p.first+dr[i];
        int nj=p.second+dc[i];
        if(0<=ni&&ni<n&&0<=nj&&nj<m){
            if(!board[ni][nj])sea++;
        }
    }
    nb[p.first][p.second]=board[p.first][p.second]-sea<0?0:board[p.first][p.second]-sea;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            if(board[i][j])v.push_back(make_pair(i,j));
        }
    }

    curr=(int)v.size();
    while(!sep()){
        t++;
        for(auto& p:v)melt(p);
        copy();
        if(!curr){
            cout<<0;
            return 0;
        }
    }
    cout<<t;
    return 0;
}
