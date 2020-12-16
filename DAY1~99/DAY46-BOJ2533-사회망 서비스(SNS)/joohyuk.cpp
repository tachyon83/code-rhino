#include <iostream>
#include <cstring>
#include <vector>
#define endl '\n'
using namespace std;
const int sz=1e6+1;
int adapters[sz][2],n,a,b;
vector<int>graph[sz];
bool visited[sz];

int solve(int node,int adapter){
    int s=0;
    int& ret=adapters[node][adapter];
    if(ret!=-1)return ret;
    visited[node]=1;
    if(!adapter){
        for(auto nx:graph[node])if(!visited[nx])s+=solve(nx,1);
        ret=s;
    }else{
        for(auto nx:graph[node])if(!visited[nx])s+=min(solve(nx,1),solve(nx,0));
        ret=1+s;
    }
    visited[node]=0;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=1;i<n;++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(adapters,-1,sizeof(adapters));
    cout<<min(solve(1,0),solve(1,1))<<endl;
    return 0;
}
