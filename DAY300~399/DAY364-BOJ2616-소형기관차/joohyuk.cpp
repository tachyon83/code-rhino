#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;

const int sz=5e4+1;
int dp[sz],acc[sz],arr[sz],n,k,dp2[sz];

int solve2(int idx){
    if(dp2[idx]!=-1)return dp2[idx];
    int &ret=dp2[idx];
    for(int i=idx;i<=n-k;++i)ret=max(ret,acc[i]-acc[i+k]);
    return ret;
}

int solve(int idx){
    if(dp[idx]!=-1)return dp[idx];
    int &ret=dp[idx];
    for(int i=idx;i<=n-2*k;++i)ret=max(ret,acc[i]-acc[i+k]+solve2(i+k));
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    fill(dp,dp+n+1,-1);
    fill(dp2,dp2+n+1,-1);
    for(int i=0;i<n;++i)cin>>arr[i];
    cin>>k;

    for(int i=0;i<n;++i)acc[i]=0;
    acc[n-1]=arr[n-1];
    for(int i=n-1-1;i>=0;--i)acc[i]=acc[i+1]+arr[i];

    int mx=0;
    for(int i=0;i<=n-3*k;++i)mx=max(mx,acc[i]-acc[i+k]+solve(i+k));
    cout<<mx;
    return 0;
}
