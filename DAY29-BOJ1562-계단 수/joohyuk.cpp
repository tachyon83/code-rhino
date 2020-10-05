#include <iostream>
#define endl '\n'
using namespace std;
const int mod=1e9;
const int v=1023;
int n,ans,num;
int memo[101][10][1<<10];
int counter(int i,int m,int k){
    if(memo[i][m][k])return memo[i][m][k];
    if(i==n && k==v) return 1;
    else if(i==n && k!=v)return 0;
    if(m==0)memo[i][m][k]=counter(i+1,1,k|(1<<1));
    else if(m==9)memo[i][m][k]=counter(i+1,8,k|(1<<8));
    else{
        memo[i][m][k]=(counter(i+1,m-1,k|(1<<(m-1)))+counter(i+1,m+1,k|(1<<(m+1))))%mod;
    }
    return memo[i][m][k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int k=1;k<10;++k)ans=(ans+counter(1,k,1<<k))%mod;
    cout<<ans<<endl;
    return 0;
}
