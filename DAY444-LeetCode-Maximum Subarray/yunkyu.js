/**
 * @param {number[]} nums
 * @return {number}
 */
const maxSubArray = function(nums) {
    const dp = new Array(nums.length); // dp[i] => nums[i]값을 마지막으로 하는 부분배열 합의 최댓값
    dp[0] = nums[0];
    let ret = dp[0];
    for(let i = 0; i < nums.length - 1; i++){
        dp[i + 1] = Math.max(dp[i] + nums[i + 1], nums[i + 1]); // 현재 값 vs 이전 값까지의 부분 배열의 최댓값 + 현재 값
        ret = Math.max(ret,dp[i + 1]);
    }
    return ret;
};
