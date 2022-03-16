#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=1e4+1;
int n,a,b,dp[sz][2],p[sz],w[sz];
vector<int>g[sz],c[sz];

int solve(int curr,int st,int pa){
    if(dp[curr][st])return dp[curr][st];
    if(st)dp[curr][st]+=w[curr];
    if(st){
        for(int nx:g[curr])if(nx!=pa)dp[curr][st]+=solve(nx,0,curr);
    }else for(int nx:g[curr])if(nx!=pa)dp[curr][st]+=max(solve(nx,0,curr),solve(nx,1,curr));
    return dp[curr][st];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    cout<<max(solve(1,1,0),solve(1,0,0));
    return 0;
}
