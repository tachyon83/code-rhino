/**
 * @param {number} n
 * @return {number}
 */
const fib = function(n) {
    const dp = new Array(n + 1).fill(0); 
    dp[1] = 1, dp[2] = 1;
    // dp 사용
    for(let i = 3; i <= n; i++){ 
        dp[i] = dp[i-1] + dp[i-2]; // i 번째 값은 i - 1번째 + i - 2번째
    }
    
    return dp[n];
};
