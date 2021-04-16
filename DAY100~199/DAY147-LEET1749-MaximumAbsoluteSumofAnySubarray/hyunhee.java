class Solution {
    
    public int maxAbsoluteSum(int[] nums) {
        int sum = 0;
        int maxSum = -1;
        int minSum = 1;
        for(int i=0;i<nums.length;i++){
            sum = sum + nums[i] < 0 ? 0 : sum + nums[i];
            maxSum = Math.max(sum, maxSum);
        }
        sum = 0;
        for(int i=0;i<nums.length;i++){
            sum = sum + nums[i] > 0 ? 0 : sum + nums[i];
            minSum = Math.min(sum, minSum);
        }
        
        return Math.max(maxSum, -minSum);
        
    }
    
}