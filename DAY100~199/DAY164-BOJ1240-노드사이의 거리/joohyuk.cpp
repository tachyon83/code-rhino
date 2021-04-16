#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int sz=1e3+1;
int m,n,a,b,c,nx,nxd,curr,d,cost[sz];
bool vis[sz];
vector<pair<int,int> >g[sz];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n-1;++i){
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    for(int i=0;i<m;++i){
        fill(vis,vis+n+1,0);
        fill(cost,cost+n+1,0);
        queue<int>q;
        cin>>a>>b;
        vis[a]=1;
        q.push(a);
        while(!q.empty()){
            int curr=q.front();q.pop();
            if(curr==b){
                cout<<cost[b]<<endl;
                break;
            }
            for(auto nxp:g[curr]){
                nx=nxp.first,nxd=nxp.second;
                if(!vis[nx]){
                    vis[nx]=1;
                    cost[nx]+=nxd+cost[curr];
                    q.push(nx);
                }
            }
        }
    }
    return 0;
}
