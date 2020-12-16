#include <iostream>
#define endl '\n'
using namespace std;
const int sz=1e4+1;
int s,dp[sz][3+1],t,v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    dp[1][1]=1;dp[2][1]=1;dp[2][2]=1;
    dp[3][1]=1;dp[3][2]=1;dp[3][3]=1;
    for(int i=4;i<sz;++i){
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-2][2]+dp[i-2][1];
        dp[i][3]=dp[i-3][3]+dp[i-3][2]+dp[i-3][1];
    }
    cin>>t;
    while(t--){
        s=0;
        cin>>v;
        for(int i=1;i<=3;++i)s+=dp[v][i];
        cout<<s<<endl;
    }
    return 0;
}
