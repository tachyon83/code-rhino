#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int f=1024-1,sz=100,mod=1e9;
int odp[10][f+1],ndp[10][f+1],n,ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=9;++i)odp[i][1<<i]=1;
    for(int k=0;k<n-1;++k){
        for(int i=0;i<=9;++i){
            for(int j=0;j<=f;++j){
                if(!i)ndp[i+1][j|(1<<(i+1))]=(ndp[i+1][j|(1<<(i+1))]+odp[i][j])%mod;
                else if(i==9)ndp[i-1][j|(1<<(i-1))]=(ndp[i-1][j|(1<<(i-1))]+odp[i][j])%mod;
                else{
                    ndp[i+1][j|(1<<(i+1))]=(ndp[i+1][j|(1<<(i+1))]+odp[i][j])%mod;
                    ndp[i-1][j|(1<<(i-1))]=(ndp[i-1][j|(1<<(i-1))]+odp[i][j])%mod;
                }
            }
        }
        for(int i=0;i<=9;++i){
            for(int j=0;j<=f;++j){
                odp[i][j]=ndp[i][j];
                ndp[i][j]=0;
            }
        }
    }
    for(int i=0;i<=9;++i)ans=(ans+odp[i][f])%mod;
    cout<<ans;
    return 0;
}
