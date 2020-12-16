#include <iostream>

class Solution {
private:
    int cnt=0;
    int dp[101][101];
    int row;
    int col;
    int dr[2]={0,1};
    int dc[2]={1,0};
public:
    Solution(){
        for(int i=0;i<101;++i)fill(dp[i],dp[i]+101,0);
    }
    void solve(int num){
        int r=num/col;
        int c=num%col;
        for(int i=0;i<2;++i){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(0<=nr&&nr<row&&0<=nc&&nc<col)dp[nr][nc]+=dp[r][c];
        }
    }
    int uniquePaths(int m, int n) {
        dp[0][0]=1;
        row=m;col=n;
        int num=m*n;
        for(int i=0;i<num;++i)solve(i);
        return dp[m-1][n-1];
    }
};
