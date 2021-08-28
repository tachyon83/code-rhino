#include <iostream>
#include <vector>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
#define ll long long
using namespace std;

const int sz=1e5+1;
int n,m,mode,zs[sz][2],os[sz][2],values[sz][2],p[sz],u,v,c;
ll ans,ans1,ans2;
vector<int>tree[sz];

void find(int curr,int parent){
    p[curr]=parent;
    int s=0;
    for(int child:tree[curr]){
        if(child==parent)continue;
        find(child,curr);
    }
}

pii process(int curr,int prev){
    if(prev){
        zs[curr][mode]+=1;
        values[curr][mode]=0;
    }else{
        os[curr][mode]+=1;
        values[curr][mode]=1;
    }
    for(int child:tree[curr]){
        if(child==p[curr])continue;
        auto temp=process(child,(prev+1)%2);
        zs[curr][mode]+=temp.first;
        os[curr][mode]+=temp.second;
    }
    return make_pair(zs[curr][mode],os[curr][mode]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    find(1,0);
    mode=0;
    process(1,1);
    mode=1;
    process(1,0);

    for(int i=0;i<m;++i){
        cin>>u>>v>>c;
        if(p[u]==v){
            if(c){
                ans1=zs[u][0]*(os[1][0]-os[u][0]);
                ans2=zs[u][1]*(os[1][1]-os[u][1]);
                ans=ans1+ans2;
            }else{
                ans1=zs[u][0]*(zs[1][0]-zs[u][0]);
                ans2=zs[u][1]*(zs[1][1]-zs[u][1]);
                ans=ans1+ans2;
            }
        }else{
            if(c){
                ans1=os[v][0]*(zs[1][0]-zs[v][0]);
                ans2=os[v][1]*(zs[1][1]-zs[v][1]);
                ans=ans1+ans2;
            }else{
                ans1=zs[v][0]*(zs[1][0]-zs[v][0]);
                ans2=zs[v][1]*(zs[1][1]-zs[v][1]);
                ans=ans1+ans2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
