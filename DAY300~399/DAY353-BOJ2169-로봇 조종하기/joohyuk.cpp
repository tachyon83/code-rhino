#include <iostream>
#define endl '\n'
using namespace std;

const int sz=1e3,sm=-1e8-1;
int dp[sz][sz][3],n,m,board[sz][sz];
const int dr[3]={1,0,0},dc[3]={0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            dp[i][j][0]=sm;
            dp[i][j][1]=sm;
            dp[i][j][2]=sm;
        }
    }

    dp[0][0][1]=board[0][0];
    for(int j=0;j<m-1;++j)dp[0][j+1][1]=dp[0][j][1]+board[0][j+1];
    for(int i=1;i<n;++i){
        for(int j=0;j<m;++j)dp[i][j][0]=max(dp[i-1][j][0],max(dp[i-1][j][1],dp[i-1][j][2]))+board[i][j];
        for(int j=0;j<m-1;++j)dp[i][j+1][1]=max(dp[i][j][0],dp[i][j][1])+board[i][j+1];
        for(int j=m-1;j>0;--j)dp[i][j-1][2]=max(dp[i][j][0],dp[i][j][2])+board[i][j-1];
    }
    cout<<max(dp[n-1][m-1][0],dp[n-1][m-1][1]);
    return 0;
}
