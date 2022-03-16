/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    const dp=[]
    for(let i=0;i<=n;++i)dp.push(0)
    dp[0]=1
    for(let i=0;i<=n;++i){
        if(i+1<=n)dp[i+1]+=dp[i]
        if(i+2<=n)dp[i+2]+=dp[i]
    }
    return dp[n]
};
