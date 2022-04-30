/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    const top=cost.length
    const dp=new Array(top+1).fill(999*1000)
    dp[0]=0
    
    for(let i=0;i<top;++i){
        dp[i+1]=Math.min(dp[i+1],cost[i]+dp[i])
        if((i+2)<cost.length+1)dp[i+2]=Math.min(dp[i+2],cost[i]+dp[i])
    }
    
    dp[1]=0
    for(let i=1;i<top;++i){
        dp[i+1]=Math.min(dp[i+1],cost[i]+dp[i])
        if((i+2)<cost.length+1)dp[i+2]=Math.min(dp[i+2],cost[i]+dp[i])
    }
    return dp[top]
};
