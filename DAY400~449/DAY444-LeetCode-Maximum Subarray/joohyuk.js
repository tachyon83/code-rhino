/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let mx=nums[0]
    for(let i=0;i<nums.length-1;++i){
        nums[i+1]=Math.max(nums[i+1],nums[i]+nums[i+1])
        mx=Math.max(mx,nums[i+1])
    }
    return mx
};
