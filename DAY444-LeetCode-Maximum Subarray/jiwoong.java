class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        for(int i=1;i<nums.length;i++){
            nums[i] = Math.max(nums[i],nums[i-1]+nums[i]);
            sum = Math.max(sum,nums[i]);
        }
        return sum;
    }
}