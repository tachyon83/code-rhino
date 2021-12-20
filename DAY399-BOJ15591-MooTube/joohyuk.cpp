#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

const int sz=5000+1;
const ll mx=1e9+1;
int N,Q,p,q,v,cnt;
ll r,k,usado[sz];
vector<pair<int,ll> > g[sz];
bool vis[sz];
queue<int>que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>N>>Q;
    for(int i=0;i<N-1;++i){
        cin>>p>>q>>r;
        g[p].push_back(make_pair(q,r));
        g[q].push_back(make_pair(p,r));
    }
    for(int i=0;i<Q;++i){
        fill(vis,vis+N+1,0);
        fill(usado,usado+N+1,mx);
        cnt=0;
        cin>>k>>v;

        vis[v]=1;
        que.push(v);
        while(!que.empty()){
            int curr=que.front();que.pop();
            for(auto nxp:g[curr]){
                if(!vis[nxp.first]){
                    vis[nxp.first]=1;
                    usado[nxp.first]=min(usado[curr],nxp.second);
                    if(usado[nxp.first]>=k)cnt++;
                    que.push(nxp.first);
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
