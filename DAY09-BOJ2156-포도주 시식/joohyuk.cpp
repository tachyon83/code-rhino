#include <iostream>
#define endl '\n'
using namespace std;
const int sz=1e4,restriction=3;
int j,mx,m,drink[sz],dp[sz][restriction];

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>m;
    while(m--)cin>>drink[j++];
    dp[0][1]=drink[0];
    for(int i=0;i<j-1;++i){
        dp[i+1][0]=max(dp[i][0],max(dp[i][1],dp[i][2]));
        dp[i+1][1]=dp[i][0]+drink[i+1];
        dp[i+1][2]=dp[i][1]+drink[i+1];
    }
    for(int i=0;i<restriction;++i)mx=max(mx,dp[j-1][i]);
    cout<<mx<<endl;
    return 0;
}
