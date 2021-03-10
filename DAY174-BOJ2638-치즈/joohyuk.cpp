#include <iostream>
#include <vector>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int sz=1e2+1;
int board[sz][sz],n,m,t;
int dr[4]={1,0,-1,0},dc[4]={0,-1,0,1};
bool vis[sz][sz],air[sz][sz];
pii root[sz][sz];
vector<pii>v,melt;

void rootSet(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            root[i][j]=mp(i,j);
        }
    }
}

pii find(pii p){
    if(root[p.first][p.second]==p)return p;
    return root[p.first][p.second]=find(root[p.first][p.second]);
}
void merge(pii p1,pii p2){
    p1=find(p1),p2=find(p2);
    if(air[p1.first][p1.second])root[p2.first][p2.second]=p1;
    else root[p1.first][p2.second]=p2;
}

void ambient(int i,int j){
    for(int k=0;k<4;++k){
        int ni=i+dr[k];
        int nj=j+dc[k];
        if(0<=ni&&ni<n&&0<=nj&&nj<m){
            if(!board[ni][nj]&&!vis[ni][nj]){
                vis[ni][nj]=1;
                merge(mp(i,j),mp(ni,nj));
                ambient(ni,nj);
            }
        }
    }
}

int findMelt(){
    for(auto& p:v){
        int cnt=0;
        for(int k=0;k<4;++k){
            int ni=p.first+dr[k];
            int nj=p.second+dc[k];
            if(0<=ni&&ni<n&&0<=nj&&nj<m){
                auto r=find(mp(ni,nj));
                if(!board[ni][nj]&&air[r.first][r.second])cnt++;
            }
        }
        if(cnt>=2)melt.push_back(p);
    }
    return (int)melt.size();
}

void propagate(pii p){
    for(int k=0;k<4;++k){
        int ni=p.first+dr[k];
        int nj=p.second+dc[k];
        if(0<=ni&&ni<n&&0<=nj&&nj<m){
            auto r=find(mp(ni,nj));
            if(!board[ni][nj]&&!air[r.first][r.second]){
                merge(mp(ni,nj),p);
                propagate(mp(ni,nj));
            }
        }
    }
}

void meltThenResetAmbient(){
    for(auto&p:melt){
        board[p.first][p.second]=0;
        air[p.first][p.second]=1;
        propagate(p);
    }
    melt.clear();
}

void resetV(){
    vector<pii>nv;
    for(auto& p:v)if(board[p.first][p.second])nv.push_back(p);
    v=nv;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    rootSet();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            if(board[i][j])v.push_back(make_pair(i,j));
        }
    }

    air[0][0]=1;vis[0][0]=1;
    ambient(0,0);

    while(findMelt()){
        t++;
        meltThenResetAmbient();
        resetV();
    }
    cout<<t;    
    return 0;
}
