#include <iostream>
#define endl '\n'
using namespace std;

const int sz=500+1,big=2e9;
int t,k,dp[sz][sz],v[sz],acc[sz];

void reset(int a){
    for(int i=0;i<=a;++i){
        for(int j=0;j<=a;++j){
            dp[i][j]=0;
        }
    }
}

int solve(int s,int e){
    if(s==e)return 0;
    if(dp[s][e])return dp[s][e];
    int&ret=dp[s][e];
    ret=big;

    for(int i=s;i<e;++i)ret=min(ret,solve(s,i)+solve(i+1,e)+acc[s]-acc[e+1]);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>k;
        for(int i=0;i<k;++i)cin>>v[i];
        reset(k);
        for(int i=k-1;i>=0;--i)acc[i]=acc[i+1]+v[i];
        cout<<solve(0,k-1)<<endl;
    }
    return 0;
}
