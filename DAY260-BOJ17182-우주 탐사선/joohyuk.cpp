#include <iostream>
#define endl '\n'
using namespace std;

const int big=2e4;
int dp[1<<10][10],n,k,cost[10][10],complete,mn=big;

void tsp(int mask,int s){
    if(mask==complete)return;
    for(int i=0;i<n;++i){
        if(i==s)continue;
        int nmask=mask|(1<<i);
        if(dp[mask][s]+cost[s][i]<dp[nmask][i]){
            dp[nmask][i]=dp[mask][s]+cost[s][i];
            tsp(nmask,i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>k;
    complete=(1<<n)-1;
    for(int i=0;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            dp[j][i]=big;
        }
    }
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>cost[i][j];
    dp[1<<k][k]=0;
    tsp(1<<k,k);
    for(int i=0;i<n;++i)mn=min(mn,dp[complete][i]);
    cout<<mn;
    return 0;
}
