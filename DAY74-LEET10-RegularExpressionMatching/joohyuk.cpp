
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        bool dp[21][31] = {0,};
        dp[0][0]=1;
        
        for (int j=2;j<=m;j+=2){
            if (p[j-1] == '*') dp[0][j] = 1;
            else break;
        }
        
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (j<m && p[j] == '*') continue;
                
                char cs = s[i-1];
                char cp = p[j-1];
                if(cp == '.')dp[i][j] |= dp[i-1][j-1];
                else if (cp == '*'){
                    dp[i][j] |= dp[i][j-2];
                    for (int k=i;k>=1;k--){
                        if (s[k-1] == p[j-2] || p[j-2] == '.')dp[i][j] |= dp[k-1][j-2];
                        else break;
                    }
                }else if (cs == cp) dp[i][j] |= dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};
