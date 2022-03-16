#include <iostream>
#include <vector>
#define endl '\n'
#define ll long long
using namespace std;

const int sz=3e5+1;
vector<int>gr[sz];
int p[sz],n,u,v,depth[sz];
ll d,g;

void form(int a){
    for(int nx:gr[a]){
        if(!p[nx]){
            p[nx]=a;
            depth[nx]=depth[a]+1;
            form(nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    p[1]=-1;
    form(1);
    for(int i=1;i<=n;++i){
        ll nsz=gr[i].size();
        if(nsz>=3)g+=nsz*(nsz-1)*(nsz-2)/6;
        if(depth[i])d+=((int)gr[p[i]].size()-1)*(nsz-1);
    }
    if(d>g*3)cout<<'D';
    else if(d<g*3)cout<<'G';
    else cout<<"DUDUDUNGA";
    
    return 0;
}
