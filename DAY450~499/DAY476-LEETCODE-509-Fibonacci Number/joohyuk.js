/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    const dp=new Array(30+1).fill(0)
    dp[1]=1
    for(let i=2;i<30+1;++i)dp[i]=dp[i-2]+dp[i-1]
    return dp[n]
};
