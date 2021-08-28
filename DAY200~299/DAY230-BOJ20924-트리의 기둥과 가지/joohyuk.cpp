#include <iostream>
#include <vector>
#define endl '\n'
#define mp make_pair
#define pii pair<int,int>
using namespace std;

const int sz=2e5+1;
int n,r,a,b,d,cost[sz],giga,mx;
vector<pii>tree[sz];
vector<int>leaf;

void solve(int node,int p,int c){
    bool isLeaf=1;
    int csz=(int)tree[node].size();
    if(!giga){
        if(node==r){
            if(csz>1)giga=node;
        }else if(csz>2)giga=node;
    }
    cost[node]=c;
    mx=max(mx,cost[node]);
    
    for(auto np:tree[node]){
        if(np.first==p)continue;
        isLeaf=0;
        if(node==giga)solve(np.first,node,np.second);
        else solve(np.first,node,np.second+c);
    }
    if(isLeaf)leaf.push_back(node);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>r;
    for(int i=0;i<n-1;++i){
        cin>>a>>b>>d;
        tree[a].push_back(mp(b,d));
        tree[b].push_back(mp(a,d));
    }
    solve(r,0,0);
    if(!giga)cout<<mx<<' '<<0<<endl;
    else{
        mx=0;
        for(int curr:leaf)mx=max(mx,cost[curr]);
        cout<<cost[giga]<<' '<<mx<<endl;
    }
    return 0;
}
