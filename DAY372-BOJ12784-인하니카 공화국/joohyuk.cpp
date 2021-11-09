#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int sz=1e3+1,big=2e4+1,bd=1e3+1+1;
vector<pii>g[sz];
vector<int>dg[bd];
int depth[sz],cost[sz],m,n,t,a,b,d;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            g[i].clear();
            cost[i]=0;
        }
        fill(depth,depth+n+1,0);
        depth[1]=1;
        for(int i=0;i<m;++i){
            cin>>a>>b>>d;
            g[a].push_back(mp(b,d));
            g[b].push_back(mp(a,d));
        }

        int mxd=0;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int curr=q.front();q.pop();
            mxd=max(mxd,depth[curr]);
            for(pii np:g[curr]){
                if(!depth[np.first]){
                    depth[np.first]=depth[curr]+1;
                    q.push(np.first);
                }
            }
        }
        for(int i=1;i<=n;++i){
            dg[depth[i]].push_back(i);
            if(depth[i]==mxd){
                cost[i]=big;
            }
        }

        for(int i=mxd;i>1;--i){
            for(int node:dg[i]){
                for(pii np:g[node]){
                    if(depth[np.first]>depth[node])continue;
                    int temp=min(cost[node],np.second);
                    cost[np.first]+=temp;
                }
            }
        }
        if(n==1)cout<<0<<endl;
        else cout<<cost[1]<<endl;
    }
    return 0;
}
