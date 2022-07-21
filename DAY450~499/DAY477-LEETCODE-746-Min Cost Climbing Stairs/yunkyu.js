/**
 * @param {number[]} cost
 * @return {number}
 */
const minCostClimbingStairs = function(cost) {
    const n = cost.length;
    const dp = new Array(n).fill(0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(let i = 2; i < n; i++){ 
        // 두 계단 올라온 cost vs 한 계단 올라온 cost 중 작은것을 취함.
        dp[i] = cost[i] + Math.min(dp[i - 2], dp[i - 1]);
    }
    
    // 정점까지 두 계단 vs 한 계단 올라온 것 중 작은 것
    return dp[n - 2] < dp[n - 1] ? dp[n - 2] : dp[n - 1];
};
