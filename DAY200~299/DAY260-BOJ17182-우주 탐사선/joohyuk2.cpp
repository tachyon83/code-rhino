#include <iostream>
#define endl '\n'
using namespace std;

const int big=2e4;
int dp[1<<10][10],n,k,cost[10][10],to[10][10],complete,mn=big;

void fw(){
    for(int k=0;k<n;++k){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;++j){
                if(i==j||j==k||k==i)continue;
                if(cost[i][j]>cost[i][k]+cost[k][j]){
                    cost[i][j]=cost[i][k]+cost[k][j];
                    to[i][j]=to[i][k];
                }
            }
        }
    }
}
void tsp(int mask,int s){
    if(mask==complete)return;
    for(int i=0;i<n;++i){
        if(i==s)continue;
        int nmask=mask|(1<<i);
        int temp_s=s;
        while(to[temp_s][i]!=i){
            nmask|=(1<<to[temp_s][i]);
            temp_s=to[temp_s][i];
        }
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
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>cost[i][j];
            to[i][j]=j;
        }
    }
    fw();
    dp[1<<k][k]=0;
    tsp(1<<k,k);
    for(int i=0;i<n;++i)mn=min(mn,dp[complete][i]);
    cout<<mn;
    return 0;
}
