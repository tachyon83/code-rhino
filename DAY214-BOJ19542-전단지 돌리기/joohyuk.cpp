#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=1e5+1;
int dist[sz],cost[sz],n,s,d,a,b;
bool vis[sz];
vector<int> g[sz];

void process(int curr){
    vis[curr]=1;
    int temp=0;
    for(int& nx:g[curr]){
        if(!vis[nx]){
            process(nx);
            if(dist[nx]+1>d)cost[curr]+=cost[nx]+2;
            dist[curr]=max(dist[curr],1+dist[nx]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>s>>d;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    process(s);
    cout<<cost[s];
    return 0;
}
