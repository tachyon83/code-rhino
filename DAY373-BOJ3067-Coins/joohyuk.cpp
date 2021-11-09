#include <iostream>
#define endl '\n'
using namespace std;

int dp[10000+1],coins[20],n,t,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)cin>>coins[i];
        cin>>m;
        fill(dp,dp+m+1,0);
        dp[0]=1;

        for(int i=0;i<n;++i){
            for(int j=1;j<=m;++j){
                if(j-coins[i]>=0){
                    if(!i)dp[j]=dp[j-coins[i]];
                    else dp[j]+=dp[j-coins[i]];
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}
